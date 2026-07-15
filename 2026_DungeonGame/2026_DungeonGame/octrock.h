//ザコ
#pragma once
#include "objBase.h"
#include "map.h"
#include "Resource.h"
#include "SpawnPoint.h"
#include "Effect.h"

class COctrock :public CCharaOBJ
{
private:
	//行動範囲
	int PATROL_RANGE = 100;
	//スポーンから離れられる距離
	int LEASH_RANGE = 250;
	//視線距離
	int FIND_RANGE = 300;
public:
	//向き
	enum DIR { DOWN, LEFT, RIGHT, UP };

	COctrock(Point, CMap*, CSpawnPoint*);

	int Action(const ObjList&, ObjList&);
	void Draw();

	Point spawnPos;//出現位置
	
	CSpawnPoint* spawn = nullptr;//出現スポーン

	CCharaOBJ* target = nullptr;//追尾するターゲット

	//向き更新
	void UpdateDir(Point);

	//SE
	int enemy_hit_SE{ -1 };
	int enemy_down_SE{ -1 };

	int oldHP{ -1 };
};