#pragma once
#include <d2d1.h>
#include <wincodec.h>
#include "GameObject.h"

class GameObject;

class Graphic
{
private:
	static ID2D1Factory* pD2DFactory;
	static ID2D1HwndRenderTarget* pRT;
	static IWICBitmapDecoder *pDecoder;
	static IWICBitmapFrameDecode *pSource;
	static IWICStream *pStream;
	static IWICFormatConverter *pConverter;
	static IWICBitmapScaler *pScaler;
	static IWICImagingFactory *pIWICFactory;
	static ID2D1BitmapBrush *m_pBitmapBrush;

public:
	static void Init(HWND hWnd);
	static void Load_Bitmap(GameObject* obj, LPCWSTR name);
	static ID2D1Bitmap* Load_Bitmap(LPCWSTR name);
	static void Render(GameObject* obj);
	static void BeginDraw();
	static void EndDraw();
};

