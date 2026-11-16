#include "GameObject.h"

class CBullet : public CGameObject
{
protected:
    int direction;
    float speed;

public:
    CBullet(float x, float y, int direction);

    void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
    void Render();
    void GetBoundingBox(float& l, float& t, float& r, float& b);
};