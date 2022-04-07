#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void TestSeqList1()
{
	//SL s1 = { NULL ,0, 4};
	SL s1;
	SeqListInit(&s1);
	//SepListPushBack(&s1, 1);
	//SepListPushBack(&s1, 2);
	//SepListPushBack(&s1, 3);
	//SepListPushBack(&s1, 4);
	//SepListPushBack(&s1, 5);
	//SepListPrint(&s1);
	//SepListPopBack(&s1);
	//SepListPopBack(&s1);
	//SepListPopBack(&s1);
	//SepListPopBack(&s1);
	//SepListPopBack(&s1);
	//SepListDestory(&s1);
}

void TestSeqList2()
{
	//SL s1 = { NULL ,0, 4};
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPrint(&s1);

	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);

	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPrint(&s1);

	SeqListDestory(&s1);//动态申请的内存在销毁时才会检查有没有越界访问

}
void TestSeqList3()
{
	//SL s1 = { NULL ,0, 4};
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPrint(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPopBack(&s1);

	SeqListDestory(&s1);//不释放内存会造成内存泄漏
}

void TestSeqList4()
{
	//SL s1 = { NULL ,0, 4};
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPrint(&s1);
	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPrint(&s1);
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);
	SeqListPrint(&s1);
	SeqListPopFront(&s1);
	SeqListPrint(&s1);
	SeqListDestory(&s1);//不释放内存会造成内存泄漏
}

void TestSeqList5()
{
	//SL s1 = { NULL ,0, 4};
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);

	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPrint(&s1);
	int pos = SeqListFind(&s1, 8);
	printf("%d\n", pos);
	//printf("%d\n", s1.a[pos]);
	SeqListDestory(&s1);
}
void TestSeqList6()
{
	//SL s1 = { NULL ,0, 4};
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPrint(&s1);
	SeqListInsert(&s1, 0, 10);
	SeqListPrint(&s1);
	SeqListInsert(&s1, 1, 20);
	/*SeqListErase(&s1, 0);
	SeqListErase(&s1, 0);
	SeqListErase(&s1, 0);*/

	SeqListPrint(&s1);
	SeqListDestory(&s1);
}
// 写一个类似通讯录的菜单
void Menu()
{
	printf("************************************\n");
	printf("请选择你的操作:>\n");
	printf("1、头插  2、头删\n");
	printf("3、尾插  4、尾删\n");
	printf("5、打印  -1、退出\n");

	printf("************************************\n");
}
// 建议不要一上来就写菜单，最好先写单元测试
// 等你把程序函数接口测试没问题，再写菜单，菜单不方便调试
void menutest()
{
	SL s1;
	SeqListInit(&s1);
	int input = 0;

	int x;
	while (input != -1)
	{
		Menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入你要头插的数据，以-1结束：\n");
			scanf("%d", &x);
			while (x != -1)
			{
				SeqListPushFront(&s1, x);
				scanf("%d", &x);
			}
			break;
		case 2:
			SeqListPopFront(&s1);
			break;
		case 3:
			printf("请输入你要尾插的数据，以-1结束：");
			scanf("%d", &x);
			while (x != -1)
			{
				SeqListPushBack(&s1, x);
				scanf("%d", &x);
			}
			break;
		case 4: SeqListPopBack(&s1);
			break;
		case 5:
			SeqListPrint(&s1);
			break;
		case -1:
			break;
		default:
			printf("无此选项,请重新输入\n");
			break;
		}
	}
	SeqListDestory(&s1);
}
int main()
{
	//TestSeqList1();
	//TestSeqList2();
	//TestSeqList3();
	//TestSeqList4();
	//TestSeqList5();
	//TestSeqList6();
	menutest();
	return 0;
}

//去重
int removeDuplicates(int* nums, int numsSize){
	if (numsSize == 0)
		return 0;

	int i = 0, j = 1;
	int dst = 0;
	while (j < numsSize)
	{
		if (nums[i] == nums[j])
		{
			++j;
		}
		else
		{
			nums[dst] = nums[i];
			++dst;
			i = j;
			++j;
		}
	}

	//nums[dst] = nums[i];
	//++dst;

	return dst;
}

//int main()
//{
//	int a[3] = { 1, 1, 2 };
//	removeDuplicates(a, 3);
//
//	return 0;
//}

//int main()
//{
//	int* p1 = malloc(sizeof(int) * 10);
//	int* p2 = realloc(p1, sizeof(int) * 2000);
//
//	return 0;
//}