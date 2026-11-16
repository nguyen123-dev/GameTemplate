#include "Tank.h"
#include "AssetIDs.h"

CTank::CTank(float x, float y) : CGameObject(x, y)
{
    direction = TANK_STATE_UP;
    shot = true;
    speed = 0.1f;

    vx = 0;
    vy = 0;

    SetState(TANK_STATE_UP);
}

void CTank::SetState(int state)
{
    vx = 0;
    vy = 0;

    switch (state)
    {
    case TANK_STATE_UP:
        vy = -speed;
        direction = TANK_STATE_UP;
        break;

    case TANK_STATE_DOWN:
        vy = speed;
        direction = TANK_STATE_DOWN;
        break;

    case TANK_STATE_LEFT:
        vx = -speed;
        direction = TANK_STATE_LEFT;
        break;

    case TANK_STATE_RIGHT:
        vx = speed;
        direction = TANK_STATE_RIGHT;
        break;
    }
}

void CTank::GetBoundingBox(
    float& l,
    float& t,
    float& r,
    float& b
)
{
    l = x - TANK_BBOX_WIDTH / 2;
    t = y - TANK_BBOX_HEIGHT / 2;

    r = l + TANK_BBOX_WIDTH;
    b = t + TANK_BBOX_HEIGHT;
}

void CTank::Render()
{
    int spriteID = ID_SPRITE_TANK_UP;

    switch (direction)
    {
    case TANK_STATE_UP:
        spriteID = ID_SPRITE_TANK_UP;
        break;

    case TANK_STATE_DOWN:
        spriteID = ID_SPRITE_TANK_DOWN;
        break;

    case TANK_STATE_LEFT:
        spriteID = ID_SPRITE_TANK_LEFT;
        break;

    case TANK_STATE_RIGHT:
        spriteID = ID_SPRITE_TANK_RIGHT;
        break;
    }

    CSprites::GetInstance()->Get(spriteID)->Draw(x, y);
}

void CTank::Update(
    DWORD dt,
    vector<LPGAMEOBJECT>* coObjects
)
{
    CCollision::GetInstance()->Process(
        this,
        dt,
        coObjects
    );
}