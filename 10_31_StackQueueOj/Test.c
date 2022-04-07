#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);


void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
}

void QueuePush(Queue* pq, const QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
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
	int count = 0;
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		++count;
		cur = next;
	}
	return count;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}
typedef struct {
	Queue q1;
	Queue q2;
} MyStack;

bool myStackEmpty(MyStack* obj);

MyStack* myStackCreate() {
	MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
	if (stack == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	QueueInit(&stack->q1);
	QueueInit(&stack->q2);
	return stack;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	Queue* EmptyQueue = &obj->q1;
	Queue* NonEmptyQueue = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		EmptyQueue = &obj->q2;
		NonEmptyQueue = &obj->q1;
	}
	while (QueueSize(NonEmptyQueue) > 1)
	{
		QDataType front = QueueFront(NonEmptyQueue);
		QueuePush(EmptyQueue, front);
		QueuePop(NonEmptyQueue);
	}
	int top = QueueFront(NonEmptyQueue);
	QueuePop(NonEmptyQueue);
	return top;
}

int myStackTop(MyStack* obj) {
	assert(!myStackEmpty(obj));
	Queue* EmptyQueue = &obj->q1;
	Queue* NonEmptyQueue = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		EmptyQueue = &obj->q2;
		NonEmptyQueue = &obj->q1;
	}
	while (QueueSize(NonEmptyQueue) > 1)
	{
		QDataType front = QueueFront(NonEmptyQueue);
		QueuePush(EmptyQueue, front);
		QueuePop(NonEmptyQueue);
	}
	int top = QueueFront(NonEmptyQueue);
	QueuePush(EmptyQueue, QueueFront(NonEmptyQueue));
	QueuePop(NonEmptyQueue);
	return top;
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/


typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
STDataType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0; //ps->top = -1;
	ps->capacity = 0;
}
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
}
void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("malloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)
{
	assert(ps);
	//assert(ps->top > 0);
	assert(!StackEmpty(ps));
	ps->top--;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
bool StackEmpty(ST* ps)
{
	/*if (ps->top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}*/
	assert(ps);
	return ps->top == 0;
}

typedef struct {
	ST pushST;
	ST popST;
} MyQueue;

bool myQueueEmpty(MyQueue* obj);

MyQueue* myQueueCreate() {
	MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&queue->pushST);
	StackInit(&queue->popST);
	return queue;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->pushST, x);
}

int myQueuePop(MyQueue* obj) {
	assert(myQueueEmpty(obj));
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}

	int top = StackTop(&obj->popST);
	StackPop(&obj->popST);
	return top;
}

int myQueuePeek(MyQueue* obj) {
	assert(!myQueueEmpty(obj));
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}

	int top = StackTop(&obj->popST);
	return top;
}

bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->pushST);
	StackDestroy(&obj->popST);
	free(obj);
}

//int main()
//{
//	MyQueue* queue = myQueueCreate();
//	myQueuePush(queue, 1);
//	myQueuePush(queue, 2);
//
//	myQueuePeek(queue);
//	myQueuePop(queue);
//	myQueueEmpty(queue);
//
//	return 0;
//}
/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/

typedef struct {
	int* a;
	int begin;
	int end;
	int k;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->a = (int*)malloc(sizeof(int) * (k + 1));
	cq->k = k;
	cq->begin = cq->end = 0;
	return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
		return false;
	obj->a[obj->end] = value;
	obj->end++;
	obj->end %= (obj->k + 1);
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return false;
	obj->begin++;
	obj->begin %= obj->k + 1;
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;

	return obj->a[obj->begin];
}

int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return -1;
	if (obj->end == 0)
		return obj->a[obj->k];

	return obj->a[obj->end - 1];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->begin == obj->end;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return (obj->end + 1) % (obj->k + 1) == obj->begin;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->a);
	free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/
//int main()
//{
//	MyCircularQueue* cq = myCircularQueueCreate(3);
//
//	//["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", 
//	//"Rear", "isFull", "deQueue", "enQueue", "Rear"]
//	if (myCircularQueueEnQueue(cq, 1))
//		printf("true\n");
//	else
//		printf("false\n");
//	if (myCircularQueueEnQueue(cq, 2))
//		printf("true\n");
//	else
//		printf("false\n");
//	if (myCircularQueueEnQueue(cq, 3))
//		printf("true\n");
//	else
//		printf("false\n");
//	if (myCircularQueueEnQueue(cq, 4))
//		printf("true\n");
//	else
//		printf("false\n");
//
//	int rear = myCircularQueueRear(cq);
//	if (myCircularQueueIsFull(cq))
//		printf("isfull\n");
//
//	myCircularQueueDeQueue(cq);
//	if (myCircularQueueEnQueue(cq, 4))
//		printf("true\n");
//	else
//		printf("false\n");
//	myCircularQueueRear(cq);
//	myCircularQueueFree(cq);
//
//	return 0;
//}

int main()
{
	MyCircularQueue* cq = myCircularQueueCreate(3);

	//["MyCircularQueue", "enQueue", "Rear", "Front",
	//[[3], [2], [], [], 
	//  "deQueue", "Front", "deQueue", "Front", 
	// [], [], [], [], 
	// "enQueue", "enQueue", "enQueue", "enQueue"]
	//[4], [2], [2], [3]]
	if (myCircularQueueEnQueue(cq, 1))
		printf("true\n");
	else
		printf("false\n");
	if (myCircularQueueEnQueue(cq, 2))
		printf("true\n");
	else
		printf("false\n");
	if (myCircularQueueEnQueue(cq, 3))
		printf("true\n");
	else
		printf("false\n");
	if (myCircularQueueEnQueue(cq, 4))
		printf("true\n");
	else
		printf("false\n");

	int rear = myCircularQueueRear(cq);
	if (myCircularQueueIsFull(cq))
		printf("isfull\n");

	myCircularQueueDeQueue(cq);
	if (myCircularQueueEnQueue(cq, 4))
		printf("true\n");
	else
		printf("false\n");
	myCircularQueueRear(cq);
	myCircularQueueFree(cq);

	return 0;
}