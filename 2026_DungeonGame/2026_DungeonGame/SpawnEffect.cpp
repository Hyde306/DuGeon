//スポーンエフェクト
#include "SpawnEffect.h"
#include "octrock.h"

//位置,敵No,マップ
CSpawnEffect::CSpawnEffect(Point p, int no, CMap* _map, CSpawnPoint* s) {
	sprite.img = Resource::effectImg;
	sprite.cutX = 0;
	sprite.cutY = 96;
	sprite.width =  32;
	sprite.height = 32;

	EnemyNo = no;
	map = _map;
	pos = p;

	//スポーンポイントの情報取得
	spawnPoint = s;

	pri = 4;

	ID = (int)ObjID::SPAWN_EFFECT;
}

int CSpawnEffect::Action(const ObjList& base, ObjList& add_base)
{
	timer++;
	if (timer >= 30) {
		//敵の生成
		add_base.push_back(make_unique<COctrock>(pos, map, spawnPoint));
		FLAG = false;
	}

	//煙エフェクトアニメーション処理用
	animFrame = timer / 20;
	//切り取り位置計算
	sprite.cutX = animFrame * sprite.width;
	return 0;
}

void CSpawnEffect::Draw() {
	sprite.Draw(pos.x - map->camera.x, pos.y - map->camera.y);
}
