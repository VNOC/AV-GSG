#include "stdafx.h"
#include "EnemyGenerate.h"
#include "GameControler.h"
#include "EnemyPlane.h"

float CEnemyGenerate::m_sfLastCreateTime = 0.0;
int CEnemyGenerate::m_snEnemyCount = 0;

CEnemyGenerate::CEnemyGenerate(void)
{
}

CEnemyGenerate::~CEnemyGenerate(void)
{
}

void CEnemyGenerate::CreateEnemy()
{
    m_sfLastCreateTime += CGameControler::GetInstance()->GetElapsedTime();
    if (m_sfLastCreateTime > 0.3f)//0.5�����һ�ܵл�
    {
        if (m_snEnemyCount < 10)
        {
            new CEnemyPlane((EnemyType)(m_snEnemyCount % 5));
        }
        m_sfLastCreateTime -= 0.5f;
    }
}
