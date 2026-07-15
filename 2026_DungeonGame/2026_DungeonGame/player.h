#pragma once
#include "objBase.h"
#include "map.h"

class CPlayer :public CCharaOBJ
{
private:
	Point startPos{ 7660,5370 };
public:
	CPlayer(CMap*);

	int Action(const ObjList&, ObjList&);
	void Draw();

	//キーの状態保存
	char key[256]{ 0 };

	//攻撃中フレーム
	int att_frame{ 0 };
	//攻撃カウント
	int attackCount{ 0 };

	//レベル
	int lv{ 1 };
	//経験値
	int exp{ 0 };

	//リスポーン処理
	void Respawn();

	PlayerState state{ PlayerState::NORMAL };
	int deadTimer{ 0 };

	//レベル計算
	void GetLevel(int);

	//SE
	int player_att_SE{ -1 };
	int player_damage_SE{ -1 };
	int player_down_SE{ -1 };

};