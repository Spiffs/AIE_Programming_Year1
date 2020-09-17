using System.Collections;
using System.Collections.Generic;
using UnityEngine;



public class Platform : MonoBehaviour
{
    private bool pause = false;
    private bool Move = false;
    int mod = -1;
    public float speed;
    private float timerpreset = 2.0f;
    private float timer = 2.0f;
    public GameObject player;
    public int collisionCount = 0;

    // Start is called before the first frame update
    void Start() { }

    public void PlatformActive()
    {
        Move = true;
    }

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.collider.tag == "Level")
        {
            timer = timerpreset;
            pause = true;
        }
        else if (collision.collider.tag == "Player")
        {
            collisionCount++;
        }
    }

    private void OnCollisionExit(Collision collision)
    {
        if (collision.collider.tag == "Player")
        {
            collisionCount--;
        }
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 move = new Vector3(1 * mod, 0, 1 * -mod);
        if (Move && !pause)
        {
            transform.position += move * speed * Time.deltaTime;
            if (collisionCount > 0)
            {
                player.transform.position += move * speed * Time.deltaTime;
            }
        }

        if (pause)
        {
            timer -= Time.deltaTime;
            if (timer < 0)
            {
                mod *= -1;
                pause = false;
                Move = true;
            }
        }

    }
}
