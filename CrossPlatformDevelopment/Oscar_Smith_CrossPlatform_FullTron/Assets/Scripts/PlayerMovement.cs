using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    public Rigidbody rb;

    public float moveSpeed = 1f;
    public float turnSpeed = 2f;
    // Update is called once per frame
    void Update()
    {
        // AddForce FORWARD
        float horizontal = Input.GetAxisRaw("Horizontal");
        float vertical = Input.GetAxisRaw("Vertical");
        
        Vector3 force = moveSpeed * vertical * transform.forward;

        if (rb.velocity.magnitude > 15)
        {
            rb.velocity = rb.velocity.normalized * 15;
        }

        rb.AddForce(force, ForceMode.Acceleration);

        if (rb.velocity.magnitude > 1)
        {
            rb.AddTorque(transform.up * turnSpeed * horizontal * (25 - rb.velocity.magnitude));
        }
    }
}
