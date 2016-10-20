#pragma once
typedef struct _color
{
	_color()
	{
	}
	_color(int r, int g, int b)
	{
		R = r;
		G = g;
		B = b;
	}
	int R, G, B;
}Color;