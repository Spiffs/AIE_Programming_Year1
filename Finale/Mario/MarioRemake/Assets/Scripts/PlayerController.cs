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

    #region COLLISIONS

    private void OnCollisionEnter2D(Collision2D collision)
    {
        collisions++;
        if (collision.transform.tag == "DeathCollider")
        {
            alive = false;
        }
    }

    private void OnCollisionExit2D(Collision2D collision)
    {
        collisions--;
    }

    #endregion

}


