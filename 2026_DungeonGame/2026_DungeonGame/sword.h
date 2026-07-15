#pragma once
#include "objBase.h"
#include "map.h"

class CSword :public CCharaOBJ
{
public:
	//位置,向き,マップ,オーナーオブジェクト
	CSword(Point,int,CMap*);

	int Action(const ObjList&, ObjList&);
	void Draw();

	//角度
	float angle{ 0 };
	float start_angle{ 0 };

	//剣の長さ
	const float SWORD_LENGTH = 48;
};