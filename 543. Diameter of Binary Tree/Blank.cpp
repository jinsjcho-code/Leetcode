// ===== Day 4: 543. Diameter of Binary Tree =====
//
// The DIAMETER = the length of the longest path between ANY two nodes.
// Length is measured in EDGES (not nodes).
// The path does NOT have to pass through the root.
//
//        1            diameter = 3   (path 4 -> 2 -> 1 -> 3, that's 3 edges)
//       / \
//      2   3
//     / \
//    4   5
//
//   int diameterOfBinaryTree(TreeNode* root);
//
// THE IDEA (this one is trickier -- take your time):
//   For each node, the longest path THROUGH that node is:
//        height(left) + height(right)      (in edges)
//   The answer is the MAX of that over all nodes.
//
//   So: compute heights recursively (like 104), and while doing it,
//   keep updating a running maximum.
//
//   int best = 0;                       // shared accumulator
//   int height(TreeNode* node) {        // returns height in EDGES
//       if (!node) return -1;           // careful: -1 for edge-counting,
//                                       //          or use 0 for node-counting
//       int L = height(node->left);
//       int R = height(node->right);
//       best = max(best, L + R + 2);    // path through this node (adjust!)
//       return 1 + max(L, R);
//   }
//
// ^ The exact +1/-1 offsets depend on whether you count nodes or edges.
//   Work it out on the example above -- don't just copy. Try node-counting
//   (empty = 0) first, it's easier: path through node = Lnodes + Rnodes.
//
// This is the "accumulator" recursion shape: return one thing (height),
// while updating a shared best.

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
    int ans = 0;
    int dfs(TreeNode* node) {
        // base case
        if (!node) return 0;
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        // progress
        ans = max(ans, left+right);

        return 1+max(left, right);
        
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // Basic Idea: DFS + longest length

        ans=0;

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
    cout << s.diameterOfBinaryTree(new TreeNode(1)) << endl;  // expect: 0

    return 0;
}
