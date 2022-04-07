#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType val;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;
//typedef int SLTDataType;
//typedef struct ListNode
//{
//	SLTDataType data;
//	struct ListNode* next;
//	struct ListNode* prev;
//}ListNode;
// 
//��ʼ��˫������
ListNode* ListInit(ListNode* phead);
void ListDestroy(ListNode* phead);
//˫������β��
void ListPushBack(ListNode* phead, LTDataType x);
void ListPopBack(ListNode* phead);
void ListPrint(ListNode* phead);
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);
ListNode* ListFind(ListNode* phead, LTDataType x);
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);
//void ListErase(ListNode* phead, ListNode* pos);
