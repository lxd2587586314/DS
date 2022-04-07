#pragma once
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h> 
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;
//��ӡ����
void SListPrint(SLTNode* phead);
//β��
void SListPushBack(SLTNode** pphead, SLTDataType x);
//βɾ
void SListPopBack(SLTNode** pphead);
//ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x);
//ͷɾ
void SListPopFront(SLTNode** pphead);

SLTNode* SListFind(SLTNode* phead, SLTDataType x);
// ��posλ��֮ǰȥ����һ���ڵ�
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
void SListErase(SLTNode** pphead, SLTNode* pos);
void SListDestory(SLTNode** pphead);

// void SListInsert(SLTNode* phead, int pos, SLTDateType x);
// void SListErase(SLTNode** pphead, int pos);


