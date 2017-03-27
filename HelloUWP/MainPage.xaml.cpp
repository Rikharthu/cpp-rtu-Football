//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "FootballField.h"
#include "Ball.h"
#include <windows.h>

#define PI 3.14159265358979323846

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

//?+++ что за ^ ?

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409
void LogMessage(Object^);
void DrawFootballField(CanvasDrawingSession^);

float max_width = 0, max_height = 0;
float circle_radius = 10;
Ball * ball;


MainPage::MainPage()
{
	InitializeComponent();

	ball = new Ball(circle_radius);

	//canvas->TargetElapsedTime.Duration;
	max_width = 800;
	max_height = 400;
	ball->setBorders(0, 0, max_width, max_height);

}


void HelloUWP::MainPage::Hello_Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	
	float dir = _wtof(nameInput->Text->Data());
	float pwr = _wtof(powerInput->Text->Data());
	ball->move(pwr, PI*dir / 180);
}

// Convert std::string to Platform::String
void LogMessage(Object^ parameter)
{
	auto paraString = parameter->ToString();
	auto formattedText = std::wstring(paraString->Data()).append(L"\r\n");
	OutputDebugString(formattedText.c_str());
}


void HelloUWP::MainPage::CanvasAnimatedControl_Draw(Microsoft::Graphics::Canvas::UI::Xaml::ICanvasAnimatedControl^ sender, Microsoft::Graphics::Canvas::UI::Xaml::CanvasAnimatedDrawEventArgs^ args)
{
#ifdef _DEBUG
	LogMessage("Drawing Animated Canvas");
#endif
	float center_x = max_width / 2;
	float center_y = max_height / 2;
	FootballField * field = new FootballField(max_width, max_height, 10);
	field->Draw(args->DrawingSession);
	ball->Draw(args->DrawingSession);

}
