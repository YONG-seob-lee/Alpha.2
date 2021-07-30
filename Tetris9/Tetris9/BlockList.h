#pragma once
#include "framework.h"
#include "Block.h"

class BlockList
{
private:
	BlockRail* CreateNode(Block* data);
	BlockRail* ptr;
	BlockRail* ptrHead;

public:
	BlockList();
	~BlockList();

	void InsertAddHead(Block* data);
	void InsertAddTail(Block* data);
	void DeleteHead();
	void SwapNode();		// ���� �ι�°���� �ٲٴ� �����Լ�
	void DelNode();
	void SetData(Block* DaTa);

	Block* getBlock();	// �� ����(���) �� �ִ� ������ ������ �Լ�
	Block* getNextBlock(int count);
};

