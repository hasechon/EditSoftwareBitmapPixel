#pragma once

#include "MainPage.g.h"

using namespace winrt::Windows::Graphics::Imaging;

namespace winrt::set_answer::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage() {};

        int32_t MyProperty();
        void MyProperty(int32_t value);


        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);

        SoftwareBitmap GetSoftwareBitmap(int nWidth, int nHeight);
        Windows::Foundation::IAsyncAction SetImageSourceFromSoftwareBitmap(SoftwareBitmap softwareBitmap, winrt::Windows::UI::Xaml::Controls::Image image);
    };
}

namespace winrt::set_answer::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
