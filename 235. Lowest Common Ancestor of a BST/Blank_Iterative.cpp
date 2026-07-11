// ===== 235. LCA of BST -- ITERATIVE (while loop), O(1) space =====
//
// Same problem, but no recursion.
//
// WHY it works without recursion:
//   In a BST we only ever go down ONE side (we throw the other subtree
//   away entirely -- just like binary search). The path from the root to
//   the LCA is a straight line, never branching. So we can just walk
//   down it with a loop, keeping a single pointer.
//
//   No branching -> no need for a call stack -> SPACE O(1).
//
//   Compare:
//     recursive version : Time O(H), Space O(H)   (call stack)
//     iterative version : Time O(H), Space O(1)   <-- better!
//
//            6
//          /   \
//         2     8
//        / \   / \
//       0   4 7   9
//          / \
//         3   5
//
// Loop idea:
//   start at root, then repeat:
//     - both p and q smaller than current -> move current to left
//     - both p and q bigger  than current -> move current to right
//     - otherwise -> current IS the LCA, return it

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
      
        // Condition for LCA
        // 1) BOTH smaller than node -> LCA is left side
        // 2) BOTH bigger than node -> LCA is right side
        // 3) otherwise -> I am the LCA
        TreeNode* t=root;
        
        while (t) {
            if (t->val > p->val && t->val > q->val) {
                t = t -> left;
            }
            else if (t->val < p->val && t->val < q->val) {
                t = t -> right;
            }
            else
                break;
        }
        return t;
    }   
};

int main() {
    TreeNode* root = new TreeNode(6);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left   = new TreeNode(0);
    root->left->right  = new TreeNode(4);
    root->right->left  = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left  = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* n2 = root->left;
    TreeNode* n8 = root->right;
    TreeNode* n4 = root->left->right;
    TreeNode* n0 = root->left->left;
    TreeNode* n5 = root->left->right->right;
    TreeNode* n9 = root->right->right;
    TreeNode* n7 = root->right->left;

    Solution s;
    cout << s.lowestCommonAncestor(root, n2, n8)->val << endl;  // 6
    cout << s.lowestCommonAncestor(root, n2, n4)->val << endl;  // 2
    cout << s.lowestCommonAncestor(root, n0, n5)->val << endl;  // 2
    cout << s.lowestCommonAncestor(root, n4, n5)->val << endl;  // 4
    cout << s.lowestCommonAncestor(root, n7, n9)->val << endl;  // 8
    return 0;
}
