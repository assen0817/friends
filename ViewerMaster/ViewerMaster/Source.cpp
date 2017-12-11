#include<windows.h>
#include<stdlib.h>
#include "resource.h"

//���b�Z�[�W�}�N��
#define MSG(m) {MessageBoxA(NULL, m, NULL, MB_OK);}

//�O���[�o����`
HINSTANCE hinst;
WNDCLASS wc;
HWND hwnd;
MSG msg;



//�e�E�B���h�E�v���O����
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



//�e�E�B���h�E�̍쐬
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
		MSG("�G���[ : �N���X�o�^���s");
		return -1;
	}

	/*    TODO:
	HWND CreateWindow(
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

	hwnd = CreateWindowA("VIEWERMASTER", "ViewerMaster", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100, 800, 600, NULL, NULL, hInstance, NULL
	);

	if (hwnd = NULL) {
		MSG("�G���[ : �E�B���h�E�쐬���s");
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









