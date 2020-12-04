using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoxScript : MonoBehaviour
{
    public Animator MainAnim;
    public GameObject Mushroom; 
    // Box case, 0 = default box, 1 = question box
    public int boxCase = 0;

    private int collisions;
    private bool triggeredQuestionBox = false;

    // Update is called once per frame
    void Update()
    {
        if (boxCase == 1)
        {
            if (collisions > 0 && !triggeredQuestionBox)
            {
                triggeredQuestionBox = true;
                StartCoroutine(QuestionBoxActivated());
            }
        }
    }

    IEnumerator QuestionBoxActivated()
    {
        float upTimer = 0f;
        float downTimer = 0f;

        while (upTimer <= 0.08f)
        {
            transform.Translate(Vector3.up * 0.05f);
            upTimer += Time.deltaTime;
            yield return null;
        }

        while (downTimer <= 0.08f)
        {
            transform.Translate(Vector3.down * 0.05f);
            downTimer += Time.deltaTime;
            yield return null;
        }
        upTimer = 0f;
        downTimer = 0f;

        Vector3 pos = transform.position;
        pos.y += 0.1f;
        Instantiate(Mushroom, pos, transform.rotation);

        MainAnim.SetBool("UsedBox", true);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Player")
        {
            collisions++;
        }
        if (collision.gameObject.tag == "ItemBox")
        {
            collisions++;
        }
    }

    private void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.gameObject.tag == "Player")
        {
            collisions--;
        }
        if (collision.gameObject.tag == "ItemBox")
        {
            collisions--;
        }
    }
}
