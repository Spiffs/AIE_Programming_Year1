using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController : MonoBehaviour
{
    public GameObject target;
    public float smoothTime = 0.05f;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 v = Vector3.zero;
        transform.position = Vector3.SmoothDamp(transform.position, target.transform.position, ref v, smoothTime);
        
    }
}
