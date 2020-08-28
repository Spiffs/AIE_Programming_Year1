using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;

public class Button : MonoBehaviour
{
    public Material material;
    public UnityEvent OnPressed;

    // Start is called before the first frame update
    void Start()
    {

    }

    void OnCollisionEnter(Collision col)
    {
        if (col.collider.tag == "Player")
        {
            GetComponent<MeshRenderer>().material = material;
            OnPressed.Invoke();
        }
    }

    // Update is called once per frame
    void Update()
    {

    }
}
