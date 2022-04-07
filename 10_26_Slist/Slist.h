#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int SLTDataType;

typedef struct SlistNode
{
	SLTDataType data;
	struct SlistNode* next;

}SLTNode;

void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPrint(SLTNode* phead);
void SListPopFront(SLTNode** pphead);