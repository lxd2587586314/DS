#include <string.h>
#include <stdlib.h>
// Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* prev = NULL, * cur = head;
	while (cur)
	{
		if (cur->val == val)
		{
			// 1、头删
			// 2、中间删除
			prev->next = cur->next;
			free(cur);
			cur = prev->next;
		}
		else
		{
			// 迭代往后走
			prev = cur;
			cur = cur->next;
		}
	}

	return head;
}

int main()
{
	// 方便快速调试oj代码
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 7;
	n2->val = 7;
	n3->val = 7;
	n4->val = 7;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	struct ListNode* head = removeElements(n1, 7);


	return 0;
}