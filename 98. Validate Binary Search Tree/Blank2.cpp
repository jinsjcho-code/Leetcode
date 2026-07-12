// ===== 98. Validate BST -- retry (NO hints) =====
//
// Return true if the tree is a valid BST.
//
// BST rule:  EVERY node in the left subtree  <  node
//            EVERY node in the right subtree >  node
//            (subtrees, not just the direct children!)
//
//        5          -> FALSE
//       / \             (3 sits in 5's RIGHT subtree, but 3 < 5)
//      4   6
//         / \
//        3   7
//
//   bool isValidBST(TreeNode* root);
//
// ---------------------------------------------------------------
// FILL THIS IN FIRST (Recursion_Cards.md), before writing any code:
//
//   (1) What does my function RETURN?  (one sentence)
//       -> check the wihtin range and update range
//
//   (2) Base case?
//       -> if root is null -> return true;
//
//   (3) How do I combine the children's results?
//       -> check the left of result and right of result.
//
//   Shape:  A (combine) / B (accumulator + return) / C (find & pass up)
//       -> A
// ---------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool valid (TreeNode* node, long long minVal, long long maxVal) {
        
        // base case
        if (!node) return true;

        // what does this function return? check the range and combine.
        if (node->val <= minVal || node->val >= maxVal) return false;  // out of range

        return valid (node->left, minVal, node->val) && valid(node->right, node->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        // Basic Idea: check the range of node. So I need to build a new helper function.
        
        return valid (root, LLONG_MIN, LLONG_MAX);

    }
};

int main() {
    Solution s;

    //   2
    //  / \
    // 1   3                 -> true
    TreeNode* a = new TreeNode(2);
    a->left = new TreeNode(1); a->right = new TreeNode(3);
    cout << s.isValidBST(a) << endl;   // 1

    //      5
    //     / \
    //    4   6              -> false  (3 < 5 but in 5's right subtree)
    //       / \
    //      3   7
    TreeNode* b = new TreeNode(5);
    b->left = new TreeNode(4); b->right = new TreeNode(6);
    b->right->left = new TreeNode(3); b->right->right = new TreeNode(7);
    cout << s.isValidBST(b) << endl;   // 0

    //   2
    //  /
    // 2                     -> false  (duplicates not allowed)
    TreeNode* c = new TreeNode(2);
    c->left = new TreeNode(2);
    cout << s.isValidBST(c) << endl;   // 0

    // single node            -> true
    cout << s.isValidBST(new TreeNode(1)) << endl;   // 1

    //        10
    //       /  \
    //      5    15
    //          /  \
    //         6    20       -> false  (6 < 10 but in right subtree)
    TreeNode* d = new TreeNode(10);
    d->left = new TreeNode(5); d->right = new TreeNode(15);
    d->right->left = new TreeNode(6); d->right->right = new TreeNode(20);
    cout << s.isValidBST(d) << endl;   // 0

    //        8
    //       / \
    //      3   10
    //     / \    \
    //    1   6    14        -> true (a real BST)
    //       / \
    //      4   7
    TreeNode* e = new TreeNode(8);
    e->left = new TreeNode(3); e->right = new TreeNode(10);
    e->left->left = new TreeNode(1); e->left->right = new TreeNode(6);
    e->left->right->left = new TreeNode(4);
    e->left->right->right = new TreeNode(7);
    e->right->right = new TreeNode(14);
    cout << s.isValidBST(e) << endl;   // 1

    return 0;
}
