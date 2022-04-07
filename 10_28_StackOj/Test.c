#include "STOJ.h"

bool isValid(char* s) {
	ST st;
	StackInit(&st);
	while (*s)
	{
		if ((*s == '(') ||
			(*s == '[') |
			(*s == '{'))
		{
			StackPush(&st, *s);
			++s;
		}

		else
		{
			if (StackEmpty(&st))
			{
				StackDestroy(&st);
				return false;
			}
			STDataType top = StackTop(&st);
			StackPop(&st);

			if ((*s == ')' && top != '(') ||
				(*s == ']' && top != '[') ||
				(*s == '}' && top != '{'))
			{
				StackDestroy(&st);
				return false;
			}

			else
			{
				++s;
			}

		}

	}
	bool ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}

int main()
{
	char arr[] = "([)]";
	isValid(arr);

	return 0;
}