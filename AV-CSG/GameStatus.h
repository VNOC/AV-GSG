#pragma once

///> ��Ϸ״̬����
class CGameStatus
{
public:
    CGameStatus(void);
    ~CGameStatus(void);

    static bool GetGameOver();
    static bool GetGameReady();
    static bool GetGameRuning();
    static bool GetGamePause();

    static void ClearGameStatus();
    static bool IsNeedUpdate();
    static void StartGame();
    static void SetGameOver();
    static void PauseGame();

private:
    static GameStatus           m_emGameStatus;
};
