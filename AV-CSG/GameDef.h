#pragma once

#define SCREEN_WIDTH        500
#define SCREEN_HEIGHT       650

///> ֡����Ϊ60������һ���ǳ���������֣��ɻ��ӵ����ٶȽ���������̶���֡��������
#define MSPERFRAME          16.666666f // 1000/60

#define ElapsedTime         0.0166666f

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
    emBulletTypeAmmoSB2,

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
    FIREALL,
    WILL,
};

//��ըЧ������
enum BlastType
{
    emBlastTypeBullet = 16,
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
    emGameStatusPause,  ///> ��ͣ
};

//����������
enum GameStagePlayType
{
    emGameStagePlayTime,
    emGameStagePlayEnemy,
    emGameStagePlayEnemyBoss,
};

//������״̬
enum GameStagePlayStatus
{
    emGameStagePlayStatusNone,
    emGameStagePlayStatusRuning
};

// ͼƬ����
enum PictureType
{
    emPicTypeBullet = 0,
    emPicTypeExplosion,
    emPicTypePlane,
};