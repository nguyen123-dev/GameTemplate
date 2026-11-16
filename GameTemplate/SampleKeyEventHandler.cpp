#include "SampleKeyEventHandler.h"

#include "debug.h"
#include "Game.h"
#include "Tank.h"
#include "PlayScene.h"

void CSampleKeyHandler::OnKeyDown(int KeyCode)
{
	//DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	CMario* mario = (CMario *)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer(); 

	switch (KeyCode)
	{
	case DIK_DOWN:
		mario->SetState(MARIO_STATE_SIT);
		break;
	case DIK_S:
		mario->SetState(MARIO_STATE_JUMP);
		break;
	case DIK_1:
		mario->SetLevel(MARIO_LEVEL_SMALL);
		break;
	case DIK_2:
		mario->SetLevel(MARIO_LEVEL_BIG);
		break;
	case DIK_0:
		mario->SetState(MARIO_STATE_DIE);
		break;
	case DIK_R: // reset
		//Reload();
		break;
	}
}

void CSampleKeyHandler::OnKeyUp(int KeyCode)
{
	//DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);

	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	switch (KeyCode)
	{
	case DIK_S:
		mario->SetState(MARIO_STATE_RELEASE_JUMP);
		break;
	case DIK_DOWN:
		mario->SetState(MARIO_STATE_SIT_RELEASE);
		break;
	}
}

void CTankKeyEventHandler::KeyState(BYTE* states)
{
    CGame* game = CGame::GetInstance();

    CTank* tank =
        ((CPlayScene*)game->GetCurrentScene())->GetPlayer();

    if (game->IsKeyDown(DIK_W))
        tank->SetState(TANK_STATE_UP);

    else if (game->IsKeyDown(DIK_S))
        tank->SetState(TANK_STATE_DOWN);

    else if (game->IsKeyDown(DIK_A))
        tank->SetState(TANK_STATE_LEFT);

    else if (game->IsKeyDown(DIK_D))
        tank->SetState(TANK_STATE_RIGHT);

    else
    {
        // Dừng di chuyển nhưng giữ nguyên hướng nhìn.
        tank->SetSpeed(0, 0);
    }
}