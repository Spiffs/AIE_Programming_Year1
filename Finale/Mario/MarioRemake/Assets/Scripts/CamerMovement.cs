using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CamerMovement : MonoBehaviour
{
    public Camera thisCamera;
    public GameObject target;
    public GameObject playerLeftBoundary;
    public float XnegatifveBoundary = 0f;
    public float XpositiveBoundary = 10f;
    public float YnegatifveBoundary = 0f;
    public float YpositiveBoundary = 10f;
    public float characterMoveBoarder = 0f;


    // Start is called before the first frame update
    void Start()
    {
        float height = 2f * thisCamera.orthographicSize;
        float width = height * thisCamera.aspect;

        Vector3 pos = playerLeftBoundary.transform.position;
        pos.x = (transform.position.x - width / 2) - 0.75f;
        playerLeftBoundary.transform.position = pos;
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 pos = transform.position;

        if (target.transform.position.x > transform.position.x + characterMoveBoarder)
        {
            pos.x = target.transform.position.x + -(characterMoveBoarder);
        }

        Mathf.Clamp(pos.x, XnegatifveBoundary, XpositiveBoundary);
        Mathf.Clamp(pos.y, YnegatifveBoundary, YpositiveBoundary);

        transform.position = pos;
    }
}
