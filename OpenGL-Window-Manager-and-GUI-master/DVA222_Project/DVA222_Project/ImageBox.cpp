#include "StdAfx.h"
#include "ImageBox.h"
#include "Graphix.h"
#include "glut.h"

using namespace std;

// This is just a sample code to show you how you can use different Event Handlers in your code


ImageBox::ImageBox()
{
	hit = pressed = false;
}

ImageBox::ImageBox(int locX, int locY, int width, int height)
	: UIControl(locX, locY, width, height)
{
	hit = pressed = false;
}

ImageBox::~ImageBox()
{
	delete normal;
	delete hover;
	delete press;
}

//This is called whenever the user moves the mouse around
void ImageBox::OnMouseMove(int button, int x, int y)
{
	if (x>X && x < X + Width && y>Y && y < Y + Height)
		hit = true;
	else
	{
		pressed = hit = false;
	}
}

//This is called whenever the application wants to redraw its contents. We have already set it to 30 fps. You cannot change that
void ImageBox::OnPaint()
{
	/**if (pressed)
		DrawBitmap(*press, 100, 100, 500, 500);
	else if (hit)
		DrawBitmap(*hover, 100, 100, 500, 500);
	else
		DrawBitmap(*normal, 100, 100, 500, 500);
		**/
	DrawBitmap(*normal, 0, 0, 100, 100);
}

//Is called once, when the object is being loaded
void ImageBox::OnLoaded()
{
	//Only 24bit bmp files are supported
	//Edit your bitmaps in MSPaint also remember that the width of the image MUST be a factor of 4 (be dividable by 4)

	normal = new Bitmap("ButtonNorm.bmp");

}

//Is called when the user presses any of the mouse buttons down
void ImageBox::OnMouseDown(int button, int x, int y)
{
	if (hit && button == MOUSE_LEFT)
		pressed = true;
}

//Is called when the user releases any of the mouse buttons down
void ImageBox::OnMouseUp(int button, int x, int y)
{
	pressed = false;
}
