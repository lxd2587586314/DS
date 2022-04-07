#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//´ó¶Ñ
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HeapInit(HP* hp);
void HeapDestroy(HP* hp);
void HeapPush(HP* hp, HPDataType x);
//void HeapPop(HP* hp);
void HeapPrint(HP* hp);
