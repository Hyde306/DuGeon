#pragma once
#include "objBase.h"
#include "map.h"

class CSpawnPoint :public BaseVector
{
public:
	//位置, No, マップ
	CSpawnPoint(Point,int,CMap*);

	int Action(const ObjList&, ObjList&);
	void Draw();

	//出現する敵の種類
	int EnemyNo{ 0 };
	//出現中フラグ
	bool enemyAlive{ false };

	//マップ情報
	CMap* map = nullptr;
};