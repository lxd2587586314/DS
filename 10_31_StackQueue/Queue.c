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
	//���ڽṹ������ı�����ָ��Ͳ���Ҫ������ָ��
	//���ṹ��ָ��Ϳ���
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	//while (cur != pq->tail) ���tail���ָ��û�б��ͷ�
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	//�ͷ����ÿ�
	pq->head = pq->tail = NULL;
}

//Ϊʲô����pushback�����е����ʾ���ֻ������һ��������
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
	newnode->next = NULL;//β�ڵ�����NULL

	//��һ�β���ڵ��ʱ��
	//if (pq->head == pq->tail)
	if (pq->head == NULL)//ͷָ��Ϊ��˵������Ϊ��
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
	assert(!QueueEmpty(pq));//�ж϶����Ƿ�Ϊ��
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	//�����ͷ���ʱ��β�ڵ�ֻ�ͷ��˿ռ䣬û���ÿ�
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
