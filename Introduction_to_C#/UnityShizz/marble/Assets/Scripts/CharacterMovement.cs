using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CharacterMovement : MonoBehaviour
{
    public float speed = 5.0f;

    private Rigidbody rb;

    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update()
    {
        {
            Vector3 movement = new Vector3(0, 0, 0);
            
            if (Input.GetButton("W"))
            {
                rb.AddForce(movement * speed);
            }
            if (Input.GetButton("S"))
            {
                rb.AddForce(movement * speed);
            }
            if (Input.GetButton("A"))
            {
                rb.AddForce(movement * speed);
            }
            if (Input.GetButton("D"))
            {
                rb.AddForce(movement * speed);
            }
        }
    }
}
