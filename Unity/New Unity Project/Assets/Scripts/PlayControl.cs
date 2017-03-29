using UnityEngine;
using System.Collections;
using UnityEngine.UI;


public class PlayControl : MonoBehaviour {

    public float speed;
	public Text CountText;
	public Text WinText;

    private Rigidbody rb;
	private int count;
	private float myTime;

    private void Start()
    {
		count = 0;
        rb = GetComponent<Rigidbody>();
		SetCountText ();
		WinText.text = "";
		Time.captureFramerate = 10;
    }


	void FixedUpdate()
	{
        float moveHorizontal = Input.GetAxis("Horizontal");
        float moveVertical = Input.GetAxis("Vertical");

		float Yspeed=rb.velocity.y;

		myTime = myTime + Time.deltaTime;
		if (Input.GetButtonDown ("Fire1") && myTime > 1.0f) 
		{
			Yspeed += 10.0f;
			myTime = 0.0f;
		}

		rb.velocity = new Vector3 (rb.velocity.x, Yspeed, rb.velocity.z);

		rb.AddForce (new Vector3 (moveHorizontal * speed, 0.0f, moveVertical * speed));


	}

	void OnTriggerEnter(Collider other) 
	{
		if (other.gameObject.CompareTag ("Pick")) 
		{
			count++;
			other.gameObject.SetActive(false);
			SetCountText ();
		}
	}

	void SetCountText()
	{
		CountText.text = "Count : " + count.ToString () + ' ' + Time.captureFramerate.ToString ();
		if (count == 10) 
		{
			WinText.text = "YOU WIN";
		}
	}

}