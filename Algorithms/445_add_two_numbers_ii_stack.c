#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

#define MAX_SIZE 10000

struct stack {
    struct ListNode *a[MAX_SIZE];
    int top;
};

void push(struct stack *stk, struct ListNode *data) {
    if (stk->top < MAX_SIZE) {
        stk->a[stk->top] = data;
        stk->top++;
    }
}

struct ListNode *pop(struct stack *stk) {
    if (stk->top > 0) {
        stk->top--;
        return stk->a[stk->top];
    }
    return NULL;
}

struct ListNode *reverseList(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct stack stk1;
    stk1.top = 0;

    struct ListNode *temp = head;
    while (temp != NULL) {
        push(&stk1, temp);
        temp = temp->next;
    }

    struct ListNode *newhead = pop(&stk1);
    temp = newhead;

    while (stk1.top > 0) {
        temp->next = pop(&stk1);
        temp = temp->next;
    }
    temp->next = NULL;

    return newhead;
}

struct ListNode *addListNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode *current = &dummy;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        current = current->next;

        current->val = sum % 10;
        current->next = NULL;
    }

    return dummy.next;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *L1 = reverseList(l1);
    struct ListNode *L2 = reverseList(l2);
    struct ListNode *L3 = addListNumbers(L1, L2);
    struct ListNode *L4 = reverseList(L3);
    return L4;
}
