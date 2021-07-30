#include "BlockLinked.h"



BlockLinked::BlockLinked()
{
	MakeList = new BlockList;
	Block* Blok[6];

	Blok[0] = new Block;
	MakeList->InsertAddHead(Blok[0]);
	for (int i = 1; i < 6; i++)
	{
		Blok[i] = new Block;
		MakeList->InsertAddTail(Blok[i]);
	}
}

BlockLinked::~BlockLinked()
{
	MakeList->DelNode();
}
void BlockLinked::Swap()
{
	MakeList->SwapNode();
}

void BlockLinked::RotateH()
{
	MakeList->getBlock()->rotate();
}

void BlockLinked::CRotateH()
{
	MakeList->getBlock()->reverserotate();
}

void BlockLinked::SetLinked()
{
	Block* Blok;
	Blok = new Block;
	MakeList->DeleteHead();		// �Ӹ� �����
	MakeList->InsertAddTail(Blok);	// ���� �ϳ� �����ϱ�
}

void BlockLinked::SetData(Block* DaTa)
{
	MakeList->SetData(DaTa);
}

int BlockLinked::getBpart(int x, int y)
{
	return MakeList->getBlock()->getBpart(x, y);
}

Block * BlockLinked::getB()
{
	return MakeList->getBlock();
}

Block * BlockLinked::getNextB(int count)
{
	return MakeList->getNextBlock(count);
}
