
#include "SList.h"
struct ListNode2 {
	int val;
	struct ListNode* next;

};

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	// write code here
	struct ListNode* slow = pListHead;
	struct ListNode* fast = pListHead;
	while (k--)
	{
		if (fast == NULL)
			return NULL;
		//fast = fast->next;
	}
	while (fast != NULL)
	{
		//fast = fast->next;
		//slow = slow->next;
	}
	return slow;
}
// Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode* next;
};


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	if (list1 == NULL)
		return list2;
	if (list2 == NULL)
		return list1;
	struct ListNode* head = NULL, * tail = NULL;
	if (list1->val < list2->val)
	{
		head = tail = list1;
		list1 = list1->next;
	}
	else
	{
		head = tail = list2;
		list2 = list2->next;

	}
	while (list1 && list2)
	{
		if (list1->val < list2->val)
		{
			tail->next = list1;
			tail = list1;
			list1 = list1->next;
		}
		else
		{
			tail->next = list2;
			tail = list2;
			list2 = list2->next;

		}

	}
	if (list1)
	{
		tail->next = list1;
	}
	if (list2)
	{
		tail->next = list2;
	}
	return head;
}


//Definition for singly-linked list.
struct ListNode1 {
	int val;
	struct ListNode* next;
};



struct ListNode* reverseList(struct ListNode* head) {

	/*
		struct ListNode* prev = NULL;
		struct ListNode* cur = head;
		while(cur)
		{
			struct ListNode* next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;

		}
		return prev;*/
	if (head == NULL)
		return NULL;
	struct ListNode* newnode = NULL;
	struct ListNode* cur = head;
	struct ListNode* next = cur->next;
	while (cur)
	{
		//ͷ��
		cur->next = newnode;
		newnode = cur;
		//����
		cur = next;
		if (next)
			next = next->next;
	}
	return newnode;
	/*if(head == NULL)
	return NULL;
	struct ListNode* prev = NULL;
	struct ListNode* cur = head;
	struct ListNode* next = cur->next;
	while(cur)
	{
		//��ת
		cur->next = prev;
		//����
		prev = cur;
		cur = next;
		if(next)
		next = next->next;
	}
	return prev;*/
}

void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
SLTNode* BuyListNode(SLTDataType x)
{
	// 1M = 1024KB = 1024 * 1024 Byte
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	/*SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}*/
	SLTNode* newnode = BuyListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;

	}
}

//βɾ
void SListPopBack(SLTNode** pphead)
{
	// �����һ��
	/*if (*pphead == NULL)
	{
	return;
	}*/

	// �ֱ�һ��
	assert(*pphead);
	// 1��һ���ڵ�
	// 2�����������Ͻڵ�
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//SLTNode* tail = *pphead;
		//SLTNode* prev = NULL;
	 //   //�ҵ�βָ��
		//while (tail->next != NULL)
		//{
		//	prev = tail;
		//	tail = tail->next;
		//}
		//	free(tail);
		//	tail = NULL;
		//	prev->next = NULL;	
		//ʣ��һ���ڵ㶼����ɶԿ�ָ������÷��ʲ���
		SLTNode* tail = *pphead;
		//�ҵ�βָ��
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}
//ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
//ͷɾ
void SListPopFront(SLTNode** pphead)
{
	//if (*pphead == NULL)
	//	return;
	assert(*pphead != NULL);

	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}
// ��pos�ĺ�����룬������ʺϣ�Ҳ���� ʱ�临�Ӷ�O(1)
void SListInsertAfter(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);
	SLTNode* newnode = BuyListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
// ��posλ��֮ǰȥ����һ���ڵ�  ʱ�临�Ӷ�O(N)
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	SLTNode* newnode = BuyListNode(x);
	if (pos == *pphead)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		// �ҵ�pos��ǰһ��λ��
		SLTNode* posprev = *pphead;
		while (posprev->next != pos)
		{
			posprev = posprev->next;
		}
		posprev->next = newnode;
		newnode->next = pos;
		// �ҵ�pos��ǰһ��λ��
		/*SLTNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}

		posPrev->next = newnode;
		newnode->next = pos;*/
	}
}
void SListErase(SLTNode** pphead, SLTNode* pos)
{

	if (pos == *pphead)
	{
		*pphead = pos->next;
		free(pos);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		//pos = NULL;
	}
}
void SListDestory(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

//void SListErase(SLTNode** pphead, SLTNode* pos)
//{
//	SLTNode* prev = NULL;
//	SLTNode* cur = *pphead;
//	SLTNode* next = pos->next;
//	assert(*pphead);
//	if (pos == *pphead && (*pphead)->next == NULL)
//	{
//		free(cur);
//		*pphead = NULL;
//	}
//	else
//	{
//		while (cur)
//		{
//			if (pos == *pphead)
//			{
//				free(cur);
//				*pphead = next;
//			}
//			if (cur->next != pos)
//			{
//				prev = cur;
//				cur = cur->next;
//			}
//			else
//			{
//				free(cur);
//				prev->next = next;
//			}
//		}
//	}
//}
// 
//void SListPopFront(SLTNode** pphead)
//{
//	assert(*pphead);
//	SLTNode* next = (*pphead)->next;
//	free(*pphead);
//	*pphead = next;
//}