//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "FootballField.h"
#include "Ball.h"

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


MainPage::MainPage()
{
	InitializeComponent();
}


void HelloUWP::MainPage::Hello_Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	// greetingOutput and nameInput ar automatically generated from XML file in MainPage.g.h
	//greetingOutput->Text = "Hello, " + nameInput->Text + "!";
	circle_radius = _wtof(nameInput->Text->Data());
	canvas->Invalidate();
}

// CanvasControl raises Draw whenever your app needs to draw or redraw its content (initial, resize and etc)
void HelloUWP::MainPage::CanvasControl_Draw(CanvasControl^ sender, CanvasDrawEventArgs^ args)
{
#ifdef _DEBUG
	LogMessage("Drawing Canvas");
#endif

	max_width = sender->ActualWidth;
	max_height = sender->ActualHeight;
	float center_x = max_width / 2;
	float center_y = max_height / 2;
	/*args->DrawingSession->FillRectangle(0, 0, max_width, max_height, Colors::Green);
	args->DrawingSession->DrawEllipse(155, 115, 80, 30, Colors::Black, 3);
	args->DrawingSession->DrawText("Hello, world!", 100, 100, Colors::Yellow);*/

	// Draw green grass background
	//args->DrawingSession->FillRectangle(0, 0, max_width, max_height, Colors::Green);
	//// Draw field markings
	//float marking_width = max_height*0.005;
	//args->DrawingSession->DrawCircle(center_x,center_y, max_height / 2 * 0.7, Colors::White, marking_width);
	//args->DrawingSession->FillCircle(center_x,center_y, 2* marking_width, Colors::White);
	//args->DrawingSession->DrawLine(center_x, 0, center_x, max_height, Colors::White, marking_width);
	//DrawFootballField(args->DrawingSession);
	FootballField * field = new FootballField(max_width, max_height, circle_radius);
	field->Draw(args->DrawingSession);
	Ball * ball = new Ball(25);
	ball->Draw(args->DrawingSession);

}

void DrawFootballField(CanvasDrawingSession^ session) {
	float center_x = max_width / 2;
	float center_y = max_height / 2;
	// Draw green grass background
	session->FillRectangle(0, 0, max_width, max_height, Colors::Green);
	// Draw field markings
	float marking_width = max_height*0.005;
	session->DrawCircle(center_x, center_y, max_height / 2 * 0.7, Colors::White, marking_width);
	session->FillCircle(center_x, center_y, 2 * marking_width, Colors::White);
	session->DrawLine(center_x, 0, center_x, max_height, Colors::White, marking_width);

}

// Convert std::string to Platform::String
void LogMessage(Object^ parameter)
{
	auto paraString = parameter->ToString();
	auto formattedText = std::wstring(paraString->Data()).append(L"\r\n");
	OutputDebugString(formattedText.c_str());
}
