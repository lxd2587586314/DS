#include "Queue.h"

//void QueueInit(Queue* pq)
//{
//	assert(pq);
//	pq->head = NULL;
//	pq->tail = NULL;
//}
// 
//void QueueDestroy(Queue* pq)
//{
//	assert(pq);
//	QueueNode* cur = pq->head;
//	while (cur)
//	{
//		QueueNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//}
//
//void QueuePush(Queue* pq, const QDataType x)
//{
//	assert(pq);
//	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
//	if (newnode == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	newnode->data = x;
//	newnode->next = NULL;
//
//	if (pq->head == NULL)
//	{
//		pq->head = pq->tail = newnode;
//	}
//	else
//	{
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//}
//
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	QueueNode* next = pq->head->next;
//	free(pq->head);
//	pq->head = next;
//	if (pq->head == NULL)
//		pq->tail = NULL;
//}
//QDataType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq->head->data;
//}
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq->tail->data;
//}
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//	int count = 0;
//	QueueNode* cur = pq->head;
//	while (cur)
//	{
//		QueueNode* next = cur->next;
//		++count;
//		cur = next;
//	}
//	return count;
//}
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//	return pq->head == NULL;
//}
//

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	//放在结构体里面改变两个指针就不需要传二级指针
	//传结构体指针就可以
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	//while (cur != pq->tail) 最后tail这个指针没有被释放
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	//释放完置空
	pq->head = pq->tail = NULL;
}

//为什么不叫pushback，队列的性质决定只允许在一端入数据
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;//尾节点链上NULL

	//第一次插入节点的时候
	//if (pq->head == pq->tail)
	if (pq->head == NULL)//头指针为空说明链表为空
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

//void QueuePop(QueueNode** head, QueueNode** tail);
void QueuePop(Queue* pq)
{
	assert(pq);
	//if (pq->head == NULL)
	//	return;
	assert(!QueueEmpty(pq));//判断队列是否为空
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	//链表释放完时，尾节点只释放了空间，没被置空
	if (pq->head == NULL)
		pq->tail = NULL;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	int count = 0;
	/*while (cur != NULL)
	{
		QueueNode* next = cur->next;
		cur = next;
		++count;
	}*/
	while (cur != NULL)
	{
		cur = cur->next;
		++count;
	}
	return count;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
