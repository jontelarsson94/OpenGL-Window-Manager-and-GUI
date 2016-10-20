#include "StdAfx.h"
#include <iostream>
#include "Graphix.h"
#include <windows.h>
#include "ControlBase.h"


using namespace std;

ControlBase *w = NULL;

//===================================
//
//  C A N ' T   T O U C H   T H I S
//
//===================================



void DrawLine(int x1, int y1, int x2, int y2 )
{
    glBegin(GL_LINES);
        glVertex3f(x1, y1, 0.0);
        glVertex3f(x2, y2, 0.0);
    glEnd();    
}

void DrawRectangle(int x, int y, int width, int height )
{
	glBegin(GL_LINE_LOOP);
        glVertex3f(x, y, 0.0);
        glVertex3f(x+width, y, 0.0);
		glVertex3f(x+width, y+height, 0.0);
		glVertex3f(x, y+height, 0.0);
    glEnd();    
}

void DrawCircle(int cx, int cy, int radius )
{
	glBegin(GL_LINE_LOOP);
	for (int i = 0;i <= 360; i+= 5)
	{
		int x = cos(i / 180.0 * 3.1416) * radius;
		int y = sin(i / 180.0 * 3.1416) * radius;
        glVertex3f(cx+x, cy+y, 0.0);
	}
    glEnd();    
}

void FillRectangle(int x, int y, int width, int height )
{
	glBegin(GL_QUADS);
        glVertex3f(x, y, 0.0);
        glVertex3f(x+width, y, 0.0);
		glVertex3f(x+width, y+height, 0.0);
		glVertex3f(x, y+height, 0.0);
    glEnd();    
}

void DrawString(string text, int x, int y)
{
    glRasterPos2i(y,x);
    for(int i = 0; i < (int) text.length(); i++){ 
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text.data()[i]);
    }
}

void DrawBitmap(Bitmap &b, int x, int y)
{
	glPushMatrix();
	glTranslatef((float)x,(float)y,0);
	////enable textures and set up automatic texture coordinate generation
	glBindTexture(GL_TEXTURE_2D, b.GetTexture());  
	glEnable(GL_TEXTURE_2D);

	glColor4f(1.0f,1.0f,1.0f,1.0f);

	//Define how alpha blending will work and enable alpha blending.
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	glPolygonMode(GL_FRONT_AND_BACK, GL_POLYGON);
	glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, b.GetHeight());
            glTexCoord2f(1.0f, 0.0f); glVertex2f(b.GetWidth(), b.GetHeight());
            glTexCoord2f(1.0f, 1.0f); glVertex2f(b.GetWidth(), 0.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}


void DrawBitmap(Bitmap &b, int x, int y, int w, int h)
{
	glPushMatrix();
	glTranslatef((float)x,(float)y,0);
	////enable textures and set up automatic texture coordinate generation
	glBindTexture(GL_TEXTURE_2D, b.GetTexture());  
	glEnable(GL_TEXTURE_2D);

	glColor4f(1.0f,1.0f,1.0f,1.0f);

	//Define how alpha blending will work and enable alpha blending.
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	glPolygonMode(GL_FRONT_AND_BACK, GL_POLYGON);
	glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, 0.0f);
            glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, (float)h);
            glTexCoord2f(1.0f, 0.0f); glVertex2f((float)w, (float)h);
            glTexCoord2f(1.0f, 1.0f); glVertex2f((float)w, 0.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}


void DrawBitmap(Bitmap &b, Rect& rect, int x, int y)
{
	glPushMatrix();
	glTranslatef((float)x,(float)y,0);
	////enable textures and set up automatic texture coordinate generation
	glBindTexture(GL_TEXTURE_2D, b.GetTexture());  
	glEnable(GL_TEXTURE_2D);

	glColor4f(1.0f,1.0f,1.0f,1.0f);

	//Define how alpha blending will work and enable alpha blending.
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	float tx1 = min(1.0f, (float)rect.X / (float)b.GetWidth());
	float ty1 = min(1.0f, (float)rect.Y / (float)b.GetHeight());

	float q = ((float)(rect.Width)/((float)b.GetWidth()));
	float tx2 = min(1.0f, tx1 + q);

	float f = (float)(rect.Height)/((float)b.GetHeight());
	float ty2 = min(1.0f, (ty1 + f) );



	glPolygonMode(GL_FRONT_AND_BACK, GL_POLYGON);
	glBegin(GL_QUADS);
            glTexCoord2f(tx1, 1-ty1); glVertex2f(0.0f, 0.0f);
			glTexCoord2f(tx1, 1-ty2); glVertex2f(0.0f, (float)rect.Height);
            glTexCoord2f(tx2, 1-ty2); glVertex2f((float)rect.Width, (float)rect.Height);
            glTexCoord2f(tx2, 1-ty1); glVertex2f((float)rect.Width, 0.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}


void SetColor(int r, int  g, int  b)
{
	glColor3f(r/255.0,g/255.0,b/255.0);
}



void paint(void)
{
	//Clear all pixels
    glClear(GL_COLOR_BUFFER_BIT);

    w->OnPaint();
    // Don't wait start processing buffered OpenGL routines
	glutSwapBuffers();
	
}

void timer(int millisec)
{
    glutTimerFunc(millisec, timer, millisec); // for next timer event
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	w->OnKeyboard(key, x, y);
	glutPostRedisplay(); /* this redraws the scene without
							waiting for the display callback so that any changes appear
							instantly */
}

void mouse(int button, int state, int x, int y)
{
	if (state  == GLUT_UP)
		w->OnMouseUp(button, x, y);
	else
		w->OnMouseDown(button, x, y);
	glutPostRedisplay(); /* this redraws the scene without
							waiting for the display callback so that any changes appear
							instantly */
}

void motion(int x, int y)
{
	w->OnMouseMove(0, x, y);
}


void resize(int width, int height)
{
	w->Height = height;
	w->Width = width;

	w->OnResize(width, height);
	glutPostRedisplay(); /* this redraws the scene without
							waiting for the display callback so that any changes appear							instantly */
}



void InitOGL(int argc, char** argv, ControlBase *window)
{	
	w = window;
	//Initialise GLUT with command-line parameters. 
    glutInit(&argc, argv);
    //Set Display Mode
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    //Set the window size
    glutInitWindowSize(800,600);	
    //Set the window position
    glutInitWindowPosition(100,100);
    //Create the window
    glutCreateWindow("DVA 222 - Assignment 2");
    //Call init (initialise GLUT
	//select clearing (background) color
    glClearColor(1.0, 1.0, 1.0, 1.0);
    //initialize viewing values 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 800.0, 600.0, 0.0, -1.0, 1.0);


 //   glEnable ( GL_COLOR_MATERIAL );
 //   glColorMaterial ( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );

	//glEnable ( GL_CULL_FACE );

	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    window->OnLoaded();
    //Call "display" function
	glutDisplayFunc(paint);
	glutTimerFunc(33, timer, 33); // redraw every 33 millisec (30fps)

	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	glutMotionFunc(motion);
	glutPassiveMotionFunc(motion);

    //Enter the GLUT event loop
    glutMainLoop();
}



//////////////


const int TF_NONE = 0;
const int TF_BILINEAR = 1;

Bitmap::Bitmap(string filename) 
{       
        HBITMAP hBmp = NULL;

		hBmp = (HBITMAP) ::LoadImageA(0, filename.c_str(), IMAGE_BITMAP, 0, 0, LR_DEFAULTSIZE |LR_CREATEDIBSECTION | LR_LOADFROMFILE);		

        //get info about the bitmap
        BITMAP BM;
        ::GetObject(hBmp, sizeof(BM), &BM);	


		width = BM.bmWidth;
		height = BM.bmHeight;
			
		glGenTextures(1, &texture[0]);  

        //tell OpenGL to ignore padding at ends of rows
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		glBindTexture(GL_TEXTURE_2D, texture[0]);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BM.bmWidth, BM.bmHeight,
                0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BM.bmBits);

        DeleteObject((HGDIOBJ) hBmp);  //avoid memory leak (Windows)
}