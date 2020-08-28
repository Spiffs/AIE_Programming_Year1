using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Playerscript : MonoBehaviour
{
    public float speed = 10;
    public GameObject Panel;

    private float ScreenWidth;
    private float ScreenHeight;

    // Start is called before the first frame update
    void Start()
    {
        Panel.gameObject.SetActive(false);
        ScreenWidth = Screen.width;
        ScreenHeight = Screen.height;

    }

    // Update is called once per frame
    void Update()
    {
        Vector3 pos = transform.position;
        for (int i = 0; i < Input.touchCount; i++)
        {
            if (Input.GetTouch(i).position.x < ScreenWidth / 2)
            {
                pos.z += speed * Time.deltaTime;
            }
            if (Input.GetTouch(i).position.x > ScreenWidth / 2)
            {
                pos.z -= speed * Time.deltaTime;
            }
            if (Input.GetTouch(i).position.y > ScreenHeight - ScreenHeight / 5)
            {
                Panel.gameObject.SetActive(false);
                SceneManager.LoadScene(SceneManager.GetActiveScene().name);
                Time.timeScale = 1;
            }

            i++;
        }

        if (Input.GetKey("a"))
        {
            pos.z += speed * Time.deltaTime;
        }
        if (Input.GetKey("d"))
        {
            pos.z -= speed * Time.deltaTime;
        }
        if (Input.GetKey("r"))
        {
            Panel.gameObject.SetActive(false);
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
            Time.timeScale = 1;
        }

        transform.position = pos;

    }

    void OnCollisionEnter(Collision col)
    {
        if (col.gameObject.CompareTag("Enemy"))
        {
            Panel.gameObject.SetActive(true);
            Time.timeScale = 0;
        }
    }
}
