using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class DeathCollider : MonoBehaviour
{
    public Image fader;
    private void OnCollisionEnter(Collision collision)
    {
        if (collision.collider.tag == "Player")
        {
            fader.CrossFadeAlpha(1, 0.05f, false);
            Invoke("Reset", 0.05f);
        }
    }

    void Reset()
    {
        Scene scene = SceneManager.GetActiveScene();
        SceneManager.LoadScene(scene.name);
    }
    
}
