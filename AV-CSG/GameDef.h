#pragma once

#define SCREEN_WIDTH        600
#define SCREEN_HEIGHT       800
#define MSPERFRAME          30

#define PI                  3.141592f

//�����ӵ�����
enum BulletType
{
    AMMO0 = 0,
    AMMO1,
    AMMO2,
    AMMO3,
    AMMO4,
    AMMO5,
    AMMO6,
    WHOLEFRIED
};

//���嶯������
enum ActionType
{
    LEFT,
    DOWN,
    RIGHT,
    UP,
    LEFT_UP,
    LEFT_DOWN,
    RIGHT_UP,
    RIGHT_DOWN,
    STOP_MOVE,
    FIRE,
    STOP_FIRE,
    FIREALL
};

//�л�����
enum EnemyType
{
    ENEMY0 = 0,
    ENEMY1,
    ENEMY2,
    ENEMY3,
    ENEMY4
};

//��ըЧ������
enum BlastType
{
    BULLETBLAST = 0,
    PLANEBLAST
};

//��Ϸ״̬
enum GameStatus
{
    emGameStatusNone,       ///> ʲô������
    emGameStatusReady,
    emGameStatusOver,
    emGameStatusPlaying,
};