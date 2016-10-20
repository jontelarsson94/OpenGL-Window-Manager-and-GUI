// DVA222_Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Graphix.h"
#include "glut.h"
#include "Button.h"
#include "Label.h"
#include "Panel.h"
#include "RadioButton.h"
#include "CheckBox.h"
#include "Window.h"
#include "ImageBox.h"
#include "CheckBoxGroup.h"
#include "RadioButtonGroup.h"
#include "Image.h"

using namespace std;


int _tmain(int argc, char** argv)
{
    //A new object of Button type is create and passed to the InitOGL function. 
    //From that point the control is handed over to the OpenGL window and stays there until the user closes the Window.
    //This means after calling the InitOGL function no further lines of code in the main function are executed until we close the Window.
    //------------------------------------------------------------------------------------------------------------------------------------
    
	Window* window_1 = new Window();
	window_1->SetLocation(Point(20, 20));
	window_1->SetSize(Size(550, 450));
	//window_1->SetBackground(Color(235, 235, 235));
	window_1->setTitle("I am the window!");

	Label* label_top = new Label();
	label_top->SetLocation(Point(20, 20));
	label_top->setText("I am Label. Actually all the text you see inside those 2 panels ...");
	//label_top->setColor(Color(50, 50, 50));

	CheckBoxGroup* checkBoxGroup_1 = new CheckBoxGroup();
	checkBoxGroup_1->SetLocation(Point(10, 50));
	checkBoxGroup_1->SetSize(Size(250, 150));
	checkBoxGroup_1->SetTitle("Check boxes");
	//checkBoxGroup_1->SetBackground(Color(210, 210, 210));
	CheckBox* checkBox_1 = new CheckBox();
	CheckBox* checkBox_2 = new CheckBox();
	CheckBox* checkBox_3 = new CheckBox();
	CheckBox* checkBox_4 = new CheckBox();
	checkBox_1->setText("I am a CheckBox");
	checkBox_2->setText("I am another CheckBox");
	checkBox_3->setText("I am a selected CheckBox");
	checkBox_4->setText("I am another selected CheckBox");
	checkBox_3->setStatus(true);
	checkBox_4->setStatus(true);
	checkBoxGroup_1->Add(checkBox_1);
	checkBoxGroup_1->Add(checkBox_2);
	checkBoxGroup_1->Add(checkBox_3);
	checkBoxGroup_1->Add(checkBox_4);

	RadioButtonGroup* radioButtonGroup_1 = new RadioButtonGroup();
	radioButtonGroup_1->SetLocation(Point(10 + 250 + 20, 50));
	radioButtonGroup_1->SetSize(Size(250, 150));
	radioButtonGroup_1->SetTitle("Radios");
	//radioButtonGroup_1->SetBackground(Color(210, 210, 210));
	RadioButton* radioButton_1 = new RadioButton(radioButtonGroup_1);
	RadioButton* radioButton_2 = new RadioButton(radioButtonGroup_1);
	RadioButton* radioButton_3 = new RadioButton(radioButtonGroup_1);
	RadioButton* radioButton_4 = new RadioButton(radioButtonGroup_1);
	radioButton_1->setText("I am a RadioButton");
	radioButton_2->setText("I am another RadioButton");
	radioButton_3->setText("I am THE selected RadioButton");
	radioButton_4->setText("I am just another RadioButton");
	radioButton_3->setStatus(true);
	radioButtonGroup_1->Add(radioButton_1);
	radioButtonGroup_1->Add(radioButton_2);
	radioButtonGroup_1->Add(radioButton_3);
	radioButtonGroup_1->Add(radioButton_4);

	RadioButton* freeRadioButton_1 = new RadioButton();
	freeRadioButton_1->SetLocation(Point(20, 50 + 150 + 20));
	freeRadioButton_1->setText("I am a free RadioButton");

	CheckBox* freeCheckBox_1 = new CheckBox();
	freeCheckBox_1->SetLocation(Point(20, 50 + 150 + 20 + 20));
	freeCheckBox_1->setText("And I am a free CheckBox");
	//freeCheckBox_1->setColor(Color(150, 0, 0));

	Image* image_1 = new Image("image.bmp");
	image_1->SetLocation(Point(20, 50 + 150 + 20 + 20 + 40));
	image_1->SetSize(Size(100, 100));
	
	Panel* panel_1 = new Panel();
	panel_1->SetLocation(Point(10 + 250 + 20, 50 + 150 + 20));
	panel_1->SetSize(Size(250, 150));
	panel_1->SetBackground(Color(233, 30, 99));
	panel_1->SetZ(1);

	Label* label_panel_1 = new Label();
	label_panel_1->SetLocation(Point(20, 20));
	label_panel_1->setText("I am a panel.");
	label_panel_1->setColor(Color(256, 256, 256));

	panel_1->Add(label_panel_1);

	Panel* panel_2 = new Panel();
	panel_2->SetLocation(Point(10 + 250 + 20 - 100, 50 + 150 + 20 + 50));
	panel_2->SetSize(Size(250, 150));
	panel_2->SetBackground(Color(194, 24, 91));
	panel_2->SetZ(2);

	Label* label_panel_2 = new Label();
	label_panel_2->SetLocation(Point(20, 20));
	label_panel_2->setText("I am also a panel.");
	label_panel_2->setColor(Color(256, 256, 256));

	panel_2->Add(label_panel_2);

	Button* button = new Button();
	button->SetLocation(Point(20, 40));
	//button->SetSize(Size(75, 20));
	button->SetButtonText("Button");

	panel_2->Add(button);
	
	

	window_1->Add(label_top);
	window_1->Add(checkBoxGroup_1);
	window_1->Add(radioButtonGroup_1);
	window_1->Add(freeRadioButton_1);
	window_1->Add(freeCheckBox_1);
	
	window_1->Add(panel_1);
	window_1->Add(panel_2);
	window_1->Add(image_1);
	
	ControlBase* base = window_1;

	InitOGL(argc, argv, base);

	delete base;
	delete window_1;
	delete label_top;
	delete label_panel_1;
	delete label_panel_2;
	delete panel_1;
	delete panel_2;
	delete freeCheckBox_1;
	delete freeRadioButton_1;
	delete radioButtonGroup_1;
	delete radioButton_1; 
	delete radioButton_2;
	delete radioButton_3;
	delete radioButton_4;
	delete checkBoxGroup_1;
	delete checkBox_1;
	delete checkBox_2;
	delete checkBox_3;
	delete checkBox_4;
	delete image_1;
	delete button;

	return 0;
}

