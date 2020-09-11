using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    public Rigidbody rb;

    public float acceleration = 0.1f;
    public float moveSpeed = 1f;
    public float turnSpeed = 2f;

    public float speed;
    private Vector3 lastposition;

    private void FixedUpdate()
    {

    }

    void Update()
    {
        float horizontal = Input.GetAxisRaw("Horizontal");
        float vertical = Input.GetAxisRaw("Vertical");

        if (vertical == 0f) { acceleration = Mathf.SmoothStep(acceleration, 0f, .1f); }
        else { acceleration = Mathf.SmoothStep(acceleration, 1f, .03f); }
        

        if (acceleration > .1f)
        {
            transform.Rotate(Vector3.up * Time.deltaTime, horizontal / acceleration);
        }

        transform.Translate((Vector3.forward * Time.deltaTime * moveSpeed * vertical) * acceleration);
    }


}
