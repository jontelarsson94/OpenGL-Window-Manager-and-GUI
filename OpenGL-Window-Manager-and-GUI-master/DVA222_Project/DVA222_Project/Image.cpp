#include "StdAfx.h"
#include "Image.h"
#include "Graphix.h"
#include "glut.h"

using namespace std;

//Constructor
Image::Image(std::string path)
{
	this->path = path;
}

//Destructor
Image::~Image()
{
    delete bitmap;
}

//ControlBase Override
void Image::OnPaint()
{
        DrawBitmap(*bitmap, X+zeroPoint.X,Y+zeroPoint.Y,Width, Height);
    
}

void Image::OnLoaded()
{		
	bitmap = new Bitmap(path);
}	

