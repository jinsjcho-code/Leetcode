// ===== Day 5: 235. Lowest Common Ancestor of a BST =====
//
// Given a BINARY SEARCH TREE (BST) and two nodes p and q, find their
// LOWEST COMMON ANCESTOR (LCA): the deepest node that has BOTH p and q
// as descendants (a node can be a descendant of itself).
//
//            6
//          /   \
//         2     8
//        / \   / \
//       0   4 7   9
//          / \
//         3   5
//
//   LCA(2, 8) = 6      (they split at 6)
//   LCA(2, 4) = 2      (2 is an ancestor of 4, and of itself)
//
//   TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
//
// KEY: this is a BST, so values are ORDERED:
//      everything in the left subtree  <  node  <  everything in the right
//
// So starting at the root, ask: where are p and q relative to me?
//   - BOTH smaller than me   -> the LCA must be somewhere on my LEFT
//   - BOTH bigger  than me   -> the LCA must be somewhere on my RIGHT
//   - otherwise (they split, or one IS me) -> I AM the LCA
//
// You can write this with recursion OR a simple while-loop (no recursion
// needed!). Try the loop version too -- it's O(1) space.

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //Basic Idea
        // 1) BOTH smaller than me: LCA must be somewhere on my Left
        // 2) BOTH bigger than me: LCA must be somewhere on my right
        // 3) other wise: I am the LCA

        // Time: O(H)
        // Space: Balanced Tree: O(logN) / Skewed Tree: O(N)
        
        // 이것도 재귀?
        // base case

        // progress
        if (root->val > p->val && root->val > q->val) { 
            return lowestCommonAncestor(root->left, p, q);
        }
        
        else if (root->val < p->val && root-> val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;

    }
};

int main() {
    //            6
    //          /   \
    //         2     8
    //        / \   / \
    //       0   4 7   9
    //          / \
    //         3   5
    TreeNode* root = new TreeNode(6);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left   = new TreeNode(0);
    root->left->right  = new TreeNode(4);
    root->right->left  = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left  = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* n2 = root->left;             // 2
    TreeNode* n8 = root->right;            // 8
    TreeNode* n4 = root->left->right;      // 4
    TreeNode* n0 = root->left->left;       // 0
    TreeNode* n5 = root->left->right->right; // 5

    Solution s;
    cout << s.lowestCommonAncestor(root, n2, n8)->val << endl;  // 6
    cout << s.lowestCommonAncestor(root, n2, n4)->val << endl;  // 2
    cout << s.lowestCommonAncestor(root, n0, n5)->val << endl;  // 2
    cout << s.lowestCommonAncestor(root, n4, n5)->val << endl;  // 4
    return 0;
}
