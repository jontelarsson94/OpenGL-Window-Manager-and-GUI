#pragma once
#include <string>
#include <stdlib.h>
#include "ControlBase.h"

#include "glut.h"

using namespace std;


//===================================
//
//  C A N ' T   T O U C H   T H I S
//
//===================================


typedef struct _point
{
	_point()
	{
	}
	_point(double x, double y)
	{
	 X = x;
	 Y = y;
	}
	double X;
	double Y;
}Point;

typedef struct _size
{
	_size()
	{

	}
	_size(double width, double height)
	{
		Width = width;
		Height = height;
	}
	double Width;
	double Height;
}Size;

typedef struct _rectangle
{
	_rectangle()
	{

	}
	_rectangle(int x, int y, int width, int height)
	{
		X = x;
		Y = y;
		Width = width;
		Height = height;
	}
	int X;
	int Y;
	int Width;
	int Height;
}Rect;




class Bitmap
{
protected:
	 GLuint  texture[1]; 
	 int width;
	 int height;
public:
	 Bitmap(string filename);	 
	 inline GLuint GetTexture()
	 {
		 return texture[0];
	 }
	 inline int GetWidth()
	 {
		 return width;
	 }
	 inline int GetHeight()
	 {
		 return height;
	 }
};

void InitOGL(int argc, char** argv, ControlBase *window);

void SetColor(int r, int  g, int  b);

void FillRectangle(int x, int y, int width, int height );

void DrawCircle(int cx, int cy, int radius);
void DrawLine(int x1, int y1, int x2, int y2 );
void DrawRectangle(int x, int y, int width, int height );
void DrawString(string text, int x, int y);
void DrawBitmap(Bitmap &b, int x, int y);                       //Draws a bitmap with its original size in location x,y
void DrawBitmap(Bitmap &b, int x, int y, int w, int h);         //Draws a bitmap at location x,y and resizes it to w,h
void DrawBitmap(Bitmap &b, Rect& rect, int x, int y);           //Draws a bitmap at location x,y inside a rectangle


#define MOUSE_LEFT      0
#define MOUSE_MIDDLE    1
#define MOUSE_RIGHT     2


