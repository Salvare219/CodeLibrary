using UnityEngine;
using System.Collections;

public class DestoryContact : MonoBehaviour {

	public GameObject explosion;
	public GameObject playerexplosion;
	public int scoreValue;

	public GameController gameController;

	void Start ()
	{
		GameObject gameControllerObject = GameObject.FindWithTag ("GameController");
		if (gameControllerObject != null)
		{
			gameController = gameControllerObject.GetComponent<GameController> ();
		}
		if (gameController == null) 
		{
			Debug.Log ("GameController can't be find!!");
		}
	}

	void OnTriggerEnter (Collider other) 
	{
		if (other.tag != "Boundary") 
		{
			Instantiate (explosion, transform.position, transform.rotation);
			if (other.tag == "Player") 
			{
				Instantiate (playerexplosion, other.transform.position, other.transform.rotation);
				gameController.GameOver ();
			}
			gameController.AddScore (scoreValue);
			Destroy (gameObject);
			Destroy (other.gameObject);
		}
	}
}
