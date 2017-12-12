#include<windows.h>
#include<stdlib.h>
#include "resource.h"

#define MSG(m) {MessageBoxA(hwnd, m, NULL, MB_OK);}
#define MSGnotice(m) {MessageBox(hwnd, m, TEXT("通知"), MB_OK);}
#define btn_L_cnct 10001
#define btn_L_discnct 10002
#define btn_T_cnct 10003
#define btn_T_discnct 10004
#define btn_Y_cnct 10005
#define btn_Y_discnct 10006

//ハンドル
HINSTANCE hinst;
WNDCLASSEX wcex;
HWND hwnd;
MSG msg;

//ボタンハンドル
static HWND hwnd_btn_L_cnct, hwnd_btn_L_discnct;
static HWND hwnd_btn_T_cnct, hwnd_btn_T_discnct;
static HWND hwnd_btn_Y_cnct, hwnd_btn_Y_discnct;



//親ウィンドウプログラム
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
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
		case btn_L_cnct:
			MSGnotice("接続します");
			return 0;
		case btn_L_discnct:
			MSGnotice("切断しました");
			return 0;
		case btn_T_cnct:
			MSGnotice("接続します");
			return 0;
		case btn_T_discnct:
			MSGnotice("切断しました");
			return 0;
		case btn_Y_cnct:
			MSGnotice("接続します");
			return 0;
		case btn_Y_discnct:
			MSGnotice("切断しました");
			return 0;
		}
	}
	return DefWindowProc(hwnd, msg, wp, lp);
}



//親ウィンドウの作成
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {

	/*    TODO:
	typedef struct _WNDCLASS { 
	UINT cbSize;
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
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = wcex.cbWndExtra = NULL;
	wcex.hInstance = hInstance;
	wcex.hIcon = (HICON)LoadImage(hinst, "ICO_VM", IMAGE_ICON, 0, 0, LR_SHARED);
	wcex.hCursor = NULL;
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.lpszClassName = TEXT("VIEWERMASTER");
	wcex.lpszMenuName = TEXT("MENUID");
	wcex.hIconSm = NULL;

	if (!RegisterClassEx(&wcex)) {
		MSG("エラー : クラス登録失敗");
		return 0;
	}

	/*    TODO:
	HWND CreateWindowEX(
	DWORD dwExStyle,    //拡張ウィンドウスタイル
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

	hwnd = CreateWindowEx(WS_EX_LEFT, TEXT("VIEWERMASTER"), TEXT("ViewerMaster"), WS_VISIBLE | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX,
		100, 100, 800, 600, NULL, NULL, hinst, NULL
	);

	//ボタン
	hwnd_btn_L_cnct = CreateWindowEx(WS_EX_LEFT, TEXT("button"), TEXT("接続"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		700, 10, 40, 20, hwnd, (HMENU)btn_L_cnct, hInstance, NULL
	);

	hwnd_btn_L_discnct = CreateWindowEx(WS_EX_LEFT, TEXT("button"), "切断", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		745, 10, 40, 20, hwnd, (HMENU)btn_L_discnct, hInstance, NULL
	);

	hwnd_btn_T_cnct = CreateWindowEx(WS_EX_LEFT, TEXT("button"), "接続", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		700, 40, 40, 20, hwnd, (HMENU)btn_T_cnct, hInstance, NULL
	);

	hwnd_btn_T_discnct = CreateWindowEx(WS_EX_LEFT, TEXT("button"), "切断", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		745, 40, 40, 20, hwnd, (HMENU)btn_T_discnct, hInstance, NULL
	);

	hwnd_btn_Y_cnct = CreateWindowEx(WS_EX_LEFT, TEXT("button"), "接続", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		700, 70, 40, 20, hwnd, (HMENU)btn_Y_cnct, hInstance, NULL
	);

	hwnd_btn_Y_discnct = CreateWindowEx(WS_EX_LEFT, TEXT("button"), "切断", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		745, 70, 40, 20, hwnd, (HMENU)btn_Y_discnct, hInstance, NULL
	);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	//エラーチェック
	if (!hwnd) {
		MSG("エラー : ウィンドウ作成失敗");
		return -1;
	}

	if (!hwnd_btn_L_cnct) {
		MSG("エラー : ボタン作成失敗");
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









