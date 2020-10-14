using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class PauseBehavior : MonoBehaviour
{
    public float rotateSpeed = 0.6f;
    public Image fader;
    public Canvas pauseMenu;
    bool controller = false;
    bool pause = false;
    bool next = true;
    int buttonSelected = 0;

    public RawImage Arrow;
    private int pauseLength = 0;
    private List<GameObject> pauseButtons = new List<GameObject>();
    public GameObject pauseObject;

    // Start is called before the first frame update
    void Start()
    {
        pauseLength = pauseObject.transform.childCount;
        pauseMenu.enabled = false;
        for (int i = 0; i < pauseLength; i++)
        {
            if (pauseObject.transform.GetChild(i).tag == "Button")
            {
                pauseButtons.Add(pauseObject.transform.GetChild(i).gameObject);
            }
        }
        pauseLength = pauseButtons.Count;
        Arrow.enabled = false;
    }

    // Update is called once per frame
    void Update()
    {
        #region MENU CONTROLLER SUPPORT
        if ((Input.GetButtonDown("Jump") || Input.GetKeyDown(KeyCode.Space)) && controller && pause)
        {
            SelectButton();
        }
        else if (Input.GetAxis("Vertical") == 0) { next = true; }

        if (Input.GetAxis("Vertical") > 0 && controller && next && pause)
        {
            if (buttonSelected <= 0) { buttonSelected = pauseLength - 1; }
            else if (buttonSelected > 0) { buttonSelected--; }
            next = false;
        }
        else if (Input.GetAxis("Vertical") < 0 && controller && next && pause)
        {
            if (buttonSelected >= pauseLength - 1) { buttonSelected = 0; }
            else if (buttonSelected < pauseLength - 1) { buttonSelected++; }
            next = false;
        }

        if (Input.GetAxis("Vertical") != 0 && pause)
        {
            Arrow.enabled = true;
            controller = true;
        }

        Vector2 pos = Arrow.transform.position;
        switch (buttonSelected)
        {
            case 0:
                Arrow.transform.position = new Vector2(pos.x, pauseButtons[0].transform.position.y); 
                break;
            case 1:
               Arrow.transform.position = new Vector2(pos.x, pauseButtons[1].transform.position.y); 
                break;
            case 2:
                Arrow.transform.position = new Vector2(pos.x, pauseButtons[2].transform.position.y); 
                break;
            default:
                break;
        }
        #endregion

        if (Input.GetKeyDown(KeyCode.Escape) || Input.GetButtonDown("Pause") && !pause)
        {
            pause = true;
            Time.timeScale = 0;
            pauseMenu.enabled = true;
        }
        else if (Input.GetKeyDown(KeyCode.Escape) || Input.GetButtonDown("Pause") && pause) { pause = false; Time.timeScale = 1; pauseMenu.enabled = false; }
    }

    void SelectButton()
    {
        switch (buttonSelected)
        {
            case 0:
                Resume();
                break;
            case 1:
                Menu();
                break;
            case 2:
                QuitGame();
                break;
        }
    }

    public void Resume() { pause = false; Time.timeScale = 1; pauseMenu.enabled = false; }

    public void Menu() { Time.timeScale = 1; fader.CrossFadeAlpha(1, 2, false); Invoke("menuScene", 2); Resume(); }
    void menuScene() { SceneManager.LoadScene("MainMenu"); }

    public void QuitGame() { Time.timeScale = 1; fader.CrossFadeAlpha(1, 2, false); Invoke("quit", 2); Resume(); }
    void quit() { Application.Quit(); }
}