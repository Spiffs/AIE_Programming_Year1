using System.Collections;
using System.Collections.Generic;
using UnityEditor.Presets;
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


    // Start is called before the first frame update
    void Start()
    {
        mainActivator.enabled = true;
        selectorActivator.enabled = false;
        mainFader.CrossFadeAlpha(0, 2, false);
        selectorFader.CrossFadeAlpha(0, 2, false);
    }

    // Update is called once per frame
    void Update()
    {
        RenderSettings.skybox.SetFloat("_Rotation", Time.time * rotateSpeed);
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
        selectorActivator.enabled = false;
        mainActivator.enabled = true;
    }

    #endregion
}
