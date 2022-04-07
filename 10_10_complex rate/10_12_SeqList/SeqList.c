#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void SeqListInit(SL* ps)
{
	assert(ps);//��Ҫ���Ƕ���
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListCheckCapacity(SL* ps)
{
	//������� �������������
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);//����ʧ��ֱ����ֹ����
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}

void SeqListPushBack(SL* ps, SLDataType x)
{
	/*if (ps->size == ps->capacity){
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
	}*/  //ע��������������������
	//�ռ䲻��Ҫ��������
	/*SeqListCheckCapacity(ps);
		ps->a[ps->size] = x;
		ps->size++;*/
	SeqListInsert(ps, ps->size, x);
}
void SeqListPopBack(SL* ps)
{
	//���ᴦ��ʽ
	//if (ps->size > 0)
	//{
	//	//ps->a[ps->size - 1] = 0; //������λ�ñ���ͷŵ���0 
	//                               �����û��ʲô����
	//	ps->size--;
	//}
	//��������ʽ
	//assert(ps->size > 0);
	//ps->a[ps->size - 1] = 0;
	//ps->size--;//size��ʶ��˳���洢�˶��ٸ���Ч����
	assert(ps);
	SeqListErase(ps, ps->size - 1);
}
void SeqListPushFront(SL* ps, SLDataType x)
{
	//SeqListCheckCapacity(ps);
	//// Ų������
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
	//// Ų������
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
void SeqListDestory(SL* ps)//��̬������ڴ�������ʱ�Ż��������ڴ��ǰ����û��Խ�����
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
//�����±�
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
//  ָ��pos�±�λ�ò���
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	//���ᴦ��ʽ
	/*if (pos<0 || pos>ps->size)
	{
		printf("pos invalid\n");
		return;
	}*/

	//�ֱ��ķ�ʽ
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SeqListCheckCapacity(ps);
	//for (int end = ps->size-1; end >= pos; end--)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//}
	// Ų������
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}
// ɾ��posλ�õ�����
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
//	//��������ʽ
//	//if (ps->size > 0)
//	//{
//	//	//ps->a[ps->size] = 0;
//	//	ps->size--;
//	//}
//	assert(ps->size >= 0);
//	ps->size--;
//}