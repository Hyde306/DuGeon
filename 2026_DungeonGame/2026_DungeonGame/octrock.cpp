//オクトロック
#include "octrock.h"
#include "function.h"
#include "player.h"

COctrock::COctrock(Point p,CMap* _map,CSpawnPoint* _spawn)
{
	sprite.img = Resource::enemy5Img;
	sprite.cutX = 0;
	sprite.cutY = 0;
	sprite.width =  32;
	sprite.height = 32;

	map = _map;

	spawnPos = pos = p;

	pri = 3;

	hp = maxhp = 2;

	switch (Range_Random_Number(0, 3))
	{
	case 0: vec.x = 0; vec.y = 0.5f; break;//上
	case 1: vec.x = 0; vec.y = -0.5f; break;//下
	case 2: vec.x = 0.5f; vec.y = 0; break;//右
	case 3: vec.x = -0.5f; vec.y = 0; break;//左
	}

	//スポーン位置保存
	spawn = _spawn;

	ID = (int)ObjID::OCTROCK;
}

int COctrock::Action(const ObjList& base, ObjList& add_base)
{
	if (damageCoolTime > 0)damageCoolTime--;
	//ノックバック処理
	if (knockFrame > 0)
	{
		knockFrame--;

		//サブステップ判定処理
		//処理回数を求める
		int step = (int)max(abs(knockVec.x), abs(knockVec.y));
		step = max(step, 1);
		//1ステップの移動距離を計算
		float moveX = knockVec.x / step;
		float moveY = knockVec.y / step;
		//ステップ判定
		for (int i = 0; i < step; i++)
		{
			//マップ判定
			Point nextPos = pos;
			nextPos.x += moveX;
			if (map->CanMove(nextPos, sprite.width, sprite.height))	pos.x = nextPos.x;
			nextPos = pos;
			nextPos.y += moveY;
			if (map->CanMove(nextPos, sprite.width, sprite.height))	pos.y = nextPos.y;
		}
		//減速
		knockVec.x *= 0.8f;
		knockVec.y *= 0.8f;

		return 0;
	}

	//移動処理
	{
		//サブステップ判定処理
		//処理回数を求める
		int step = (int)max(abs(vec.x), abs(vec.y));
		step = max(step, 1);
		//1ステップの移動距離を計算
		float moveX = vec.x / step;
		float moveY = vec.y / step;
		bool hitX{ false }, hitY{ false };
		//ステップ判定
		for (int i = 0; i < step; i++)
		{
			//マップ判定
			Point nextPos = pos;
			nextPos.x += moveX;
			if (map->CanMove(nextPos, sprite.width, sprite.height)) {
				pos.x = nextPos.x;
			}
			else {
				hitX = true;
			}
			nextPos = pos;
			nextPos.y += moveY;
			if (map->CanMove(nextPos, sprite.width, sprite.height)) {
				pos.y = nextPos.y;
			}
			else {
				hitY = true;
			}
		}
		if (hitX)vec.x = -vec.x;
		if (hitY)vec.y = -vec.y;

		//アニメーション
		animTimer++;
		if (animTimer >= 15)
		{
			animTimer = 0;
			animFrame++;
			if (animFrame > 1)
				animFrame = 0;
		}
		sprite.cutX = animFrame * sprite.width;
		if (Dir == LEFT || Dir == RIGHT) sprite.cutY = 32;
		if (Dir == UP || Dir == DOWN) sprite.cutY = 0;

	}

	if (hp <= 0) {
		//エフェクト生成
		add_base.push_back(make_unique<CEffect>(pos, 4, 2, 5, map));
		FLAG = false;
		//スポーン位置スポーン許可
		spawn->enemyAlive = false;
	}

	return 0;
}

void COctrock::Draw() 
{
	//描画位置を計算
	Point draw_pos = CameraToScreen(pos, map->camera);

	//体力ゲージ
	DrawHpBar(draw_pos, hp, maxhp);

	//描画向き	
	sprite.LR_reverse_flag = false;
	sprite.UD_reverse_flag = false;
	if (Dir == LEFT)sprite.LR_reverse_flag = true;
	if (Dir == DOWN)sprite.UD_reverse_flag = true;
	//描画
	sprite.Draw(draw_pos.x, draw_pos.y);
}

//向きの更新処理
void COctrock::UpdateDir(Point target)
{
	float dx = target.x - pos.x;
	float dy = target.y - pos.y;

	if (fabs(dx) > fabs(dy))
		Dir = (dx > 0) ? RIGHT : LEFT;
	else
		Dir = (dy > 0) ? DOWN : UP;
}