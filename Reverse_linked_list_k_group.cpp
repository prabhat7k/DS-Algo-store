#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* buildList(vector<int> arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* node = head;
    for (int i = 0; i < k; i++) {
        if (!node) return head;
        node = node->next;
    }
    ListNode *prev = NULL, *curr = head;
    for (int i = 0; i < k; i++) {
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head->next = reverseKGroup(curr, k);
    return prev;
}

int main() {
    ListNode* head = buildList({1, 2, 3, 4, 5});
    cout << "Original: "; printList(head);
    head = reverseKGroup(head, 2);
    cout << "Reversed in K=2: "; printList(head);
    return 0;
}
