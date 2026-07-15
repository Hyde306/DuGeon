//ƒŠƒ[ƒX
#include "Resource.h"

int Resource::playerImg;
int Resource::effectImg;
int Resource::enemy5Img;
int Resource::enemy6Img;
int Resource::bowImg;
int Resource::mapImg;

//‰æ‘œ“Ç‚İ‚İ
void Resource::Load()
{
	playerImg = LoadGraph("image\\player32.png");
	effectImg = LoadGraph("image\\effect02.png");
	enemy5Img = LoadGraph("image\\enemy5.png");
	enemy6Img = LoadGraph("image\\enemy6.png");
	bowImg = LoadGraph("image\\bow.png");
	mapImg = LoadGraph("image\\map.png");
}
//‰æ‘œíœ
void Resource::Release() {
	DeleteGraph(playerImg);
	DeleteGraph(effectImg);
	DeleteGraph(enemy5Img);
	DeleteGraph(enemy6Img);
	DeleteGraph(bowImg);
	DeleteGraph(mapImg);
}