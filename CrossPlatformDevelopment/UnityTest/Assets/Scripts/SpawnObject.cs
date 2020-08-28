using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpawnObject : MonoBehaviour
{

    public GameObject objToSpawn;
    public float spawnInSeconds = 1.6f;
    public float spawnCoolDown = 0.0f;
    public float spawnCount = 1.0f;
    // Start is called before the first frame update
    void Start()
    {
        spawnCoolDown = spawnInSeconds;
    }

    // Update is called once per frame
    void Update()
    {
        spawnCoolDown -= Time.deltaTime;
        spawnCount -= Time.deltaTime;
        if (spawnCoolDown < 0)
        {
            spawnCoolDown = spawnInSeconds;
            var obj = GameObject.Instantiate(objToSpawn);

        }
        if (spawnCount < 0)
        {
            spawnCount = 1.0f;
            spawnInSeconds /= 1.05f;
        }
    }
}
