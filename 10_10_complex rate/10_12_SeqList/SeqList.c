#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListInit(SL* ps)
{
	assert(ps);//不要忘记断言
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListCheckCapacity(SL* ps)
{
	//检查容量 如果不够就扩容
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);//开辟失败直接终止程序
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

void SeqListPushBack(SL* ps, SLDataType x)
{
	/*if (ps->size == ps->capacity){
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
	}*/  //注意变量作用域和生命周期
	//空间不够要考虑增容
	/*SeqListCheckCapacity(ps);
		ps->a[ps->size] = x;
		ps->size++;*/
	SeqListInsert(ps, ps->size, x);
}
void SeqListPopBack(SL* ps)
{
	//温柔处理方式
	//if (ps->size > 0)
	//{
	//	//ps->a[ps->size - 1] = 0; //如果这个位置本身就放的是0 
	//                               置零就没有什么意义
	//	ps->size--;
	//}
	//暴力处理方式
	//assert(ps->size > 0);
	//ps->a[ps->size - 1] = 0;
	//ps->size--;//size标识了顺序表存储了多少个有效数据
	assert(ps);
	SeqListErase(ps, ps->size - 1);
}
void SeqListPushFront(SL* ps, SLDataType x)
{
	//SeqListCheckCapacity(ps);
	//// 挪动数据
	//int end = ps->size - 1;
	//while (end >= 0)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	end--;
	//}
	//ps->a[0] = x;
	//ps->size++;
	assert(ps);
	SeqListInsert(ps, 0, x);
}

void SeqListPopFront(SL* ps)
{
	//assert(ps->size > 0);
	//// 挪动数据
	///*int begin = 0;
	//while (begin < ps->size)
	//{
	//	ps->a[begin] = ps->a[begin+1];
	//	begin++;
	//}*/
	//int begin = 1;
	//while (begin < ps->size)
	//{
	//	ps->a[begin - 1] = ps->a[begin];
	//	begin++;
	//}
	//ps->size--;
	assert(ps);
	SeqListErase(ps, 0);
}
void SeqListPrint(SL* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void SeqListDestory(SL* ps)//动态申请的内存在销毁时才会检查申请内存的前后有没有越界访问
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
//查找下标
int SeqListFind(SL* ps, SLDataType x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
//  指定pos下标位置插入
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	//温柔处理方式
	/*if (pos<0 || pos>ps->size)
	{
		printf("pos invalid\n");
		return;
	}*/

	//粗暴的方式
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SeqListCheckCapacity(ps);
	//for (int end = ps->size-1; end >= pos; end--)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//}
	// 挪动数据
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}
// 删除pos位置的数据
void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	//assert(ps->size > 0);
	assert(pos >= 0 && pos < ps->size);
	/*for (int begin = pos+1; begin < ps->size; begin++)
	{
		ps->a[begin-1] = ps->a[begin];
	}*/
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}



//void SeqListInit(SL* ps)
//{
//	//ps.a = (SLDataType*)malloc(sizeof(SLDataType*));
//	//ps.capacity = ps.size = 0;
//}

//void SepListPushBack(SL* ps, SLDataType x)
//{
//	SepListCheckCapacity(ps);
//	
//	ps->a[ps->size] = x;
//	ps->size++;
//}

//void SepListPrint(SL* ps)
//{
//	int i = 0;
//	for (i = 0; i < ps->size; ++i)
//	{
//		printf("%d ", ps->a[i]);
//	}
//}
//void SepListDestory(SL* ps)
//{
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = ps->size = 0;
//}

//void SepListPopBack(SL* ps)
//{
//	//温柔解决方式
//	//if (ps->size > 0)
//	//{
//	//	//ps->a[ps->size] = 0;
//	//	ps->size--;
//	//}
//	assert(ps->size >= 0);
//	ps->size--;
//}