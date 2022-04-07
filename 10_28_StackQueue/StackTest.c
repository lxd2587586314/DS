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
	ST st ;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPop(&st);
	StackPop(&st);
	printf("%d\n",StackTop(&st));
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
		printf("%d\n", st.a[st.top - 1]);
		StackPop(&st);
	}

	StackDestroy(&st);
}

int main()
{
	
	TestStack1();
	//TestStack2();
	//TestStack3();
	//TestStack4();
	return 0;
}