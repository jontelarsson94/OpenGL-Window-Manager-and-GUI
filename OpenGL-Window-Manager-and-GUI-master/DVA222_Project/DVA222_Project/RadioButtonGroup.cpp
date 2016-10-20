#include "stdafx.h"
#include "RadioButtonGroup.h"
#include "RadioButton.h"

//Constructor
RadioButtonGroup::RadioButtonGroup()
{
}

//Destructor
RadioButtonGroup::~RadioButtonGroup()
{
}

//Reset radios
void RadioButtonGroup::Reset()
{
	int size = controls.size();
	for (int i = 1; i < size; i++)
	{
		RadioButton* e = (RadioButton*) controls.at(i);
		e->setStatus(false);
	}
}
