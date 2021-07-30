#pragma once
#include "TetrisHandler.h"

class TetrisManager
{
private:
	int GameState;
	int AttackLine;

	TetrisHandler handle;
	FRAME Frame;

	// HANDLES
	HANDLES h_Base;
	HANDLES h_TitleBG[TITLE_BG_FRAME];			// Ÿ��Ʋ ���
	HANDLES h_newBG;							// �� Ÿ��Ʋ ��� �����̱�
	HANDLES h_Flash;							// �� Ÿ��Ʋ ������� �ٲ�� ����
	HANDLES h_PressBig;							// ū ��ư
	HANDLES h_PressSmall;						// ���� ��ư
	HANDLES h_Alpha;
	HANDLES h_Fade;

	// UPDATE
	UPDATE u_TitleBG;							// Ÿ��Ʋ ��� �ִϸ��̼��� ���� ������Ʈ
	UPDATE u_NewBG;								// ƽ �����̸� ���� �߰�
	UPDATE u_Flash;								// ���� �ִϸ��̼�
	UPDATE u_PressBig;							// ���� ��ư���� ū ��ư���� ��ȯ�� ���� ������Ʈ
	UPDATE u_Fade;

	// UTIL
	RECT m_rtClient;							// ũ�⸦ ���� �׷���

public:
	TetrisManager();
	~TetrisManager();

	// Basic
	void GameLoop(HDC hdc);		// ���� ������ �Ѱ��ϴ� ����
	void DrawAll(HDC hdc);		// ���� �׸��� �Ѱ��ϴ� �Լ�
	void Update();				// ���� ������Ʈ�� �Ѱ��ϴ� �Լ�
	void setGameState();		// 

	// Init
	void InitFirst();				// ���� ���ʷ� �ʱ�ȭ�ϴ� �Լ�
	void InitResource();			// Bace.dc ���� ���� �Լ�
	void InitData();				// ���ҽ��� ������ ����������� �ʱ�ȭ �ϴ� �Լ�
	void InitResourceTitleBG();		// Ÿ��Ʋ��� ���ҽ� �ʱ�ȭ

	// Draw
	void DrawTitle();			// Ÿ��Ʋ ���
	void DrawNewBG();			// �� Ÿ��Ʋ
	void DrawFlash();			// ����
	void DrawPressBig();		// ū ��ư
	void DrawPressSmall();		// ���� ��ư
	void DrawFade();
	void DrawBlockAlpha();

	// Update
	void UpdateTitle();
	void UpdateNewBG();
	void UpdateFlash();
	void UpdatePressBig();
	void GetOver();
	void UpdateFade();


	// Util
	void Load(HANDLES& h, LPCWSTR name);
	void InitTick(UPDATE& up, int mode = 0);	// '0' �̸� all, '1' �̸� move, '2' �̸� animate
	RECT& GetRect();
	void GetFrame();
	BOOL UpdateCheck(UPDATE& up, DWORD tick);
	HANDLES getbase();
	BOOL KeyCheck(WPARAM wparam);

};

