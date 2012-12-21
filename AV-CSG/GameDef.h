#pragma once

#define SCREEN_WIDTH        600
#define SCREEN_HEIGHT       800
#define MSPERFRAME          30

#define PI                  3.141592f

//�����ӵ�����
enum BulletType
{
    emBulletTypeAMMO0 = 0,
    emBulletTypeAMMO1,
    emBulletTypeAMMO2,
    emBulletTypeAMMO3,
    emBulletTypeAMMO4,
    emBulletTypeAMMO5,
    emBulletTypeAMMO6,
    emBulletTypeAmmoAll1,
    emBulletTypeAmmoSB,

    emBulletTypeMax
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
    emEnemyTypeENEMY0 = 0,
    emEnemyTypeENEMY1,
    emEnemyTypeENEMY2,
    emEnemyTypeENEMY3,
    emEnemyTypeENEMY4,

    emEnemyTypeMax
};

//��ըЧ������
enum BlastType
{
    emBlastTypeBullet = 0,
    emBlastTypePlane,

    emBlastTypeMax
};

//��Ϸ״̬
enum GameStatus
{
    emGameStatusNone,       ///> ʲô������
    emGameStatusReady,
    emGameStatusOver,
    emGameStatusRuning,
};

// ͼƬ����
enum PictureType
{
    emPicTypeBullet = 0,
    emPicTypeExplosion,
    emPicTypePlane,
};