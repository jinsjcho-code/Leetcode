// ===== Day 5 (bonus): 230. Kth Smallest Element in a BST =====
//
// Given a BST, return the k-th SMALLEST value (1-indexed).
//
//        3
//       / \
//      1   4        k = 1  ->  1
//       \           k = 3  ->  3
//        2          k = 4  ->  4
//
//   int kthSmallest(TreeNode* root, int k);
//
// HINT (you already know this!): what does an INORDER traversal of a BST
// give you?  ... A SORTED sequence.  So the k-th smallest is simply the
// k-th value you visit in inorder.
//
// Two ways:
//   (A) Do a full inorder into a vector, then return v[k-1].   (simple)
//   (B) Walk inorder and COUNT; stop as soon as you hit the k-th.
//       (better -- you don't have to visit the whole tree)
//
// Try (A) first, then (B) if you want the optimization.

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
    vector <int> v;
    void inorderDFS(TreeNode* node) {
        // base case
        if (!node) return ;
        
        // How do I combine child's result
        inorderDFS(node->left);
        v.push_back(node->val);

        inorderDFS(node->right);
        
    }

    int kthSmallest(TreeNode* root, int k) {
        
        // 1) What does this function return? -> Kth number
        // 2) What is the base case? -> root is null return
        // 3) How do I combine child's results? -> B 
        // A:Combine, B: Accumulate, C: forward

        // Basic Idea: Sorted Array? or Set? But I don't know how can I use set.
        // However it's already sorted tree! Why do I use any other structure? It has already index?

        // Found: Count of inorder -> kth number??? 
        v={};
        inorderDFS(root);

        return v[k-1];    
    }
};

int main() {
    Solution s;

    //     3
    //    / \
    //   1   4
    //    \
    //     2
    TreeNode* a = new TreeNode(3);
    a->left = new TreeNode(1); a->right = new TreeNode(4);
    a->left->right = new TreeNode(2);
    cout << s.kthSmallest(a, 1) << endl;   // 1
    cout << s.kthSmallest(a, 2) << endl;   // 2
    cout << s.kthSmallest(a, 3) << endl;   // 3
    cout << s.kthSmallest(a, 4) << endl;   // 4

    //         5
    //        / \
    //       3   6
    //      / \
    //     2   4
    //    /
    //   1
    TreeNode* b = new TreeNode(5);
    b->left = new TreeNode(3); b->right = new TreeNode(6);
    b->left->left = new TreeNode(2); b->left->right = new TreeNode(4);
    b->left->left->left = new TreeNode(1);
    cout << s.kthSmallest(b, 3) << endl;   // 3

    return 0;
}
