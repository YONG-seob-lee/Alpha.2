#include "ScoreLinked.h"

TopScore * ScoreLinked::CreateNode(int data)
{
	TopScore* ptr = new TopScore;		// ptr ������ ������ ������ ����
	ptr->data = data;		// ���θ��� �������� ������ �ʱ�ȭ
	ptr->pNode = NULL;		// ���θ��� �������� pNode �ʱ�ȭ
	return ptr;
}

ScoreLinked::ScoreLinked()
{
	ptr = NULL;
	ptrHead = NULL;
}

ScoreLinked::~ScoreLinked()
{
	DelNode();
}

void ScoreLinked::InsertAddHead(int data)
{
	TopScore* ptr;
	if (ptrHead == NULL)	ptrHead = CreateNode(data);	// ���ptr �� ����Ű�°��� ������(NULL) ���� ��� ����

	else
	{
		ptr = CreateNode(data);		// ptr �����ϰ�
		ptr->pNode = ptrHead;		// ptr�� ��尡 ptrHead �����͸� ����Ű�� �ϰ�
		ptrHead = ptr;				// ptrHead �����͸� ptr�� ����Ű�°����� �ű�
	}
}

void ScoreLinked::InsertAddTail(int data)
{
	TopScore* ptr;

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

int ScoreLinked::GetScoreData(int index)
{
	TopScore* ptr;
	ptr = ptrHead;
	for (int i = 0; i < index; i++)	 // �ε��� ��ŭ
	{
		ptr = ptr->pNode;		// �̵�
	}
	return ptr->data;		// �ε�����ŭ �̵��� ���� ������ ����
}

void ScoreLinked::DelNode()
{
	TopScore* ptr;
	for (ptr = ptrHead; ptrHead != NULL; ptr = ptrHead)
	{
		ptrHead = ptrHead->pNode;
		if (ptr != NULL)
			delete ptr;
	}
}
