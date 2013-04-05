#pragma once

#define Default_Life    1

class Player_GameStatus
{
public:
    Player_GameStatus();
    ~Player_GameStatus();

public:
    ///> ������ߵ÷�
    int GetMaxScore();
    bool SetMaxScore(int nMaxScore);

    ///> ʣ������
    int GetLife();
    int AddLife(int nAdd = 0);
    int SubLife(int nSub = 0);

    ///> Ѫ��
    int GetHp();
    void SetHp(int nHp);
    int AddHp(int nAdd = 1);
    int SubHp(int nSub = 1);

    ///> ��ǰ�÷�
    int GetScore();
    int AddScore(int nAdd = 0);
    int SubScore(int nSub = 0);

    ///> ������Ϸ״̬
    void ResetGameStatus();

private:
    ///> ��Ҵ�ɻ��ĵ�����ߵ÷�
    int m_nMaxScore;
    ///> ��ǰ�÷�
    int m_nScroe;
    ///> ʣ��Ѫ��
    int m_HP;
    ///> ʣ����������
    int m_nLife;
};