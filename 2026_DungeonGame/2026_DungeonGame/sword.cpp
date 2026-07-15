//Œ•
#include "sword.h"
#include "function.h"

CSword::CSword(Point p, int _dir, CMap* _map)
{
	sprite.img = Resource::playerImg;
	sprite.cutX = 96;
	sprite.cutY = 32;
	sprite.width = 32;
	sprite.height =32;

	pos = p;
	Dir = _dir;
	
	map = _map;

	//‰‰ñ‚ÌŒ•‚ÌŒü‚«
	if (Dir == (int)DIR::UP) {
		//ã
		angle = start_angle = 180;
	}
	else if (Dir == (int)DIR::DOWN) {
		//‰º
		angle = start_angle = 0;
	}
	else if (Dir >= (int)DIR::LEFT_DOWN && Dir <= (int)DIR::LEFT_UP) {	
		//¶
		angle = start_angle = -270;
	}
	else {
		//‰E
		angle = start_angle = 270;
	}

	pri = 1;

	//‰ŠúˆÊ’u
	vec.x = cos(RADIAN(angle)) * sprite.width;
	vec.y = sin(RADIAN(angle)) * sprite.height;
	sprite.angle = RADIAN(angle);

	ID = (int)ObjID::SWORD;
}

int CSword::Action(const ObjList& base, ObjList& add_base)
{
	//‰ñ“]
	vec.x = cos(RADIAN(angle)) * sprite.width;
	vec.y = sin(RADIAN(angle)) * sprite.height;
	sprite.angle = RADIAN(angle);
	angle += 15;

	//”¼Žü‚µ‚½‚çÁ‚¦‚é
	if (angle > start_angle + 195)
	{
		FLAG = false;
	}
	return 0;
}

void CSword::Draw()
{
	sprite.Draw(pos.x - map->camera.x+vec.x, pos.y - map->camera.y+vec.y);
}
