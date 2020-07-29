using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraActor : MonoBehaviour
{
    public Transform target;

    private Vector3 boom;

    // Start is called before the first frame update
    void Start()
    {
        boom = this.transform.position - target.position;
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 target_pos = target.position + boom;
        this.transform.position = target_pos;
    }
}
