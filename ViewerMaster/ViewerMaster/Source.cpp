#include<windows.h>
#include<stdlib.h>
#include "resource.h"

//�E�B���h�E�n���h��
HWND hwnd;

//�C���X�^���X�n���h��
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

	winc.style = CS_HREDRAW | CS_VREDRAW;	//�c���̍ĕ`�������
	winc.lpfnWndProc = WndProc;	//�E�B���h�E�v���[�W���̖��O
	winc.cbClsExtra = winc.cbWndExtra = 0;	//�g��Ȃ�����0��NULL
	winc.hInstance = hInstance;	//�C���X�^���X�n���h��
	winc.hIcon = winc.hCursor = NULL;	//NULL�Ŗ��Ȃ��͂�
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//�w�i�𔒂ɐݒ�
	winc.lpszClassName = TEXT("VIEWERMASTER");	//�N���X�o�^��
	winc.lpszMenuName = TEXT("MENUID");	//	���j���[�o�^��

	if (!RegisterClass(&winc)) {
		return -1;
	}

	//�E�B���h�E�쐬
	hwnd = CreateWindow(
		TEXT("ViewerMaster"),
		TEXT("ViewerMaster"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100, 800, 600, NULL, NULL, hInstance, NULL
	);

	//�G���[�`�F�b�N
	int check;
	while (check = GetMessage(&msg, NULL, 0, 0)) {
		if (check == -1) {
			break;
		}
		DispatchMessage(&msg);
	}

	//�N���X���
	UnregisterClass("VIEWERMASTER", hinst);
}