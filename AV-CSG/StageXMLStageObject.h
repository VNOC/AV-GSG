#ifndef STAGE_OBJECT
#define STAGE_OBJECT

#include "StageXMLObject.h"
#include "StageXMLEnemyOBject.h"
#include "StageXMLItemOBject.h"

typedef std::map<std::string, CStageXMLItem*> ItemObejctMap;
typedef std::map<std::string, CStageXMLEnemy*> EnemyObejctMap;

class CStageXMLStage : public CStageXMLOBject
{
public:
    CStageXMLStage();
    virtual ~CStageXMLStage();

    bool PushEnemy(CStageXMLEnemy* sItemObject);
    const EnemyObejctMap::const_iterator EnemyBegin() const;
    const EnemyObejctMap::const_iterator EnemyEnd() const;

    bool PushItem(CStageXMLItem* sItemObject);
    const ItemObejctMap::const_iterator ItemBegin() const;
    const ItemObejctMap::const_iterator ItemEnd() const;

    void SetMap(const std::string& strMap);
    const std::string& GetMap() const;

    void SetDifficulty(long lnMap);
    const long GetDifficulty() const;

    bool SetItem(const std::string& strId,CStageXMLItem* sItemObject);
    CStageXMLItem* GetItem(const std::string& strId) const;

private:

    void _Close();

    int m_Boss;
    long m_Difficulty;
    std::string m_MapPath;
    ItemObejctMap m_mapItem;
    EnemyObejctMap m_mapEnemy;
};

#endif