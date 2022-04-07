#include "Stack.h"

void TestStack1()
{
	ST st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	/*while (st.top)
	{
		printf("%d\n", st.a[st.top - 1]);
		st.top--;
	}*/
	StackDestroy(&st);
}

void TestStack2()
{
	ST st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPop(&st);
	StackPop(&st);
	printf("%d\n", StackTop(&st));
	StackPop(&st);
	//StackPop(&st);
	while (st.top)
	{
		printf("%d\n", st.a[st.top - 1]);
		st.top--;
	}

	StackDestroy(&st);
}

void TestStack3()
{
	ST st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	printf("%d\n", StackSize(&st));
	StackPop(&st);
	StackPop(&st);
	printf("%d\n", StackTop(&st));
	StackPop(&st);
	//StackPop(&st);
	while (st.top)
	{
		printf("%d\n", st.a[st.top - 1]);
		st.top--;
	}

	StackDestroy(&st);
}

void TestStack4()
{
	ST st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	printf("%d\n", StackTop(&st));
	StackPop(&st);
	printf("%d\n", StackTop(&st));
	StackPop(&st);
	StackPush(&st, 5);
	StackPush(&st, 6);
	while (!StackEmpty(&st))
	{
		printf("%d\n", StackTop(&st));
		StackPop(&st);
	}

	StackDestroy(&st);
}

#include "Queue.h"

void TestQueue1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	//QueuePop(&q);
	//printf("%d\n", QueueBack(&q));

}

void TestQueue2()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);

	printf("%d\n", QueueFront(&q));
	QueuePop(&q);

	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		QDataType front = QueueFront(&q);
		printf("%d\n", front);
		QueuePop(&q);
	}
}

int main()
{

	//TestStack1();
	//TestStack2();
	//TestStack3();
	//TestStack4();
	//TestQueue1();
	TestQueue2();
	return 0;
}