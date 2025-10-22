#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return NULL;
    ListNode *p1 = headA, *p2 = headB;
    while (p1 != p2) {
        p1 = p1 ? p1->next : headB;
        p2 = p2 ? p2->next : headA;
    }
    return p1;
}

int main() {
    // Create common part
    ListNode* common = new ListNode(5);
    common->next = new ListNode(6);
    common->next->next = new ListNode(7);

    // List A
    ListNode* a1 = new ListNode(1);
    a1->next = new ListNode(2);
    a1->next->next = new ListNode(3);
    a1->next->next->next = common;

    // List B
    ListNode* b1 = new ListNode(9);
    b1->next = new ListNode(8);
    b1->next->next = common;

    ListNode* inter = getIntersectionNode(a1, b1);
    if (inter) cout << "Intersection at node: " << inter->val << endl;
    else cout << "No intersection" << endl;

    return 0;
}
