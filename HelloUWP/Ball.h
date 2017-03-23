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


class Ball :public Drawable {
private:
	int radius;
	int center_x, center_y;

public:
	Ball(int radius):Drawable(width*2,width*2), radius(radius) {
		center_x = x + radius;
		center_y = y + radius;
	}

	virtual void Draw(CanvasDrawingSession^ session) {
		// ?+ FIX
		session->FillCircle(center_x, center_y, radius, Colors::White);
		session->DrawCircle(center_x, center_y, radius, Colors::Black,radius*0.2);
	}

	virtual void moveTo(int xTo, int yTo) {
		center_x = xTo, center_y = yTo;
	}
};