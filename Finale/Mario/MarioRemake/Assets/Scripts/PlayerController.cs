using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    #region ALL VARIABLES

    //public unity types
    public Animator mainAnim;
    public Rigidbody2D rb;
    public Transform feetPos;
    public Collider2D BigCollider;
    public Collider2D SmallCollider;
    public LayerMask whatIsGround;

    //public commons
    public float moveSpeed = 1f;
    public float jumpForce = 1f;
    public float jumpTime = 0.2f;
    public float sprintAdditionAdjustment = 1.8f;

    //privates
    private bool isGrounded = false;
    private bool isJumping = false;
    private bool jump = false;
    private bool alive = true;
    public bool bigboi = false;
    private float jumpTimerCounter = 0f;
    private float horizontalMove = 0f;
    private float sprintAddition = 1f;
    private float collisions = 0f;

    #endregion

    private void Update()
    {
        #region SPRITE FLIP

        Vector3 scaleflip = transform.localScale;

        if (Input.GetAxisRaw("Horizontal") < 0 && transform.localScale.x > 0)
        {
            scaleflip.x = transform.localScale.x * -1;
        }
        else if (Input.GetAxisRaw("Horizontal") > 0 && transform.localScale.x < 0)
        {
            scaleflip.x = transform.localScale.x * -1;
        }
        transform.localScale = scaleflip;

        if (bigboi)
        {
            BigCollider.enabled = true;
            SmallCollider.enabled = false;
        }
        else
        {
            BigCollider.enabled = false;
            SmallCollider.enabled = true;
        }

        #endregion

        #region JUMPING

        if (Input.GetKeyUp(KeyCode.W) || Input.GetKeyUp(KeyCode.UpArrow))
        {
            isJumping = false;
        }

        if ((Input.GetKeyDown(KeyCode.W) || Input.GetKeyDown(KeyCode.UpArrow)) && isGrounded && !jump)
        {
            mainAnim.SetFloat("JumpValue", 1f);
            jump = true;
        }

        #endregion

        #region MOVEMENT

        if (Input.GetKey(KeyCode.LeftShift))
        {
            sprintAddition = sprintAdditionAdjustment;
        }
        else
        {
            sprintAddition = 1f;
        }

        #endregion

        #region GAMEOVER

        if (alive == false)
        {
            rb.gameObject.SetActive(false);

        }

        #endregion
    }

    void FixedUpdate()
    {
        #region JUMPING

        #region GROUNDING

        isGrounded = Physics2D.OverlapCircle(feetPos.position, 0.25f, whatIsGround);

        if (collisions > 0)
        {
            mainAnim.SetFloat("JumpValue", 0f);
        }
        else
        {
            mainAnim.SetFloat("JumpValue", 1f);
        }

        #endregion

        if (jump)
        {
            isJumping = true;
            jumpTimerCounter = jumpTime;
            rb.velocity = Vector2.up * jumpForce;
            jump = false;
        }

        if ((Input.GetKey(KeyCode.W) || Input.GetKey(KeyCode.UpArrow)) && isJumping)
        {
            if (jumpTimerCounter > 0)
            {
                rb.velocity = Vector2.up * jumpForce;
                jumpTimerCounter -= Time.deltaTime;
            }
            else
            {
                isJumping = false;
            }
        }

        #endregion

        #region MOVEMENT

        Vector2 pos = transform.position;
        horizontalMove = Input.GetAxisRaw("Horizontal") * moveSpeed * sprintAddition;
        pos.x += horizontalMove;

        mainAnim.SetFloat("Speed", Mathf.Abs(horizontalMove));

        transform.position = pos;

        #endregion
    }

    void OnDeath()
    {

    }

    IEnumerator SmallOrBigBoi(bool smallorbig)
    {
        yield return new WaitForSecondsRealtime(0.05f);
        Time.timeScale = 0f;
        mainAnim.SetFloat("JumpValue", 0);
        mainAnim.SetFloat("Speed", 0);

        int i = 0;
        if (smallorbig)
        {
            while (i < 3)
            {
                mainAnim.SetBool("BigBoi", false);
                yield return new WaitForSecondsRealtime(0.1f);
                mainAnim.SetBool("BigBoi", true);
                yield return new WaitForSecondsRealtime(0.1f);
                i++;
            }
        }
        else
        {
            while (i < 3)
            {
                mainAnim.SetBool("BigBoi", true);
                yield return new WaitForSecondsRealtime(0.1f);
                mainAnim.SetBool("BigBoi", false);
                yield return new WaitForSecondsRealtime(0.1f);
                i++;
            }
        }
        Time.timeScale = 1f;
    }

    #region COLLISIONS

    private void OnCollisionEnter2D(Collision2D collision)
    {
        collisions++;
        if (collision.transform.tag == "DeathCollider")
        {
            alive = false;
            bigboi = false;
        }
        if (collision.transform.tag == "ItemBox")
        {
            isJumping = false;
        }
        if (collision.transform.tag == "Mushroom")
        {
            if (!bigboi)
            {
                StartCoroutine(SmallOrBigBoi(true));
            }
            else
            {

            }
        }
    }

    private void OnCollisionExit2D(Collision2D collision)
    {
        collisions--;
    }

    #endregion

}


