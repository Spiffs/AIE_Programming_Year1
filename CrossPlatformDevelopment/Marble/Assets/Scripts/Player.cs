using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public float speed;
    public Rigidbody rb;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        Vector3 force = new Vector3( Input.GetAxis("Horizontal"), 0.0f, Input.GetAxis("Vertical") );
        rb.AddForce(force * Time.deltaTime * speed, ForceMode.Force);

    }
}
