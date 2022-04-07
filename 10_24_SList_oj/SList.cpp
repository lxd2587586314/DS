#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        struct ListNode* lessHead, * lessTail;
        struct ListNode* greaterHead, * greaterTail;
        lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
        lessTail->next = NULL;
        greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
        greaterTail->next = NULL;
        struct ListNode* cur = pHead;
        while (cur)
        {
            if (cur->val < x)
            {
                lessTail->next = cur;
                lessTail = cur;

            }
            else
            {
                greaterTail->next = cur;
                greaterTail = cur;
            }
            cur = cur->next;
        }
        lessTail->next = greaterHead->next;
        struct ListNode* newHead = lessHead->next;
        greaterTail->next = NULL;
        free(lessHead);
        free(greaterHead);
        return newHead;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList1(struct ListNode* head) {

    /*
        struct ListNode* prev = NULL;
        struct ListNode* cur = head;
        while(cur)
        {
            struct ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;

        }
        return prev;*/
    if (head == NULL)
        return NULL;
    struct ListNode* newnode = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = cur->next;
    while (cur)
    {
        //头插
        cur->next = newnode;
        newnode = cur;
        //迭代
        cur = next;
        if (next)
            next = next->next;
    }
    return newnode;
    /*if(head == NULL)
    return NULL;
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = cur->next;
    while(cur)
    {
        //翻转
        cur->next = prev;
        //迭代
        prev = cur;
        cur = next;
        if(next)
        next = next->next;
    }
    return prev;*/
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//struct ListNode* middleNode(struct ListNode* head) {
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    while (fast)
//    {
//        if (fast->next)
//            fast = fast->next->next;
//        slow = slow->next;
//    }
//    return slow;
//}

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = NULL;
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        struct ListNode* mid = middleNode(A);
        struct ListNode* rm = reverseList(mid);
        struct ListNode* ra = A;
        while (ra && rm)
        {
            if (ra->val == rm->val)
            {
                ra = ra->next;
                rm = rm->next;
            }
            else
            {
                return false;
            }
        }
        if (rm == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* tailA = headA;
    struct ListNode* tailB = headB;
    int lenA = 1;
    int lenB = 1;
    while (tailA->next != NULL)
    {
        tailA = tailA->next;
        lenA++;
    }
    while (tailB->next != NULL)
    {
        tailB = tailB->next;
        lenB++;
    }
    if (tailA->val != tailB->val)
    {
        return NULL;
    }
    else
    {
        int sub = abs(lenA - lenB);
        struct ListNode* longList = headA;
        struct ListNode* shortList = headB;
        if (lenA < lenB)
        {
            longList = headB;
            shortList = headA;
        }
        while (sub--)
        {
            longList = longList->next;
        }
        while (longList && shortList)
        {
            if (longList == shortList)
            {
                return shortList;
            }
            else
            {
                longList = longList->next;
                shortList = shortList->next;
            }
        }
        return NULL;
    }
}

bool hasCycle(struct ListNode* head) {
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        //如果链表带环，俩指针一定会相遇
        if (slow == fast)
            return true;
    }
    return false;
} 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            struct ListNode* meetNode = slow;
            while (meetNode != head)
            {
                head = head->next;
                meetNode = meetNode->next;
            }
            return meetNode;
        }
    }
    return NULL;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            struct ListNode* meet = slow;
            struct ListNode* meetstr = meet->next;
            int lenm = 2;
            while (meetstr != meet)
            {
                meetstr = meetstr->next;
                lenm++;
            }
            int lenh = 1;
            struct ListNode* cur = head;
            while (cur != meet)
            {
                cur = cur->next;
                lenh++;
            }
            int sub = abs(lenh - lenm);
            struct ListNode* longlist = head;
            struct ListNode* shortlist = meet;
            if (lenh < lenm)
            {
                longlist = meet;
                shortlist = head;
            }
            while (sub--)
            {
                longlist = longlist->next;
            }
            while (longlist != meet && shortlist != meet)
            {
                longlist = longlist->next;
                shortlist = shortlist->next;
                if (longlist == shortlist)
                    return shortlist;
            }

        }
    }
    return NULL;
}


//Definition for a Node.
  struct Node {
     int val;
     struct Node *next;
     struct Node *random;
 };

struct Node* copyRandomList(struct Node* head) {
    //依次将复制的节点插入到原链表中，
    struct Node* cur = head;
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;

        copy->next = cur->next;
        cur->next = copy;
        cur = copy->next;
    }
    //将copy的random指向对应原链表的random上
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        cur = copy->next;
    }
    //将copy拆下来进行链接
    cur = head;
    struct Node* copyhead = NULL;
    struct Node* copytail = NULL;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;
        if (copytail == NULL)
        {
            copyhead = copytail = copy;
        }
        else
        {
            copytail->next = copy;
            copytail = copy;

        }
        cur->next = next;
        cur = next;
    }
    return copyhead;
}