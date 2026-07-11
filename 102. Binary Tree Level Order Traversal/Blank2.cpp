// ===== 102. Level Order Traversal -- retry (NO hints) =====
//
// Return node values level by level (top->bottom, left->right):
//        3               ->  [[3], [9,20], [15,7]]
//       / \
//      9   20
//         /  \
//        15   7
//
//   vector<vector<int>> levelOrder(TreeNode* root);
//
// You've got this. Think: which data structure processes things
// in the order they arrive? And how do you know where one level ends?

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Basic Idea: BFS
        // It's not use recursive function.
        
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        
        // edge case 
        if (!root) return {};
        
        q.push(root);
        
        // queue 
        while (!q.empty()) {
            vector<int> level;

            int level_size = q.size();

            for (int i =0 ; i < level_size ; i++) {
                TreeNode* t;

                t=q.front();
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
    TreeNode* root = new TreeNode(3);
    root->left  = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left  = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    for (const vector<int>& level : s.levelOrder(root)) {
        for (int v : level) cout << v << " ";
        cout << endl;
    }
    // expect: 3 / 9 20 / 15 7

    cout << "--- empty ---" << endl;
    cout << "levels: " << s.levelOrder(nullptr).size() << endl;   // 0
    return 0;
}
