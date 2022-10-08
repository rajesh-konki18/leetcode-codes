#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

    ListNode *temp = new ListNode();
    ListNode *res = temp;
    int sum, carry = 0;
    while (l1 != NULL || l2 != NULL)
    {
        if (l1 == NULL)
            l1 = new ListNode(0);
        if (l2 == NULL)
            l2 = new ListNode(0);
        sum = (l1->val + l2->val + carry) % 10;
        ListNode *newTemp = new ListNode(sum);
        carry = (l1->val + l2->val + carry) / 10;
        // res = new ListNode(sum, newTemp);
        temp->next = newTemp;
        temp = temp->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (carry > 0)
    {
        temp->next = new ListNode(carry);
    }
    return res->next;
}

int main()
{
    ListNode *node11 = new ListNode(9);
    ListNode *node12 = new ListNode(9);
    ListNode *node13 = new ListNode(9);
    ListNode *node14 = new ListNode(9);
    ListNode *node15 = new ListNode(9);
    ListNode *node16 = new ListNode(9);
    ListNode *node17 = new ListNode(9);

    node11->next = node12;
    node12->next = node13;
    node13->next = node14;
    node14->next = node15;
    node15->next = node16;
    node16->next = node17;
    // ListNode* temp = node11;

    ListNode *node21 = new ListNode(9);
    ListNode *node22 = new ListNode(9);
    ListNode *node23 = new ListNode(9);
    ListNode *node24 = new ListNode(9);

    node21->next = node22;
    node22->next = node23;
    node23->next = node24;

    ListNode *res = addTwoNumbers(node11, node21);

    ListNode *temp = res;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    return 0;
}
