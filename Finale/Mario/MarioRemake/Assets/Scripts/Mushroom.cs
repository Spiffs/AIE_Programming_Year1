using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Mushroom : MonoBehaviour
{
    public Rigidbody2D rb;
    public float speed = 1f;

    private Vector3 curPos = Vector3.zero;
    private Vector3 lastPos = Vector3.zero;
    private Vector3 LR = Vector3.right;
    private bool spawned = false;

    // Update is called once per frame
    void FixedUpdate()
    { 
        if (spawned)
        {
            // if moving
            curPos = transform.position;
            if (curPos == lastPos)
            {
                if (LR == Vector3.right)
                {
                    LR = Vector3.left;
                }
                else
                {
                    LR = Vector3.right;
                }
            }
            lastPos = curPos;

            transform.Translate(LR * speed);
        }
    }

    IEnumerator Spawn()
    {
        Vector3 target = transform.position;
        target.y += 1;

        for (int i = 0; i < 10; i++)
        {
            transform.Translate(new Vector3(0, 0.1f));
            yield return new WaitForSecondsRealtime(0.1f);
        }
        spawned = true;
    }

    void Disable()
    {
        Destroy(gameObject);
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.transform.tag == "Player")
        {
            Disable();
        }
    }
}
