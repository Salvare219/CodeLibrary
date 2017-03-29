using UnityEngine;
using System.Collections;

public class GameController : MonoBehaviour {

	public GameObject hazerd;
	public Vector3 spawnValue;
	public int hazerdCount;
	public float spawnWait;
	public float startWait;
	public float waveWait;

	public GUIText scoreText;
	public GUIText restartText;
	public GUIText gameOverText;

	private int score;
	private bool gameOver;
	private bool restart;

	void Start()
	{
		score = 0;
		gameOver = false;
		restart = false;
		restartText.text = "";
		gameOverText.text = "";
		updateScore ();
		StartCoroutine (SpawnWaves ());
	}

	void Update()
	{
		if (restart) 
		{
			if (Input.GetKeyDown (KeyCode.R)) 
			{
				Application.LoadLevel (Application.loadedLevel);
			}
				
		}
	}

	IEnumerator SpawnWaves()
	{
		yield return new WaitForSeconds (startWait);
		while (true)
		{
			for (int i = 0; i < hazerdCount; i++) 
			{
				Vector3 spawnPosition = new Vector3 (Random.Range (-spawnValue.x, spawnValue.x), spawnValue.y, spawnValue.z);
				Quaternion spawnRotation = Quaternion.identity;
				Instantiate (hazerd, spawnPosition, spawnRotation);
				yield return new WaitForSeconds (spawnWait);
			}
			yield return new WaitForSeconds (waveWait);
			if (gameOver) 
			{
				restartText.text = "Press 'R' for restart the game";
				restart = true;
				break;
			}
		}
	}

	public void AddScore(int newScore)
	{
		score += newScore;
		updateScore ();
	}

	void updateScore()
	{
		scoreText.text = "Score : " + score;
	}

	public void GameOver()
	{
		gameOverText.text = "Game Over";
		gameOver = true;
	}

}
