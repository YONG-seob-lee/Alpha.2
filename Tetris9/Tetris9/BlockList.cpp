#include "BlockList.h"



BlockList::BlockList()
{
	ptr = NULL;
	ptrHead = NULL;
}

BlockList::~BlockList()
{
}

BlockRail * BlockList::CreateNode(Block* data)
{
	BlockRail* ptr = new BlockRail;		// ptr ������ ������ ������ ����
	ptr->data = data;		// ���θ��� �������� ������ �ʱ�ȭ
	ptr->pNode = NULL;		// ���θ��� �������� pNode �ʱ�ȭ
	return ptr;				// ������(�ּҰ�) ��ȯ
}

void BlockList::InsertAddHead(Block* data)
{
	BlockRail* ptr;
	if (ptrHead == NULL)	ptrHead = CreateNode(data);	// ���ptr �� ����Ű�°��� ������(NULL) ���� ��� ����

	else
	{
		ptr = CreateNode(data);		// ptr �����ϰ�
		ptr->pNode = ptrHead;		// ptr�� ��尡 ptrHead �����͸� ����Ű�� �ϰ�
		ptrHead = ptr;				// ptrHead �����͸� ptr�� ����Ű�°����� �ű�
	}
}

void BlockList::InsertAddTail(Block* data)
{
	BlockRail* ptr;

	if (ptrHead == NULL)	ptrHead = CreateNode(data);	// ���ptr �� ����Ű�°��� ������(NULL) ���� ��� ����

	else
	{
		ptr = ptrHead;						// �ϴ� ptr�����͸� Head �����ͷ� �Űܵΰ�
		while (ptr->pNode != NULL)			// ptr�� pNode�� ���� ����� ���������� null �� �Ǵ°����� �̵�
		{
			ptr = ptr->pNode;				// �� �̵��� �ڿ� ������ ��带 ptr�����Ϳ� ����
		}
		ptr->pNode = CreateNode(data);				// ���� �Ŀ� ptr ��� ����
	}
}

void BlockList::DeleteHead()
{
	BlockRail* ptr;
	BlockRail* ptr2;
	if (ptrHead == NULL)	return;

	ptr = ptr2 = ptrHead;		// ptr �ʱ�ȭ
	ptr2 = ptr2->pNode;			// ptr2 �� ĭ �����̱�
	ptrHead = ptr2;				// ptrHead �� ĭ �����̱�
	delete ptr;
}

void BlockList::SwapNode()
{
	BlockRail* ptr;
	BlockRail* ptr2;
	ptr = ptr2 = ptrHead;	//ptr�� �ʱ�ȭ
	ptr2 = ptr2->pNode;	// ptr2 ��ĭ ����
	ptr->pNode = ptr2->pNode;	// ptr�� ��尡 ptr2�� ����Ű�� �����ͷ� ����
	ptr2->pNode = ptr;	// ptr2�� ��带 ���� ��带 ����Ű�� ����
	ptrHead = ptr2;	// ��� �ű��
}

void BlockList::DelNode()
{
	BlockRail* ptr;
	for (ptr = ptrHead; ptrHead != NULL; ptr = ptrHead)
	{
		ptrHead = ptrHead->pNode;
		if (ptr != NULL)
			delete ptr;
	}
}

void BlockList::SetData(Block* DaTa)
{
	ptrHead->data = DaTa;
}

Block * BlockList::getBlock()
{
	BlockRail* ptr;
	ptr = ptrHead;
	return ptr->data;
}

Block * BlockList::getNextBlock(int count)
{
	BlockRail* ptr;
	ptr = ptrHead;
	for (int i = 0; i < count; i++)
	{
		ptr = ptr->pNode;
	}
	return ptr->data;
}
