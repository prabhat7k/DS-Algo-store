#include <bits/stdc++.h>
using namespace std;

// Binary Tree Node
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

// Find LCA
Node* LCA(Node* root, Node* p, Node* q) {
    if (!root || root == p || root == q) return root;
    Node* left = LCA(root->left, p, q);
    Node* right = LCA(root->right, p, q);
    return left && right ? root : (left ? left : right);
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    Node* lca = LCA(root, root->left, root->right);
    cout << "LCA: " << lca->val << endl;
    return 0;
}
