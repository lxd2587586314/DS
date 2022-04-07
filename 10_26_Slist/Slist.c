#include "Slist.h"

void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}

}

//void SLTNodePrint(SLTNode* phead)
//{
//	if (phead == NULL)
//	{
//		printf("NULL\n");
//	}
//	while (phead->next != NULL)//err 对NULL指针解引用 
//	{
//		printf("%d->", phead->data);
//		phead = phead->next;
//	}
//	printf("%d->NULL\n", phead->data);
//}
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
//void SListPopFront(SLTNode** pphead)//err
//{
//	assert(pphead);
//	assert(*pphead != NULL);
//	if ((*pphead)->next != NULL)
//	{
//		SLTNode* tail = *pphead;
//		free(tail);
//		tail = NULL;
//		*pphead = (*pphead)->next;
//	}
//	else
//	{
//		//free(*pphead); 少加了
//		free(*pphead);
//		*pphead = NULL;
//	}
//}
void SListPopFront(SLTNode** pphead)
{
	assert(pphead);
	assert(*pphead);

	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}