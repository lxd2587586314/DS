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
//打印链表
void SListPrint(SLTNode* phead);
//尾插
void SListPushBack(SLTNode** pphead, SLTDataType x);
//尾删
void SListPopBack(SLTNode** pphead);
//头插
void SListPushFront(SLTNode** pphead, SLTDataType x);
//头删
void SListPopFront(SLTNode** pphead);

SLTNode* SListFind(SLTNode* phead, SLTDataType x);
// 在pos位置之前去插入一个节点
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
void SListErase(SLTNode** pphead, SLTNode* pos);
void SListDestory(SLTNode** pphead);

// void SListInsert(SLTNode* phead, int pos, SLTDateType x);
// void SListErase(SLTNode** pphead, int pos);


