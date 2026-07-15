//モリブ
#include "moribu.h"
#include "function.h"
#include "player.h"
#include "bow.h"

CMoribu::CMoribu(Point p, CMap* _map)
{
	sprite.img = Resource::enemy6Img;
	sprite.cutX = 0;
	sprite.cutY = 0;
	sprite.width = 32;
	sprite.height = 32;

	map = _map;

	pri = 3;

	hp = 40;

	switch (Range_Random_Number(0, 3))
	{
	case 0: vec.x = 0; vec.y = -3.0f; break;//上
	case 1: vec.x = 0; vec.y = 3.0f; break;//下
	case 2: vec.x = 3.0f; vec.y = 0; break;//右
	case 3: vec.x = -3.0f; vec.y = 0; break;//左
	}

	pos.x = p.x * 64 + sprite.width / 2;
	pos.y = p.y * 64 + sprite.height / 2;

	ID = (int)ObjID::MORIBU;
}

int CMoribu::Action(const ObjList& base, ObjList& add_base)
{
	CPlayer* player = (CPlayer*)Get_obj(base, (int)ObjID::PLAYER);
	float dis = DistanceF(player->pos.x, player->pos.y, pos.x, pos.y);

	//SE
	if (oldHP != hp) {
		if (hp > 0 && dis < 300) PlaySoundMem(enemy_hit_SE, DX_PLAYTYPE_BACK);
		oldHP = hp;
	}
	//ダメージクールタイムチェック
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

	//行動処理
	{
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
		if (Dir == LEFT || Dir == RIGHT) sprite.cutY = 64;
		if (Dir == UP) sprite.cutY = 0;
		if (Dir == DOWN) sprite.cutY = 32;

	}

	if (hp <= 0) {
		//SE
		PlaySoundMem(enemy_down_SE, DX_PLAYTYPE_BACK);
		//エフェクト生成
		add_base.push_back(make_unique<CEffect>(pos, 4, 2, 5, map));
		FLAG = false;
	}
	//時間経過で回復
	timer++;
	if (timer > 600) {
		hp += 1;
		if (hp > maxhp) hp = maxhp;
		timer = 0;
	}
	return 0;
}

void CMoribu::Draw()
{
	//描画位置を計算
	Point draw_pos = CameraToScreen(pos, map->camera);

	//体力ゲージ
	DrawHpBar(draw_pos, hp, maxhp);

	//描画向き	
	sprite.LR_reverse_flag = false;
	if (Dir == LEFT)sprite.LR_reverse_flag = true;
	//描画
	sprite.Draw(draw_pos.x, draw_pos.y);
}

//向きの更新処理
void CMoribu::UpdateDir(Point target)
{
	float dx = target.x - pos.x;
	float dy = target.y - pos.y;

	if (fabs(dx) > fabs(dy))
		Dir = (dx > 0) ? RIGHT : LEFT;
	else
		Dir = (dy > 0) ? DOWN : UP;
}