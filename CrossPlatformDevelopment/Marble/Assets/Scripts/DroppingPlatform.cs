using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DroppingPlatform : MonoBehaviour
{
    private Material mDefault;
    public Material semiActive;
    public Material active;
    private bool move = false;
    public float moveSpeed = 0.05f;

    // Start is called before the first frame update
    void Start()
    {
        mDefault = gameObject.GetComponent<MeshRenderer>().material;
    }

    void OnCollisionEnter(Collision collision)
    {
        gameObject.GetComponent<MeshRenderer>().material = semiActive;
        Invoke("Active", 0.5f);
    }

    void Active()
    {
        move = true;
        gameObject.GetComponent<MeshRenderer>().material = active;
        Invoke("Delete", 3);
    }

    // Update is called once per frame
    void Update()
    {
        if (move)
        {
            transform.Translate(0, -moveSpeed, 0);
        }
    }

    void Delete() { Destroy(gameObject); }
}
