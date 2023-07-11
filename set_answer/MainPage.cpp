#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Media;

namespace winrt::set_answer::implementation
{
    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));

        SoftwareBitmap softwareBitmap = GetSoftwareBitmap(200, 200);
        SetImageSourceFromSoftwareBitmap(softwareBitmap, Img1());
    }

    SoftwareBitmap MainPage::GetSoftwareBitmap(int nWidth, int nHeight)
    {
        SoftwareBitmap softwareBitmap(BitmapPixelFormat::Bgra8, nWidth, nHeight, BitmapAlphaMode::Premultiplied);
        BitmapBuffer buffer = softwareBitmap.LockBuffer(BitmapBufferAccessMode::Write);
        uint8_t* pixels = buffer.CreateReference().data();
        int nPixelsSize = nWidth * nHeight * 4;
        for (int i = 0; i < nPixelsSize; i += 4)
        {
            pixels[i] = 255;
            pixels[i + 1] = 0;
            pixels[i + 2] = 0;
            pixels[i + 3] = 255; // add
        }
        return softwareBitmap;
    }

    Windows::Foundation::IAsyncAction MainPage::SetImageSourceFromSoftwareBitmap(SoftwareBitmap softwareBitmap, winrt::Windows::UI::Xaml::Controls::Image image)
    {
        Imaging::SoftwareBitmapSource bitmapSource;
        co_await bitmapSource.SetBitmapAsync(softwareBitmap);
        image.Source(bitmapSource);
    }
}
