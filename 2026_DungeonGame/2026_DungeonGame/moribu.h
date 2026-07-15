//中ボス
#pragma once
#include "objBase.h"
#include "map.h"
#include "Resource.h"
#include "SpawnPoint.h"
#include "Effect.h"
#include "bow.h"

class CMoribu :public CCharaOBJ
{
private:
	//行動範囲
	int PATROL_RANGE = 100;
	//スポーンから離れられる距離
	int LEASH_RANGE = 250;
	//視線距離
	int FIND_RANGE = 200;
	//攻撃距離
	int ATTACK_RANGE = 100;
	//攻撃時間
	int att_time{ 0 };
public:
	//向き
	enum DIR { DOWN, LEFT, RIGHT, UP };

	//位置,マップ
	CMoribu(Point, CMap*);

	int Action(const ObjList&, ObjList&);
	void Draw();	

	CCharaOBJ* target = nullptr;//追尾するターゲット

	//向き更新
	void UpdateDir(Point);

	//se
	int enemy_hit_SE{ -1 };
	int enemy_down_SE{ -1 };
	int enemy_att_SE{ -1 };
	int moribu_koe_SE{ -1 };
	int oldHP{ -1 };
};