#pragma once
#include "GameObject.h"

class CWall : public CGameObject
{
public:
    CWall(float x, float y);

    void Render();
    void GetBoundingBox(float& l, float& t, float& r, float& b);

    int IsBlocking() { return 1; }
};

