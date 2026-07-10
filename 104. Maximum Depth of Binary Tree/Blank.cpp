// ===== Day 3: 104. Maximum Depth of Binary Tree =====
//
// Return the MAXIMUM DEPTH of a binary tree = the number of nodes
// along the longest path from the root down to a leaf.
//
//         3           depth 1
//        / \
//       9   20        depth 2
//          /  \
//         15   7      depth 3     -> maxDepth = 3
//
// THE RECURSION MINDSET (this is the whole game for trees):
//   - Base case: an empty tree (nullptr) has depth 0.
//   - Otherwise: depth = 1 (this node) + max(depth of left, depth of right)
//   - TRUST that maxDepth(root->left) gives you the left subtree's depth.
//     You don't trace it by hand -- you trust the recursion.
//
//   int maxDepth(TreeNode* root);

#include <bits/stdc++.h>
using namespace std;

// --- GIVEN (LeetCode provides this) ---
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    
public:
    int maxDepth(TreeNode* root) {
        // TODO
        // 1) if root is nullptr -> return 0
        // 2) otherwise -> 1 + max( maxDepth(left), maxDepth(right) )
        if (root == nullptr) return 0;
        return 1+max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() {
    // Build this tree:
    //        3
    //       / \
    //      9   20
    //         /  \
    //        15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    cout << s.maxDepth(root) << endl;   // expect: 3
    return 0;
}
