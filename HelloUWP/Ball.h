#pragma once
#include "Drawable.h"
#include "pch.h"
#include "MainPage.xaml.h"
#include <windows.h>
#include <math.h>

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


// Model and View (in my MVC)
class Ball :public Drawable {
private:
	int radius;
	int center_x, center_y;
	float direction;
	float speed;
	float slowdown=0.05f;
	int min_x;
	int min_y;
	int max_x;
	int max_y;

public:
	Ball(int radius):Drawable(width*2,width*2), radius(radius) {
		center_x = 50;
		center_y = 50;
	}

	virtual void Draw(CanvasDrawingSession^ session) {
		// ?+ FIX
		session->FillCircle(center_x, center_y, radius, Colors::White);
		session->DrawCircle(center_x, center_y, radius, Colors::Black,radius*0.2);
	}

	virtual void moveTo(int xTo, int yTo) {
		center_x = xTo, center_y = yTo;
	}

	int getX() const{
		return this->center_x;
	}

	int getY() const {
		return this->center_y;
	}

	bool isInside(int x, int y) {
		return x >= min_x && x <= max_x && y >= min_y && y <= max_y;
	}

	bool isOutHorizontally(int x) {
		return x<min_x || x>max_x;
	}

	virtual void move(float speed, float direction) {
		this->speed = speed;
		this->direction = direction;

		while (speed > 0) {
			int next_x = center_x + speed*cos(direction);
			int next_y = center_y - speed*sin(direction);
			center_x = next_x;
			center_y = next_y;
			if (!isInside(next_x, next_y)) {
				int a = 4;
				direction = -direction;
			}
			Sleep(50);
			speed -= slowdown;
		}
	}

	void setBorders(int min_x, int min_y, int  max_x, int max_y) {
		this->min_x = min_x;
		this->min_y = min_y;
		this->max_x = max_x;
		this->max_y = max_y;
	}

};