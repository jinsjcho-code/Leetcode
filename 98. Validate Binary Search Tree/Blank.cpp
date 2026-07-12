// ===== Day 5: 98. Validate Binary Search Tree =====
//
// Return true if a binary tree is a VALID BST.
//
// BST rule (read it carefully!):
//   - The LEFT subtree of a node contains ONLY nodes with values < node
//   - The RIGHT subtree contains ONLY nodes with values > node
//   - Both subtrees must also be BSTs
//
//        2          -> true
//       / \
//      1   3
//
//        5          -> FALSE!  (4 is in 5's right subtree but 4 < 5)
//       / \
//      1   4
//         / \
//        3   6
//
// ^^^ THE TRAP: it's not enough to check "left child < node < right child".
//     EVERY node in the left subtree must be < node, not just the child.
//     In the second tree, 3 is a valid child of 4, but 3 < 5 and it sits
//     in 5's RIGHT subtree -> invalid.
//
//   bool isValidBST(TreeNode* root);
//
// TWO CLASSIC APPROACHES -- try one, then the other if you like:
//
//   (A) RANGE approach: pass down the allowed (min, max) range.
//       - root can be anything: (-inf, +inf)
//       - going LEFT  from node -> the max becomes node->val
//       - going RIGHT from node -> the min becomes node->val
//       - a node is bad if it's outside its allowed range.
//       Tip: use long long (or pass TreeNode* bounds) to dodge INT_MIN/MAX.
//
//   (B) INORDER approach: an inorder traversal of a valid BST is
//       STRICTLY INCREASING. So walk inorder and check each value is
//       bigger than the previous one. (Remember 94? Same traversal!)

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
    bool valid(TreeNode* node, long long minVal, long long maxVal) {
        // setup the range

        if (!node) return true;

        // progress

        // if node->val is within range then return true
        if (node->val <= minVal || node->val >= maxVal) return false;
        
        return valid(node->left, minVal, node->val) && valid(node->right, node->val, maxVal);


    }
    
    bool isValidBST(TreeNode* root) {
        // Basic Idea
        return valid (root, LLONG_MIN, LLONG_MAX);
     
    }
};

int main() {
    Solution s;

    //   2
    //  / \
    // 1   3          -> true
    TreeNode* a = new TreeNode(2);
    a->left = new TreeNode(1); a->right = new TreeNode(3);
    cout << s.isValidBST(a) << endl;   // 1

    //   5
    //  / \
    // 1   4          -> false (3 and 4 are < 5 but on the right)
    //    / \
    //   3   6
    TreeNode* b = new TreeNode(5);
    b->left = new TreeNode(1); b->right = new TreeNode(4);
    b->right->left = new TreeNode(3); b->right->right = new TreeNode(6);
    cout << s.isValidBST(b) << endl;   // 0

    //      5
    //     / \
    //    4   6       -> false (3 is in 5's RIGHT subtree but 3 < 5)
    //       / \
    //      3   7
    TreeNode* c = new TreeNode(5);
    c->left = new TreeNode(4); c->right = new TreeNode(6);
    c->right->left = new TreeNode(3); c->right->right = new TreeNode(7);
    cout << s.isValidBST(c) << endl;   // 0

    // single node -> true
    cout << s.isValidBST(new TreeNode(1)) << endl;   // 1

    // equal values are NOT allowed (strictly less / greater)
    //   2
    //  /
    // 2                -> false
    TreeNode* d = new TreeNode(2);
    d->left = new TreeNode(2);
    cout << s.isValidBST(d) << endl;   // 0

    return 0;
}
