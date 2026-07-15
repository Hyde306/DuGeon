#pragma once
#include "objBase.h"
#include "map.h"
#include "Resource.h"
#include "SpawnPoint.h"

class CSpawnEffect :public BaseVector
{
public:
	//位置,敵No,マップ,スポーン場所情報
	CSpawnEffect(Point, int, CMap*, CSpawnPoint*);

	int Action(const ObjList&, ObjList&);
	void Draw();

	int EnemyNo{ 0 };//敵種類
	int enemyID{ 0 };//管理用ID

	int timer{ 0 };

	CSpawnPoint* spawnPoint{};

	//マップ情報
	CMap* map = nullptr;
};