using UnityEngine;

public class PlayerShooting : MonoBehaviour
{
    public int damagePerShot = 20;
    public float range = 100f;
	public int shotguncnt = 10;
	public float[] gunspeed;
	public float[] gunangle;
	//supergun, normalgun, shotgun, SMgun

    float timer;
	int guntype;
	float timeBetweenBullets;
    Ray shootRay;
    RaycastHit shootHit;
    int shootableMask;
    ParticleSystem gunParticles;
    LineRenderer gunLine;
    AudioSource gunAudio;
    Light gunLight;
    float effectsDisplayTime = 0.02f;


    void Awake ()
    {
        shootableMask = LayerMask.GetMask ("Shootable");
        gunParticles = GetComponent<ParticleSystem> ();
        gunLine = GetComponent <LineRenderer> ();
        gunAudio = GetComponent<AudioSource> ();
        gunLight = GetComponent<Light> ();
		ChangeGunType(1);
    }
		

    void Update ()
    {
        timer += Time.deltaTime;

		if(Input.GetKeyDown(KeyCode.End))
		{
			ChangeGunType((guntype + 1) % 4);
		}

		if(Input.GetButton ("Fire1") && timer >= timeBetweenBullets && Time.timeScale != 0)
        {
            Shoot ();
        }

        if(timer >= effectsDisplayTime)
        {
            DisableEffects ();
        }
    }

	void ChangeGunType(int type)
	{
		guntype = type;
		timeBetweenBullets = gunspeed[type];
	}

    public void DisableEffects ()
    {
        gunLine.enabled = false;
        gunLight.enabled = false;
    }

	void Bullet(float angle,int cnt)
	{
		angle *= Random.value;
		cnt *= 3;

		gunLine.enabled = true;
		gunLine.SetPosition (cnt, transform.position);

		shootRay.origin = transform.position - transform.forward * 0.5f;
		shootRay.direction = Quaternion.AngleAxis(angle, transform.up) * transform.forward;

		if(Physics.Raycast (shootRay, out shootHit, range, shootableMask))
		{
			EnemyHealth enemyHealth = shootHit.collider.GetComponent <EnemyHealth> ();
			if(enemyHealth != null)
			{
				enemyHealth.TakeDamage (damagePerShot, shootHit.point);
			}
			gunLine.SetPosition (cnt + 1, shootHit.point);
		}
		else
		{
			gunLine.SetPosition (cnt + 1, shootRay.origin + shootRay.direction * range);
		}

		gunLine.SetPosition(cnt + 2, transform.position);
	}

    void Shoot ()
    {
        timer = 0f;

        gunAudio.Play ();

        gunLight.enabled = true;

        gunParticles.Stop ();
        gunParticles.Play ();


		if(guntype <= 1)
		{
			gunLine.SetVertexCount(3);
			Bullet(gunangle[guntype], 0);
		}
		else if(guntype == 2)
		{
			gunLine.SetVertexCount(shotguncnt * 3);
			for(int i = 0; i < shotguncnt; i ++)
			{
				Bullet(gunangle[guntype], i);
			}
		}
		else if(guntype == 3)
		{
			gunLine.SetVertexCount(3);
			Bullet(gunangle[guntype], 0);
		}
    }
}
