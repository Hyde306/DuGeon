//スポーンポイント
#include "SpawnPoint.h"
#include "function.h"
#include "SpawnEffect.h"

//位置, No, マップ
CSpawnPoint::CSpawnPoint(Point p,int no,CMap* _map) {
	EnemyNo = no;
	pos.x = p.x + CHIP_SIZE_X / 2;
	pos.y = p.y + CHIP_SIZE_Y / 2;
	map = _map;
}

int CSpawnPoint::Action(const ObjList& base, ObjList& add_base) 
{
	if (enemyAlive) return 0;

	timer++;
	if (timer >= 30 && !enemyAlive) {
		timer = 0;
		for (auto& obj : base) {
			if (obj->ID == (int)ObjID::PLAYER) {
				Point p = obj->pos;
				float dx = p.x - pos.x;
				float dy = p.y - pos.y;
				float l = sqrtf(dx * dx + dy * dy);
				//敵出現処理
				if (l < 200 && Range_Random_Number(0, 10)<5) {
					//敵エフェクト生成
					add_base.push_back(make_unique<CSpawnEffect>(pos, EnemyNo, map, this));
					enemyAlive = true;
					break;
				}
			}
		}
	}
	return 0;
}

void CSpawnPoint::Draw() {
}