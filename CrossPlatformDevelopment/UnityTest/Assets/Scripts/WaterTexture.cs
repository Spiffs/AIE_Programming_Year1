using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WaterTexture : MonoBehaviour
{
    public float speedX = 0.1f;
    private float curX;

    // Use this for initialization
    void Start()
    {
        curX = GetComponent<Renderer>().material.mainTextureOffset.x;
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        curX -= Time.deltaTime * speedX;
        GetComponent<Renderer>().material.SetTextureOffset("_MainTex", new Vector2(curX, 0));
    }
}