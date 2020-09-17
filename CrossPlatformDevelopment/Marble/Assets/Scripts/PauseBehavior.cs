using System.Collections;
using System.Collections.Generic;
using UnityEditor.Presets;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class PauseBehavior : MonoBehaviour
{
    public float rotateSpeed = 0.6f;
    public Image fader;
    public Canvas pauseMenu;
    bool pause = false;


    // Start is called before the first frame update
    void Start()
    {
        pauseMenu.enabled = false;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Escape) && !pause)
        {
            pause = true;
            Time.timeScale = 0;
            pauseMenu.enabled = true;
        }
        else if (Input.GetKeyDown(KeyCode.Escape) && pause) { pause = false; Time.timeScale = 1; pauseMenu.enabled = false; }
    }

    public void Resume() { pause = false; Time.timeScale = 1; pauseMenu.enabled = false; }
    
    public void Menu() { Time.timeScale = 1; fader.CrossFadeAlpha(1, 2, false); Invoke("menuScene", 2); Resume(); }
    void menuScene() { SceneManager.LoadScene("MainMenu"); }

    public void QuitGame() { Time.timeScale = 1; fader.CrossFadeAlpha(1, 2, false); Invoke("quit", 2); Resume(); }
    void quit() { Application.Quit(); }
}