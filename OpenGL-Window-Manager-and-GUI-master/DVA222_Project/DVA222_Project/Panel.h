#pragma once
#include "UIControl.h"
#include "Container.h"
#include <stdlib.h>
#include <vector>
#include "Header.h"
#include "Graphix.h"
#include "Label.h"
#include <algorithm>

class Panel : public Container
{
protected:
	//Looks
	Color background;

	//Helper function for painting panel elements
	virtual void PaintElements();

public:
	//Contructor
	Panel();

	//Desctructor
	~Panel();

	//Looks
	virtual void SetBackground(Color background);
	virtual Color GetBackground();

	//ControlBase Overrides
	virtual void OnPaint();
	
	//Custom SetZeroPointForControls
	virtual void SetZeroPointForControls();
};

