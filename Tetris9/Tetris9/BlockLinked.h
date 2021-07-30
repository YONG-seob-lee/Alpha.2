#pragma once
#include "Block.h"
#include "BlockList.h"
#include "framework.h"

class BlockLinked
{
private:
	BlockList* MakeList;

public:
	BlockLinked();
	~BlockLinked();

	void Swap();		// ��嵥���Ͷ� �ι�°������ ����
	void RotateH();		// ��嵥���� �ð�������� ȸ��
	void CRotateH();	// ��嵥���� �ݽð�������� ȸ��
	void SetLinked();	// ���κ� ���� �ٽ� �߰��ϱ����
	void SetData(Block* DaTa);		// ����Ʈ���� ������ �����ϱ�
	int getBpart(int x, int y);
	Block* getB();
	Block* getNextB(int count);
};

