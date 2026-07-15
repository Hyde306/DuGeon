//矢
#pragma once
#include "objBase.h"
#include "map.h"

class CBow :public CCharaOBJ
{
public:
	//位置,移動ベクトル
	CBow(Point, Vector, CMap*);

	int Action(const ObjList&, ObjList&);
	void Draw();

	float angle{ 0 };
	int life{ 60 };
};