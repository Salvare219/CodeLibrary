using UnityEngine;
using System.Collections;


public class FirstPersonCamera : MonoBehaviour {

	public GameObject player;
	public Vector3 offset;

	private Camera cam;

	void Start () {
		offset = transform.position - player.transform.position;
		cam = GetComponent<Camera> ();
	}
	
	// Update is called once per frame
	void Update () {
		transform.position = offset + player.transform.position;

		if (Input.GetKeyDown (KeyCode.Q)) {
			cam.depth = -cam.depth;
		}

	}
}
