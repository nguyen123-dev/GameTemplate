
#include "GameObject.h"
#define TANK_STATE_UP       100
#define TANK_STATE_DOWN     200
#define TANK_STATE_LEFT     300
#define TANK_STATE_RIGHT    400

class CTank : public CGameObject
{
protected:
	int direction;
	float speed;
	bool shot;
public:
	CTank(float x, float y);
	void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	void Render();
	void GetBoundingBox(float& l, float& t, float& r, float& b);

	void SetState(int state);
};

void CTank::OnNoCollision(DWORD dt)
{
	x += vx * dt;
	y += vy * dt;
}

void CTank::OnCollisionWith(LPCOLLISIONEVENT e)
{
	if (!e->obj->IsBlocking())
		return;

	if (e->nx != 0)
		vx = 0;

	if (e->ny != 0)
		vy = 0;
}