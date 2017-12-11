#include<windows.h>
#include<stdlib.h>
#include "resource.h"

//メッセージマクロ
#define MSG(m) {MessageBoxA(NULL, m, NULL, MB_OK);}

//グローバル定義
HINSTANCE hinst;
WNDCLASS wc;
HWND hwnd;
MSG msg;



//親ウィンドウプログラム
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_CREATE:
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wp)) {
		case Option:
			return 0;
		case Other:
			return 0;
		case Version:
			return 0;
		case Rule:
			return 0;
		}
	}
	return DefWindowProc(hwnd, msg, wp, lp);
}



//親ウィンドウの作成
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {

	/*    TODO:
	typedef struct _WNDCLASS { 
	UINT style; 
	WNDPROC lpfnWndProc; 
	int cbClsExtra; 
	int cbWndExtra; 
	HANDLE hInstance; 
	HICON hIcon; 
	HCURSOR hCursor; 
	HBRUSH hbrBackground; 
	LPCTSTR lpszMenuName; 
	LPCTSTR lpszClassName; 
	}
	*/

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = wc.cbWndExtra = NULL;
	wc.hInstance = hInstance;
	wc.hIcon = (HICON)LoadImage(hinst, "ICO_VM", IMAGE_ICON, 0, 0, LR_SHARED);
	wc.hCursor = NULL;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszClassName = "VIEWERMASTER";
	wc.lpszMenuName = "MENUID";

	if (!RegisterClass(&wc)) {
		MSG("エラー : クラス登録失敗");
		return -1;
	}

	/*    TODO:
	HWND CreateWindow(
	LPCTSTR lpClassName,    // RegisterClass関数で登録したクラス名
	LPCTSTR lpWindowName,    // ウィンドウの名前
	DWORD dwStyle,    // ウィンドウスタイル
	int x,    // ウィンドウの横方向の位置
	int y,    // ウィンドウの縦方向の位置
	int nWidth,    // ウィンドウの幅
	int nHeight,    // ウィンドウの高さ
	HWND hWndParent,    // 親ウィンドウまたはオーナーウィンドウのハンドル
	HMENU hMenu,    // メニューハンドルまたは子ウィンドウ ID
	HINSTANCE hInstance,    // アプリケーションインスタンスのハンドル
	LPVOID lpParam    // ウィンドウ作成データ
	);
	*/

	hwnd = CreateWindowA("VIEWERMASTER", "ViewerMaster", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100, 800, 600, NULL, NULL, hInstance, NULL
	);

	if (hwnd = NULL) {
		MSG("エラー : ウィンドウ作成失敗");
		return -1;
	}

	int check;    //エラーチェック用変数
	/*    TODO:
	BOOL GetMessage(
	LPMSG lpMsg,    // メッセージ情報
	HWND hWnd,    // ウィンドウのハンドル
	UINT wMsgFilterMin,    // 最初のメッセージ
	UINT wMsgFilterMax    // 最後のメッセージ
	);
	*/
	while (check = GetMessage(&msg, NULL, 0, 0)) {
		if (check == -1) {
			break;
		}
		DispatchMessage(&msg);
	}

	//クラス解放
	UnregisterClass("VIEWERMASTER", hinst);
	return 0;
}









