#include "bow.h"
#include "function.h"

CBow::CBow(Point p, Vector v, CMap* _m) {

	sprite.img = Resource::bowImg;
	sprite.cutX = 0;
	sprite.cutY = 0;
	sprite.width = 32;
	sprite.height = 32;

	pos = p;
	vec = Vector_SetLength(v, 8.0f);

	sprite.angle = atan2(vec.y, vec.x);

	map = _m;
	
	ID = (int)ObjID::BOW;
}

int CBow::Action(const ObjList&, ObjList&) 
{
	pos = Add_Point_Vector(pos, vec);

	life--;
	if (life == 0)FLAG = false;

	return 0;
}

void CBow::Draw()
{
	//•`‰æˆÊ’u‚ðŒvŽZ
	Point draw_pos = CameraToScreen(pos, map->camera);

	//•`‰æ
	sprite.Draw(draw_pos.x, draw_pos.y);
}