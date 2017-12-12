#include<windows.h>
#include<stdlib.h>
#include "resource.h"

#define MSG(m) {MessageBoxA(hwnd, m, NULL, MB_OK);}
#define MSGnotice(m) {MessageBox(hwnd, m, TEXT("�ʒm"), MB_OK);}
#define btn_L_cnct 10001
#define btn_L_discnct 10002
#define btn_T_cnct 10003
#define btn_T_discnct 10004
#define btn_Y_cnct 10005
#define btn_Y_discnct 10006

//�n���h��
HINSTANCE hinst;
WNDCLASSEX wcex;
HWND hwnd;
MSG msg;

//�{�^���n���h��
static HWND hwnd_btn_L_cnct, hwnd_btn_L_discnct;
static HWND hwnd_btn_T_cnct, hwnd_btn_T_discnct;
static HWND hwnd_btn_Y_cnct, hwnd_btn_Y_discnct;



//�e�E�B���h�E�v���O����
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
			MSGnotice("�ڑ����܂�");
			return 0;
		case btn_L_discnct:
			MSGnotice("�ؒf���܂���");
			return 0;
		case btn_T_cnct:
			MSGnotice("�ڑ����܂�");
			return 0;
		case btn_T_discnct:
			MSGnotice("�ؒf���܂���");
			return 0;
		case btn_Y_cnct:
			MSGnotice("�ڑ����܂�");
			return 0;
		case btn_Y_discnct:
			MSGnotice("�ؒf���܂���");
			return 0;
		}
	}
	return DefWindowProc(hwnd, msg, wp, lp);
}



//�e�E�B���h�E�̍쐬
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
		MSG("�G���[ : �N���X�o�^���s");
		return 0;
	}

	/*    TODO:
	HWND CreateWindowEX(
	DWORD dwExStyle,    //�g���E�B���h�E�X�^�C��
	LPCTSTR lpClassName,    // RegisterClass�֐��œo�^�����N���X��
	LPCTSTR lpWindowName,    // �E�B���h�E�̖��O
	DWORD dwStyle,    // �E�B���h�E�X�^�C��
	int x,    // �E�B���h�E�̉������̈ʒu
	int y,    // �E�B���h�E�̏c�����̈ʒu
	int nWidth,    // �E�B���h�E�̕�
	int nHeight,    // �E�B���h�E�̍���
	HWND hWndParent,    // �e�E�B���h�E�܂��̓I�[�i�[�E�B���h�E�̃n���h��
	HMENU hMenu,    // ���j���[�n���h���܂��͎q�E�B���h�E ID
	HINSTANCE hInstance,    // �A�v���P�[�V�����C���X�^���X�̃n���h��
	LPVOID lpParam    // �E�B���h�E�쐬�f�[�^
	);
	*/

	hwnd = CreateWindowEx(WS_EX_LEFT, TEXT("VIEWERMASTER"), TEXT("ViewerMaster"), WS_VISIBLE | WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX,
		100, 100, 800, 600, NULL, NULL, hinst, NULL
	);

	//�{�^��
	hwnd_btn_L_cnct = CreateWindowEx(WS_EX_LEFT, TEXT("button"), TEXT("�ڑ�"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		700, 10, 40, 20, hwnd, (HMENU)btn_L_cnct, hInstance, NULL
	);

	hwnd_btn_L_discnct = CreateWindowEx(WS_EX_LEFT, TEXT("button"), "�ؒf", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		745, 10, 40, 20, hwnd, (HMENU)btn_L_discnct, hInstance, NULL
	);

	hwnd_btn_T_cnct = CreateWindowEx(WS_EX_LEFT, TEXT("button"), "�ڑ�", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		700, 40, 40, 20, hwnd, (HMENU)btn_T_cnct, hInstance, NULL
	);

	hwnd_btn_T_discnct = CreateWindowEx(WS_EX_LEFT, TEXT("button"), "�ؒf", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		745, 40, 40, 20, hwnd, (HMENU)btn_T_discnct, hInstance, NULL
	);

	hwnd_btn_Y_cnct = CreateWindowEx(WS_EX_LEFT, TEXT("button"), "�ڑ�", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		700, 70, 40, 20, hwnd, (HMENU)btn_Y_cnct, hInstance, NULL
	);

	hwnd_btn_Y_discnct = CreateWindowEx(WS_EX_LEFT, TEXT("button"), "�ؒf", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		745, 70, 40, 20, hwnd, (HMENU)btn_Y_discnct, hInstance, NULL
	);

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	//�G���[�`�F�b�N
	if (!hwnd) {
		MSG("�G���[ : �E�B���h�E�쐬���s");
		return -1;
	}

	if (!hwnd_btn_L_cnct) {
		MSG("�G���[ : �{�^���쐬���s");
		return -1;
	}

	int check;    //�G���[�`�F�b�N�p�ϐ�

	/*    TODO:
	BOOL GetMessage(
	LPMSG lpMsg,    // ���b�Z�[�W���
	HWND hWnd,    // �E�B���h�E�̃n���h��
	UINT wMsgFilterMin,    // �ŏ��̃��b�Z�[�W
	UINT wMsgFilterMax    // �Ō�̃��b�Z�[�W
	);
	*/

	while (check = GetMessage(&msg, NULL, 0, 0)) {
		if (check == -1) {
			break;
		}
		DispatchMessage(&msg);
	}

	//�N���X���
	UnregisterClass("VIEWERMASTER", hinst);
	return 0;
}









