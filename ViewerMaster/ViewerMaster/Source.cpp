#include<windows.h>
#include<stdlib.h>
#include "resource.h"

//ウィンドウハンドル
HWND hwnd;

//インスタンスハンドル
HINSTANCE hinst;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wp, lp);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	WNDCLASS winc;

	winc.style = CS_HREDRAW | CS_VREDRAW;	//縦横の再描画をする
	winc.lpfnWndProc = WndProc;	//ウィンドウプロージャの名前
	winc.cbClsExtra = winc.cbWndExtra = 0;	//使わないから0かNULL
	winc.hInstance = hInstance;	//インスタンスハンドル
	winc.hIcon = winc.hCursor = NULL;	//NULLで問題ないはず
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//背景を白に設定
	winc.lpszClassName = TEXT("VIEWERMASTER");	//クラス登録名
	winc.lpszMenuName = TEXT("MENUID");	//	メニュー登録名

	if (!RegisterClass(&winc)) {
		return -1;
	}

	//ウィンドウ作成
	hwnd = CreateWindow(
		TEXT("ViewerMaster"),
		TEXT("ViewerMaster"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100, 800, 600, NULL, NULL, hInstance, NULL
	);

	//エラーチェック
	int check;
	while (check = GetMessage(&msg, NULL, 0, 0)) {
		if (check == -1) {
			break;
		}
		DispatchMessage(&msg);
	}

	//クラス解放
	UnregisterClass("VIEWERMASTER", hinst);
}