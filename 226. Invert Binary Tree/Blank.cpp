// ===== Day 3: 226. Invert Binary Tree =====
//
// Invert (mirror) a binary tree: every node's left and right children
// are swapped, all the way down.
//
//        4                    4
//      /   \                /   \
//     2     7      -->     7     2
//    / \   / \            / \   / \
//   1   3 6   9          9   6 3   1
//
//   TreeNode* invertTree(TreeNode* root);   // returns the new root
//
// RECURSION:
//   - Base case: nullptr -> return nullptr (nothing to invert)
//   - Otherwise: swap this node's left/right, then invert each subtree.
//   - Return root.
//
// C++ tip: swap(a, b) swaps two values. swap(root->left, root->right);

#include <bits/stdc++.h>
using namespace std;

// --- GIVEN ---
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// helper (given): print the tree level by level so you can see the result
void printLevelOrder(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* n = q.front(); q.pop();
        cout << n->val << " ";
        if (n->left)  q.push(n->left);
        if (n->right) q.push(n->right);
    }
    cout << endl;
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // TODO
        // Idea #1: Copy the inverted tree
        // Idea #2: switch left and right

        // base case
        if (root == nullptr) return nullptr;


        // progress
        TreeNode* temp;
        swap(root->left, root->right);
        /*
        temp = root->left;
        root->left = root->right;
        root->right = temp;
*/
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

int main() {
    //        4
    //      /   \
    //     2     7
    //    / \   / \
    //   1   3 6   9
    TreeNode* root = new TreeNode(4);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left   = new TreeNode(1);
    root->left->right  = new TreeNode(3);
    root->right->left  = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "before: ";
    printLevelOrder(root);          // 4 2 7 1 3 6 9

    Solution s;
    s.invertTree(root);

    cout << "after:  ";
    printLevelOrder(root);          // 4 7 2 9 6 3 1
    return 0;
}
