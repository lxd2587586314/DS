#include "List.h"
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->val = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
ListNode* ListInit(ListNode* phead)
{
	//开辟一个头节点，初始化为双向带头循环链表
	phead = (ListNode*)malloc(sizeof(ListNode));
	if (phead == NULL)
	exit(-1);
	phead->prev = phead;
	phead->next = phead;
	return phead;
}

void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);
	//ListNode* newnode = BuyListNode(x);
	////记录尾指针
	//ListNode* tail = phead->prev;
	////修改链接关系
	//tail->next = newnode;
	////newnode->prev = phead;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;
	ListInsert(phead, x);
}
//phead    newnode

void ListPopBack(ListNode* phead)
{
	assert(phead);
	//链表为空
	assert(phead->next != phead);
	/*ListNode* tail = phead->prev;
	ListNode* tailprev = tail->prev;

	free(tail);
	tail = NULL;
	tailprev->next = phead;
	phead->prev = tailprev;*/
	ListErase(phead, phead->prev);
}

void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);
	/*ListNode* newnode = BuyListNode(x);
	ListNode* next = phead->next;

	newnode->next = next;
	next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;*/
	ListInsert(phead->next, x);
}

void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	/*ListNode* next = phead->next;
	ListNode* nextNext = next->next;
	nextNext->prev = phead;
	phead->next = nextNext;
	free(next);
	next = NULL;*/
	ListErase(phead, phead->next);
}
//查找位置
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
//pos位置之前的插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* posprev = pos->prev;
	posprev->next = newnode;
	newnode->prev = posprev;
	newnode->next = pos;
	pos->prev = newnode;
}
////pos位置之前的删除
//void ListErase(ListNode* phead, ListNode* pos)
//{
//	assert(phead);
//	assert(pos);
//	assert(pos->prev != phead);
//	assert(pos != phead);
//	ListNode* posPrev = pos->prev;
//	ListNode* posNext = pos->next;
//
//	posPrev->next = posNext;
//	posNext->prev = posPrev;
//	free(pos);
//	pos = NULL;
//}

//pos位置之前的删除
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	posPrev->next = posNext;
	posNext->prev = posPrev;

	free(pos);
	pos = NULL;
}

void ListDestroy(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;

	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = NULL;
		cur = next;
	}
	free(phead);
	phead = NULL;
}














ListNode* ListNodeInit()
{
	ListNode* phead = (ListNode*)malloc(sizeof(ListNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//void ListPopBack(ListNode* phead)
//{
//	assert(phead);
//	//assert(phead->next != phead);
//	ListNode* cur = phead;
//	ListNode* pop = cur->prev;
//	cur->prev = pop->prev;
//	pop->next = cur;
//	free(pop);
//	pop = NULL;
//}

void ListNodePopBack(ListNode* phead)
{
	//assert(phead);
	//assert(phead->next != phead);
	//ListNode* Next = phead->prev;
	//phead->prev = Next->prev;
	//Next->prev->next = phead;
	//free(Next);  
	//Next = NULL;
	assert(phead);
	assert(phead->next != phead);
	ListNode* tail = phead->prev;
	ListNode* tailprev = tail->prev;
	phead->prev = tailprev;
	tailprev->next = phead;
	free(tail);
	tail = NULL;
}

