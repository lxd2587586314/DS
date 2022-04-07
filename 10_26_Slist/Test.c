#include "Slist.h"
#include "List.h"
void test1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	
	SListPrint(plist);
}
void test2()
{
	SLTNode* plist = NULL;
	
	SListPrint(plist);
}
void test3()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPopFront(&plist);

	SListPrint(plist);
}
//int main()
//{
//	//test1();
//	//test2();
//	test3();
//	return 0;
//}

void Test1()
{
	//SLTNode* plist = NULL;
	ListNode* plist = NULL;
	plist = ListInit(plist);
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);

	ListPrint(plist);
}

void Test2()
{
	ListNode* plist = NULL;
	plist = ListInit(plist);
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPrint(plist);
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPrint(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);
}

void Test3()
{
	ListNode* plist = NULL;
	plist = ListInit(plist);
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPrint(plist);

	ListNode* pos = ListFind(plist, 2);
	if (pos)
	{
		ListErase(pos);
		//ListErase(plist,pos);
		pos = NULL;
	}
	//pos->next = plist;
	ListPrint(plist);
	ListDestroy(plist);
	plist = NULL;

}

void Test4()
{
	ListNode* plist = NULL;
	plist = ListInit(plist);

	ListNode* pos = ListFind(plist, 2);
	if (pos)
	{
		ListErase(plist->next);
		//ListErase(plist,pos);
	}
	ListDestroy(plist);
	plist = NULL;
}

int main()
{
	//Test1();
	//Test2();
	Test3();
	//Test4();
	return 0;
}