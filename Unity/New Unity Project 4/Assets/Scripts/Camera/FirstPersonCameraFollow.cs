using UnityEngine;
using System.Collections;

public class FirstPersonCameraFollow : MonoBehaviour {

	public Transform player;
	public float distant;
	public float hand;

	void Update () 
	{
		transform.position = player.transform.position + player.transform.forward * distant;
		transform.position = transform.position + player.transform.up * hand;
		transform.eulerAngles = player.transform.eulerAngles;
	}
}
