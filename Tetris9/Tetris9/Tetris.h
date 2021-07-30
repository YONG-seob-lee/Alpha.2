#pragma once
#include "BlockLinked.h"
#include "framework.h"
#include "ScoreLinked.h"

class Tetris
{
private:
	BlockLinked* BLinked;
	Block* HoldBlock;		// Ȧ�� ���� ������ ����
	ScoreLinked* TopMember;	// A.I �ε��� ������ ����

	int PositionX;			// ��Ʈ������ ��������Ʈ x
	int PositionY;			// ��Ʈ������ ���� ����Ʈ y
	int MapData[24][12];
	int BlockData[4][4];	// �� ������ ����
	int checkMap[4][4];		// ���� �ʰ��� �浹�� Ȯ���� ���迭
	int HBlock[4][4];		// Ȧ��� �����͸� ������ ����
	int HoldFirst;		// Ȧ��� ���� ����ߴ��� Ȯ���ϱ� ���� ����
	int posX;				// �� �����Ϳ� �� �������� ��ǥ
	int posY;				// �� �����Ϳ� �� �������� ��ǥ
	int AI_posX;
	int HowManyRotate;

	// Handles
	HANDLES h_Block;
	HANDLES h_TransBlock;

	// Update
	UPDATE u_Block;
	UPDATE u_MAP;
	UPDATE u_AI;
	UPDATE u_CheckOver;
	UPDATE u_TransBlock;
	UPDATE u_Rotate;

public:
	Tetris();
	~Tetris();

	// init
	void LoadTetris(HANDLES h_Base);
	void InitAll(int x, int y);
	void InitPosition(int x, int y);
	void InitMap();
	void InitBlock();
	void InitCM();
	void SetBlock();			// �� ���� �� ��ġ �ʱ�ȭ

	// draw
	void DrawPersonal(HANDLES h_Base);
	void DrawSmall(HANDLES h_Base);

	void DrawMap(HANDLES h_Base, int size);
	void DrawBlock(HANDLES h_Base, int size);
	void DrawBottomBlock(HANDLES h_Base, int size);
	void DrawHoldBlock(HANDLES h_Base, int size);		// Ȧ���� ��� �׸��� �Լ�
	void DrawNextBlock(HANDLES h_Base, int size);
	void DrawSmallHoldBlock(HANDLES h_Base);
	void DrawSmallNextBlock(HANDLES h_Base);

	// check util
	bool CheckWall();
	void CheckLine();
	void CheckDeadLine();

	// block move
	void goLeft();
	void goRight();
	void goDown();
	void goStraightDown();
	void Rotate();
	void CRotate();
	void SwapBlock();
	void holdBlock();

	void UpdateAutoDown(int DownSpeed);
	void UpdateMap();
	BOOL UpdateGetOver();

	//////////// AI	/////////////
	void Update_AI();
	
	int GetScoreToCheckBottom();
	int CheckAllLine();

	void Load(HANDLES& h, LPCWSTR name, HANDLES h_Base);
	BOOL UpdateCheck(UPDATE& up, DWORD tick);
};

