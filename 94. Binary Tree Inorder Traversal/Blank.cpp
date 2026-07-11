// ===== Day 4: 94. Binary Tree Inorder Traversal =====
//
// Return the node values in INORDER:  left subtree -> node -> right subtree
//
//        1              ->  [1, 3, 2]
//         \
//          2
//         /
//        3
//
//        4              ->  [1, 2, 3, 4, 5, 6, 7]   (a BST prints sorted!)
//      /   \
//     2     6
//    / \   / \
//   1   3 5   7
//
//   vector<int> inorderTraversal(TreeNode* root);
//
// THE THREE CLASSIC ORDERS (just where you "visit" the node):
//   preorder : node, left, right
//   inorder  : left, node, right    <-- this problem
//   postorder: left, right, node
//
// RECURSION shape: a helper that appends into a shared result vector.
//   void dfs(TreeNode* node, vector<int>& out) {
//       if (!node) return;              // base case
//       dfs(node->left, out);           // go left first
//       out.push_back(node->val);       // then visit me
//       dfs(node->right, out);          // then go right
//   }
// Note: `out` is passed BY REFERENCE -- an intentional shared accumulator.
// (This is the "accumulator" recursion shape we talked about.)

#include <bits/stdc++.h>
using namespace std;

// --- GIVEN ---
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    void dfs(TreeNode* node, vector<int>& ans) {
        // base case
        if (!node) return ;

        // progress
        dfs(node->left, ans);
        ans.push_back(node->val);

        dfs(node->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        // Basic Idea: DFS 
        
        vector<int> ans;
        // base case
        dfs(root, ans);

        return ans;

    }
};

int main() {
    Solution s;

    //   1
    //    \
    //     2
    //    /
    //   3
    TreeNode* a = new TreeNode(1);
    a->right = new TreeNode(2);
    a->right->left = new TreeNode(3);
    for (int v : s.inorderTraversal(a)) cout << v << " ";
    cout << endl;                    // expect: 1 3 2

    
    //       4
    //     /   \
    //    2     6
    //   / \   / \
    //  1   3 5   7
    TreeNode* b = new TreeNode(4);
    b->left  = new TreeNode(2); b->right = new TreeNode(6);
    b->left->left  = new TreeNode(1); b->left->right  = new TreeNode(3);
    b->right->left = new TreeNode(5); b->right->right = new TreeNode(7);
    for (int v : s.inorderTraversal(b)) cout << v << " ";
    cout << endl;                    // expect: 1 2 3 4 5 6 7 (sorted!)

    return 0;
}
