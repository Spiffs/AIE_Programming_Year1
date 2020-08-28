using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoxEnemy : MonoBehaviour
{
    private float Maxx = 4.20f;
    private float Minx = -13.75f;
    public float speed = 20;
    private float speeduptime = 1;

    void OnCollisionEnter(Collision col)
    {
        if (col.gameObject.CompareTag("Collide"))
        {
            Destroy(gameObject);
        }
    }

    // Start is called before the first frame update
    void Start()
    {
        Vector3 pos = transform.position;
        pos = new Vector3(98, 4.5f, Random.Range(Minx, Maxx));
        transform.position = pos;
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 pos = transform.position;
        pos.x -= speed * Time.deltaTime;
        transform.position = pos;

        speeduptime -= Time.deltaTime;
        if (speeduptime < 0)
        {
            speeduptime = 1;
            speed += 1f;
        }
    }
}
