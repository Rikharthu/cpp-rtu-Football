#pragma once
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

class Drawable {

protected: 
	int x;
	int y;
	int height;
	int width;
	// we don't want Drawable to be instanced outside it's children
	Drawable(int width, int height) :height(height), width(width) {}
public:
	//!+++ НЕ КОМПИЛИРУЕТ
	// Drawable draws itself through CanvasDrawingSession
	//virtual void Draw(CanvasDrawingSession);
	// Checks if point at given x and y coordinates is inside/intersects with current Drawable
	//virtual bool IsInside(int x, int y);
};