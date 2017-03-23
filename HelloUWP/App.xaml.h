//
// App.xaml.h
// Declaration of the App class.
//

#pragma once

#include "App.g.h"

namespace HelloUWP
{
	/// <summary>
	/// Provides application-specific behavior to supplement the default Application class.
	/// </summary>
	//? ref - lifetime of these types is governed by automatic reference counting (not garbage collection) so that you never explicitly delete these objects.
	//? это фишка С++ виндовса, в .NET ref классы обычно понимаются на других языках
	//? sealed - class cannot serve as a base class. Почти все реф-классы являютсе sealed, ибо JavaScript не понимает наследие
	//! You declare a variable of a ref class by using the ^ (hat) operator, and you instantiate the object with the ref new keyword (=> is a pointer)
	ref class App sealed
	{
	protected:
		virtual void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ e) override;

	//? ???
	internal:
		App();

	private:
		void OnSuspending(Platform::Object^ sender, Windows::ApplicationModel::SuspendingEventArgs^ e);
		void OnNavigationFailed(Platform::Object ^sender, Windows::UI::Xaml::Navigation::NavigationFailedEventArgs ^e);
	};
}
