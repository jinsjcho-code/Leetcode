// ===== 543. Diameter of Binary Tree -- retry (NO hints) =====
//
// The DIAMETER = length of the longest path between ANY two nodes,
// measured in EDGES. The path does NOT have to go through the root.
//
//        1            diameter = 3   (4 -> 2 -> 1 -> 3, three edges)
//       / \
//      2   3
//     / \
//    4   5
//
//   int diameterOfBinaryTree(TreeNode* root);
//
// Think: for any single node, how long is the longest path that
// PASSES THROUGH it? And what does each recursive call need to hand
// back to its parent?  (Those two are different things.)

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
    // helper function
    int ans=0;
    int dfs(TreeNode* node) {
        
        // base case
        if (!node) return 0;

        // progress
        int left = dfs(node->left);
        int right = dfs(node->right);

        ans = max(ans, left+right);

        return 1+max(left, right);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // Basic Idea: DFS + calculate the height at each node
        // Time: O(N) // Space: balanced Tree O(logN), Skewed Tree: O(N)
        ans = 0;
        dfs(root);
        return ans;
    }
};

int main() {
    Solution s;

    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* a = new TreeNode(1);
    a->left = new TreeNode(2); a->right = new TreeNode(3);
    a->left->left = new TreeNode(4); a->left->right = new TreeNode(5);
    cout << s.diameterOfBinaryTree(a) << endl;   // expect: 3

    //   1
    //    \
    //     2
    TreeNode* b = new TreeNode(1);
    b->right = new TreeNode(2);
    cout << s.diameterOfBinaryTree(b) << endl;   // expect: 1

    // single node
    cout << s.diameterOfBinaryTree(new TreeNode(1)) << endl;   // expect: 0

    // deeper: path not through root
    //        1
    //       /
    //      2
    //     / \
    //    4   5
    //   /     \
    //  6       7
    TreeNode* c = new TreeNode(1);
    c->left = new TreeNode(2);
    c->left->left = new TreeNode(4); c->left->right = new TreeNode(5);
    c->left->left->left = new TreeNode(6);
    c->left->right->right = new TreeNode(7);
    cout << s.diameterOfBinaryTree(c) << endl;   // expect: 4  (6->4->2->5->7)

    return 0;
}
