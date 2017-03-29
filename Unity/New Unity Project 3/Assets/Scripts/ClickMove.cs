using UnityEngine;
using System.Collections;

public class ClickMove : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void OnMouseDown ()
	{
		transform.position += new Vector3 (-1.0f, 0.0f, -1.0f);
	}

}
