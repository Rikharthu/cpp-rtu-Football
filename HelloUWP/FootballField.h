#pragma once
#include "Drawable.h"
#include "pch.h"
#include "MainPage.xaml.h"

using namespace HelloUWP;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Numerics;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Microsoft::Graphics::Canvas::UI::Xaml;
using namespace Microsoft::Graphics::Canvas;

class FootballField : public Drawable {
protected:
	float marking_width;

public:
	FootballField(int width, int height, float marking_width) : Drawable(width,height),marking_width(marking_width) {

	}

	void setDimension(int width, int height) {
		this->width = width;
		this->height = height;
	}

	void setWidth(int width) {
		this->width = width;
	}

	void setHeight(int height) {
		this->height = height;
	}

	void setMarkingWidth(float marking_width) {
		this->marking_width = marking_width;
	}

	virtual void Draw(CanvasDrawingSession^ session) {
		float center_x = width / 2;
		float center_y = height / 2;
		// Draw green grass background
		session->FillRectangle(0, 0, width, height, Colors::Green);
		// Draw field markings
		session->DrawCircle(center_x, center_y, height / 2 * 0.7, Colors::White, marking_width);
		session->FillCircle(center_x, center_y, 2 * marking_width, Colors::White);
		session->DrawLine(center_x, 0, center_x, height, Colors::White, marking_width);
	}

};