//リソースクラス
#pragma once
#include "main.h"

class Resource {
public:
	static int playerImg;
	static int effectImg;
	static int enemy5Img;
	static int enemy6Img;
	static int bowImg;
	static int mapImg;

	//リソースの読み込み
	static void Load();
	//各リソースの削除処理
	static void Release();
};