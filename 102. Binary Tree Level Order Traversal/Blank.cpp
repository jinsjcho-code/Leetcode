// ===== Day 4: 102. Binary Tree Level Order Traversal =====
//
// Return the node values level by level (top to bottom, left to right).
//
//        3               ->  [[3],
//       / \                   [9, 20],
//      9   20                 [15, 7]]
//         /  \
//        15   7
//
//   vector<vector<int>> levelOrder(TreeNode* root);
//
// NEW TOOL: this is BFS (breadth-first search), not recursion!
//   Use a QUEUE. Process one whole level at a time:
//
//   push root into queue
//   while queue is not empty:
//       levelSize = queue.size()          <-- how many nodes on THIS level
//       for i in 0..levelSize-1:
//           node = queue.front(); queue.pop()
//           add node->val to this level's vector
//           push node->left  (if not null)
//           push node->right (if not null)
//       append this level's vector to the answer
//
// KEY TRICK: capture queue.size() BEFORE the inner loop -- it changes
// as you push children!
//
// DFS (recursion) goes deep; BFS (queue) goes wide, level by level.

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Idea: BFS algorithm
        // Shoud I make a map visited? But it's a tree not a array
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        // base case
        if (!root) {
            return {};  // how can i return type of vector<vector<int>>? 
        } 

        // progress
        q.push(root);
        while (!q.empty()) {
            int levelsize = q.size();
            vector<int> level;
            
            for (int i = 0 ; i <levelsize ; i++) {
                TreeNode* t;

                t = q.front();
                q.pop();

                level.push_back(t->val);

                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                
            }

            ans.push_back(level);
           
        }

        return ans;
    }
};

int main() {
    //        3
    //       / \
    //      9   20
    //         /  \
    //        15   7
    TreeNode* root = new TreeNode(3);
    root->left  = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left  = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    vector<vector<int>> ans = s.levelOrder(root);

    for (const vector<int>& level : ans) {       // expect: 3 / 9 20 / 15 7
        for (int v : level) cout << v << " ";
        cout << endl;
    }

    // edge case: empty tree -> prints nothing
    cout << "--- empty tree ---" << endl;
    vector<vector<int>> e = s.levelOrder(nullptr);
    cout << "levels: " << e.size() << endl;      // 0
    return 0;
}
