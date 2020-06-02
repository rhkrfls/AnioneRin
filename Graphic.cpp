#include "stdafx.h"
#include "Graphic.h"

ID2D1Factory*			Graphic::pD2DFactory = NULL;
ID2D1HwndRenderTarget*	Graphic::pRT = NULL;
IWICBitmapDecoder*		Graphic::pDecoder = NULL;
IWICBitmapFrameDecode*	Graphic::pSource = NULL;
IWICStream*				Graphic::pStream = NULL;
IWICFormatConverter*	Graphic::pConverter = NULL;
IWICBitmapScaler*		Graphic::pScaler = NULL;
IWICImagingFactory*		Graphic::pIWICFactory;
ID2D1BitmapBrush*		Graphic::m_pBitmapBrush;

void Graphic::Init(HWND hWnd)
{
	D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED,
		&pD2DFactory
	);

	// Obtain the size of the drawing area.
	RECT rc;
	GetClientRect(hWnd, &rc);

	// Create a Direct2D render target			
	pD2DFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(
			hWnd,
			D2D1::SizeU(
				rc.right - rc.left,
				rc.bottom - rc.top)
		),
		&pRT
	);

	CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pIWICFactory));
}

void Graphic::Load_Bitmap(GameObject* obj, LPCWSTR name)
{
	pIWICFactory->CreateDecoderFromFilename(
		name,
		NULL,
		GENERIC_READ,
		WICDecodeMetadataCacheOnLoad,
		&pDecoder
	);

	pDecoder->GetFrame(0, &pSource);
	pIWICFactory->CreateFormatConverter(&pConverter);

	pConverter->Initialize(
		pSource,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		NULL,
		0.f,
		WICBitmapPaletteTypeMedianCut
	);

	pRT->CreateBitmapFromWicBitmap(
		pConverter,
		NULL,
		&obj->pBitmap
	);
}

ID2D1Bitmap* Graphic::Load_Bitmap(LPCWSTR name)
{
	ID2D1Bitmap* TempBitmap;
	pIWICFactory->CreateDecoderFromFilename(
		name,
		NULL,
		GENERIC_READ,
		WICDecodeMetadataCacheOnLoad,
		&pDecoder
	);

	pDecoder->GetFrame(0, &pSource);
	pIWICFactory->CreateFormatConverter(&pConverter);

	pConverter->Initialize(
		pSource,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		NULL,
		0.f,
		WICBitmapPaletteTypeMedianCut
	);

	pRT->CreateBitmapFromWicBitmap(
		pConverter,
		NULL,
		&TempBitmap
	);

	return TempBitmap;
}

void Graphic::Render(GameObject* obj)
{
	if (obj->exist) 
	{

	pRT->CreateBitmapBrush(
		obj->pBitmap,
		&m_pBitmapBrush
	);

	float width = obj->pBitmap->GetPixelSize().width;
	float height = obj->pBitmap->GetPixelSize().height;

	pRT->SetTransform(D2D1::Matrix3x2F::Scale(obj->scale.x, obj->scale.y, D2D1::Point2F(width / 2, height / 2))*
		D2D1::Matrix3x2F::Rotation(obj->angle, D2D1::Point2F(width / 2, height / 2))*
			D2D1::Matrix3x2F::Translation(obj->position.x - width / 2, obj->position.y - height / 2));

	pRT->FillRectangle(D2D1::RectF(0, 0, width, height), m_pBitmapBrush);
	}
}

void Graphic::BeginDraw()
{
	pRT->BeginDraw();
	pRT->Clear();
}

void Graphic::EndDraw()
{
	pRT->EndDraw();
}
