#include "Stack.h"

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
	ps->capacity = ps->top = 0;
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

//void StackPush(ST* ps, STDataType x)
//{
//	assert(ps);
//	if (ps->top == ps->capacity)
//	{
//		ps->capacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * 2);
//		if (tmp == NULL)
//		{
//			printf("mallco fail\n");
//			exit(-1);
//		}
//		else
//		{
//			ps->a = tmp;
//		}
//	}
//	else
//	{
//		ps->a[ps->top] = x;
//		ps->top++;
//	}
//}
//
//void StackPop(ST* ps)
//{
//	assert(ps);
//	assert(ps->top>0);
//	ps->top--;
//}
//STDataType StackTop(ST* ps)
//{
//	return ps->a[ps->top - 1];
//}
