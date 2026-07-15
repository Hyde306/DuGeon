//プレイヤー
#include "player.h"
#include "sword.h"
#include "function.h"

const float MOVE_SPEED = 4.0f;

CPlayer::CPlayer(CMap* _map)
{
	sprite.img = Resource::playerImg;
	sprite.cutX = 0;
	sprite.cutY = 0;

	sprite.width =  32;
	sprite.height =  32;

	pos = startPos;

	map = _map;

	pri = 2;

	ID = (int)ObjID::PLAYER;

	hp = maxhp = 10;
}

int CPlayer::Action(const ObjList& base, ObjList& add_base) 
{
	int PAD_INFO = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	switch (state) {
	case PlayerState::NORMAL:
		//死亡チェック
		if (hp <= 0) {
			//SE
			PlaySoundMem(player_down_SE, DX_PLAYTYPE_BACK);
			state = PlayerState::DEAD;
			return 0;
		}
		break;
	case PlayerState::DEAD:
		deadTimer++;
		if (deadTimer == 30)
		{
			Respawn();
			state = PlayerState::NORMAL;
			deadTimer = 0;
		}
		return 0;
	}

	vec.x = vec.y = 0;
	if (att_frame > 0) att_frame--;
	//攻撃中判定フラグ
	bool isAttack = (att_frame > 0);
	//ノックバック処理
	//SE
	if (damageCoolTime == 20) PlaySoundMem(player_damage_SE, DX_PLAYTYPE_BACK);
	//ダメージクールタイムチェック
	if (damageCoolTime > 0)damageCoolTime--;
	if (knockFrame > 0) {
		knockFrame--;
		//サブステップ判定
		//処理回数を計算
		int step = (int)max(abs(knockVec.x), abs(knockVec.y));
		step = max(step, 1);
		//1ステップの移動量を計算
		float moveX = knockVec.x / step;
		float moveY = knockVec.y / step;
		//ステップ判定
		for (int i = 0; i < step; i++) {
			//マップ判定
			Point nextPos = pos;
			nextPos.x += moveX;
			if (map->CanMove(nextPos, sprite.width, sprite.height))pos.x = nextPos.x;
			nextPos = pos;
			nextPos.y += moveY;
			if (map->CanMove(nextPos, sprite.width, sprite.height))pos.y = nextPos.y;
		}
		knockVec.x *= 0.8f;
		knockVec.y *= 0.8f;

		return 0;
	}

	if (!isAttack) {
		//キー入力
		if (CheckHitKey(KEY_INPUT_A) || (PAD_INFO & PAD_INPUT_LEFT)) vec.x = -1.0f;
		if (CheckHitKey(KEY_INPUT_D) || (PAD_INFO & PAD_INPUT_RIGHT)) vec.x = 1.0f;
		if (CheckHitKey(KEY_INPUT_W) || (PAD_INFO & PAD_INPUT_UP)) vec.y = -1.0f;
		if (CheckHitKey(KEY_INPUT_S) || (PAD_INFO & PAD_INPUT_DOWN)) vec.y = 1.0f;

		//攻撃処理
		if ((CheckHitKey(KEY_INPUT_SPACE) || (PAD_INFO & PAD_INPUT_1)) && (!key[(PAD_INFO & PAD_INPUT_1)] &&!key[KEY_INPUT_SPACE])) {
			//SE
			PlaySoundMem(player_att_SE, DX_PLAYTYPE_BACK);
			add_base.push_back(make_unique<CSword>(pos, Dir, map));
			att_frame = 13;
			attackCount++;
		}
	}
	//移動しているかフラグ
	bool isMove = (vec.x != 0 || vec.y != 0);

	//向き
	Dir = GetDir(Dir);

	//切り取り位置計算
	if (Dir == (int)DIR::DOWN) {
		sprite.cutY = 32;
	}
	else if (Dir == (int)DIR::UP) {
		sprite.cutY = 0;
	}
	else {
		sprite.LR_reverse_flag = true;
		if (Dir >= (int)DIR::LEFT_DOWN && Dir <= (int)DIR::LEFT_UP)
			sprite.LR_reverse_flag = false;
		sprite.cutY = 64;
	}

	//アニメーション処理
	if (isMove) {
		animTimer++;
		if (animTimer >= 10) 
		{
			animTimer = 0;
			sprite.cutX += sprite.width;
			if (sprite.cutX > sprite.width)	sprite.cutX = 0;
		}
	}
	else {
		animFrame = 0;
	}

	//移動ベクトル計算
	if (isMove) {
		//移動ベクトル計算
		vec = Vector_SetLength(vec, MOVE_SPEED);
		//移動できるかチェック
		Point nextPos = pos;
		//x方向
		nextPos.x += vec.x;
		if (map->CanMove(nextPos, sprite.width, sprite.height))
		{
			pos.x = nextPos.x;
		}
		//y方向
		nextPos = pos;
		nextPos.y = pos.y + vec.y;
		if (map->CanMove(nextPos, sprite.width, sprite.height)) {
			pos.y = nextPos.y;
		}
	}

	//入力状態の保存
	GetHitKeyStateAll(key);
	key[(PAD_INFO & PAD_INPUT_1)] = PAD_INFO & PAD_INPUT_1;

	//レベルチェック
	GetLevel(exp);

	return 0;
}

//リスポーン処理
void CPlayer::Respawn()
{
	hp = maxhp;//体力全快
	pos = startPos;//初期位置
}

//レベル計算
void CPlayer::GetLevel(int exp) {
	if (exp > lv * 10) {
		lv++;
		//lv99でカンスト
		if (lv > 99) return;
		maxhp += 5;
		hp += 5;
	}
}

void CPlayer::Draw()
{
	//描画位置を計算
	Point draw_pos = CameraToScreen(pos, map->camera);

	//体力ゲージ
	DrawHpBar(draw_pos, hp, maxhp);

	//プレイヤー
	sprite.Draw(draw_pos.x, draw_pos.y);

}