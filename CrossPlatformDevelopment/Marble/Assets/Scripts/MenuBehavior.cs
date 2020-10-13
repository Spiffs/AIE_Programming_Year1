using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class MenuBehavior : MonoBehaviour
{
    public float rotateSpeed = 0.6f;
    public Image mainFader;
    public Image selectorFader;
    public Canvas mainActivator;
    public Canvas selectorActivator;
    bool controller = false;
    bool next = true;
    int buttonSelected = 0;

    public RawImage Arrow;
    // false = MainMenu, true = Leveleditor
    private bool menu = false;
    private int mainLength = 0;
    private int selectorLength = 0;
    private List<GameObject> mainButtons = new List<GameObject>();
    private List<GameObject> selectorButtons = new List<GameObject>();

    // Start is called before the first frame update
    void Start()
    {
        mainActivator.enabled = true;
        selectorActivator.enabled = false;
        mainFader.CrossFadeAlpha(0, 2, false);
        selectorFader.CrossFadeAlpha(0, 2, false);
        #region BUTTONGET
        mainLength = mainActivator.gameObject.transform.childCount;
        for (int i = 0; i < mainLength; i++)
        {
            if (mainActivator.gameObject.transform.GetChild(i).tag == "Button")
            {
                mainButtons.Add(mainActivator.gameObject.transform.GetChild(i).gameObject);
            }
        }
        mainLength = mainButtons.Count;

        selectorLength = selectorActivator.gameObject.transform.childCount;
        for (int i = 0; i < selectorLength; i++)
        {
            if (selectorActivator.gameObject.transform.GetChild(i).tag == "Button")
            {
                selectorButtons.Add(selectorActivator.gameObject.transform.GetChild(i).gameObject);
            }
        }
        selectorLength = selectorButtons.Count;
        Arrow.enabled = false;
        #endregion
    }

    // Update is called once per frame
    void Update()
    {
        if ((Input.GetButtonDown("Jump") || Input.GetKeyDown(KeyCode.Space)) && controller)
        {
            SelectButton();
        }

        else if (Input.GetAxis("Vertical") == 0) { next = true; }

        // controller menu selector
        if (Input.GetAxis("Vertical") > 0 && controller && next)
        {
            if (!menu)
            {
                if (buttonSelected <= 0) { buttonSelected = mainLength - 1; } 
                else if (buttonSelected > 0) { buttonSelected--; }
            }
            else
            {
                if (buttonSelected <= 0) { buttonSelected = selectorLength - 1; }
                else if (buttonSelected > 0) { buttonSelected--; }
            }
            next = false;
        }
        else if (Input.GetAxis("Vertical") < 0 && controller && next)
        {
            if (!menu)
            {
                if (buttonSelected >= mainLength - 1) { buttonSelected = 0; }
                else if (buttonSelected < mainLength - 1){ buttonSelected++; }
            }
            else
            {
                if (buttonSelected >= selectorLength - 1) { buttonSelected = 0; }
                else if (buttonSelected < selectorLength - 1) { buttonSelected++; }
            }
            next = false;
        }

        if (Input.GetAxis("Vertical") != 0)
        {
            Arrow.enabled = true;
            controller = true;
        }

        Vector2 pos = Arrow.transform.position;
        switch (buttonSelected)
        {
            case 0:
                if (!menu) { Arrow.transform.position = new Vector2(pos.x, mainButtons[0].transform.position.y); }
                else { Arrow.transform.position = new Vector2(pos.x, selectorButtons[0].transform.position.y); }
                break;
            case 1:
                if (!menu) { Arrow.transform.position = new Vector2(pos.x, mainButtons[1].transform.position.y); }
                else { Arrow.transform.position = new Vector2(pos.x, selectorButtons[1].transform.position.y); }
                break;
            case 2:
                if (!menu) { Arrow.transform.position = new Vector2(pos.x, mainButtons[2].transform.position.y); }
                else { Arrow.transform.position = new Vector2(pos.x, selectorButtons[2].transform.position.y); }
                break;
            case 3:
                Arrow.transform.position = new Vector2(pos.x, selectorButtons[3].transform.position.y);
                break;
            case 4:
                Arrow.transform.position = new Vector2(pos.x, selectorButtons[4].transform.position.y);
                break;
            default:
                break;
        }

        RenderSettings.skybox.SetFloat("_Rotation", Time.time * rotateSpeed);
    }


    void SelectButton()
    {
        switch (buttonSelected)
        {
            case 0:
                if (!menu) { PlayGame(); }
                else { Level1Button(); }
                break;
            case 1:
                if (!menu) { LevelSelect(); }
                else { Level2Button(); }
                break;
            case 2:
                if (!menu) { QuitGame(); }
                else { Level3Button(); }
                break;
            case 3:
                Level4Button();
                break;
            case 4:
                BackButton();
                break;
        }
    }

    #region MAIN MENU
    public void PlayGame()
    {
        mainFader.CrossFadeAlpha(1, 2, false);
        Invoke("pGame", 2);
    }
    void pGame() { SceneManager.LoadScene("Level1"); }

    public void LevelSelect()
    {
        buttonSelected = 0;
        menu = true;
        selectorActivator.enabled = true;
        mainActivator.enabled = false;
    }

    public void QuitGame() { Application.Quit(); }
    #endregion

    #region LEVEL SELECTOR
    public void Level1Button() { selectorFader.CrossFadeAlpha(1, 2, false); Invoke("LoadLevel1", 2); }
    void LoadLevel1() { SceneManager.LoadScene("Level1"); }
    public void Level2Button() { selectorFader.CrossFadeAlpha(1, 2, false); Invoke("LoadLevel2", 2); }
    void LoadLevel2() { SceneManager.LoadScene("Level2"); }
    public void Level3Button() { selectorFader.CrossFadeAlpha(1, 2, false); Invoke("LoadLevel3", 2); }
    void LoadLevel3() { SceneManager.LoadScene("Level3"); }
    public void Level4Button() { selectorFader.CrossFadeAlpha(1, 2, false); Invoke("LoadLevel4", 2); }
    void LoadLevel4() { SceneManager.LoadScene("Level4"); }
    public void BackButton()
    {
        buttonSelected = 0;
        menu = false;
        selectorActivator.enabled = false;
        mainActivator.enabled = true;
    }

    #endregion
}
