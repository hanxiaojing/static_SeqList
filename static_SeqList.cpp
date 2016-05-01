#define _CRT_SECURE_NO_WARNINGS 1
//��̬˳���
#include<iostream>
using namespace std;
#include<assert.h>

#define MAXSIZE 100
typedef int DataType;

typedef struct SeqList
{
	DataType _array[MAXSIZE];
	size_t _size;
}SeqList;

void InitSeqList(SeqList* pSeq)
{
	assert(pSeq);
	memset(pSeq->_array,0, sizeof(DataType)*MAXSIZE);	
	pSeq->_size = 0;
}


void PushBack(SeqList* pSeq,DataType x)
{
	assert(pSeq->_size< MAXSIZE);
	pSeq->_array[pSeq->_size++] = x;
}


void PopBack(SeqList* pSeq)
{
	assert(pSeq->_size>0);
	--pSeq->_size;
}


void PushFront(SeqList* pSeq,DataType x)
{
	assert(pSeq->_size < MAXSIZE);
	for (int i = pSeq->_size-1; i >= 0; i--)
	{
		pSeq->_array[i+1] = pSeq->_array[i];
	}
	++pSeq->_size;
	pSeq->_array[0] = x;
}


void PopFront(SeqList* pSeq)
{
	assert(pSeq->_size > 0);
	for (int i = 1; i < pSeq->_size; i++)
	{
		pSeq->_array[i - 1] = pSeq->_array[i];
	}
	--pSeq->_size;
}

void Insert(SeqList* pSeq,int pos, DataType x)
{
	assert(pos >= 0);
	assert(pSeq->_size < MAXSIZE);
	for (int i = pSeq->_size - 1; i >= pos; i--)
	{
		pSeq->_array[i+1] = pSeq->_array[i];
	}
	++pSeq->_size;
	pSeq->_array[pos] = x;
}


int Find(SeqList*pSeq,DataType x)
{
	int i = 0;
	for (i = 0; i < pSeq->_size; i++)
	{
		if (pSeq->_array[i] == x)
		{
			return i;
		}
	}
	return -1;
}


void Erase(SeqList* pSeq, int pos)
{
	assert(pos > 0);
	for (int i = pos; i < pSeq->_size; i++)
	{
		pSeq->_array[i] = pSeq->_array[i + 1];
	}
	--pSeq->_size;
}


void PrintSeqList(SeqList* pSeq)
{
	if (pSeq->_size == 0)
	{
		printf("��ǰ˳���Ϊ�գ�");
		return;
	}
	for (int i = 0; i < pSeq->_size; i++)
	{
		printf("%d  ", pSeq->_array[i]);
	}
	printf("\n");
}


void Test()
{
	SeqList List;
	InitSeqList(&List);
	PushBack(&List,1);
	PushBack(&List, 2);
	PushBack(&List, 3);
	PushBack(&List, 4);
	PushBack(&List, 5);
	PushBack(&List, 6);
	PrintSeqList(&List);

	PopBack(&List);
	PopBack(&List);
	PopBack(&List);
	PrintSeqList(&List);

	PushFront(&List,0);
	PushFront(&List, -1); 
	PushFront(&List, -2);
	PrintSeqList(&List);

	PopFront(&List);
	PopFront(&List);
	PopFront(&List);
	PrintSeqList(&List);

	int ret = Find(&List, 2);
	printf("%d\n", ret);

	Erase(&List, 1);
	PrintSeqList(&List);

	Insert(&List, 1, 2);
	PrintSeqList(&List);

}


int main()
{
	Test();
	system("pause");
	return 0;
}