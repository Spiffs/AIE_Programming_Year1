using UnityEngine;

public class Player : MonoBehaviour
{
    public float jumpForce = 2f;
    public float speed = 1000f;
    public float speedEnd = 10f;
    public Rigidbody rb;
    public GameObject endMoveTo;
    bool end = false;
    public int collisionCount = 0;

    private void OnCollisionEnter(Collision collision)
    {
        if (collision.collider.tag != "Wall")
        {
            collisionCount++;
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == "EndMoveTo")
        {
            Debug.Log("HIT");
            end = true;
        }
    }

    private void OnCollisionExit(Collision collision)
    {
        if (collision.collider.tag != "Wall")
        {
            collisionCount--;
        }
    }

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        if (end)
        {
            float step = speedEnd * Time.deltaTime;
            transform.position = Vector3.MoveTowards(transform.position, endMoveTo.transform.position, step);
        }
        else
        {


            Vector3 force = new Vector3(Input.GetAxis("Horizontal"), 0.0f, Input.GetAxis("Vertical"));
            rb.AddForce(force * Time.deltaTime * speed, ForceMode.Force);

            if (Input.GetButtonDown("Jump") && collisionCount > 0)
            {
                rb.AddForce(Vector3.up * jumpForce, ForceMode.Impulse);
            }
        }
    }
}
