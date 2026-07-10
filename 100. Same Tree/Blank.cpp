// ===== Day 3: 100. Same Tree =====
//
// Given the roots of two binary trees p and q, return true if they are
// THE SAME: identical structure AND identical values.
//
//   p:   1        q:   1         -> true
//       / \           / \
//      2   3         2   3
//
//   p:   1        q:   1         -> false  (different structure)
//       /               \
//      2                 2
//
//   p:   1        q:   1         -> false  (different values)
//       / \           / \
//      2   1         1   2
//
//   bool isSameTree(TreeNode* p, TreeNode* q);
//
// RECURSION on TWO trees at once. Think about the base cases:
//   - both nullptr           -> ?
//   - exactly one is nullptr -> ?
//   - values differ          -> ?
//   - otherwise -> compare left-with-left AND right-with-right
//
// (Both subtrees must match -> use && )

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Idea: Compare the each node

        // base case
        if (!p && !q) return true; // 둘다없음 -> true
        if (!p || !q) return false; // 하나만 없음 -> false
        if (p->val != q->val) return false; // 값이 다름 -> false

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main() {
    Solution s;

    // Test 1: same          1        1
    //                      / \      / \
    //                     2   3    2   3
    TreeNode* a = new TreeNode(1);
    a->left = new TreeNode(2); a->right = new TreeNode(3);
    TreeNode* b = new TreeNode(1);
    b->left = new TreeNode(2); b->right = new TreeNode(3);
    cout << s.isSameTree(a, b) << endl;   // 1 (true)

    // Test 2: different structure   1        1
    //                              /          \
    //                             2            2
    TreeNode* c = new TreeNode(1); c->left  = new TreeNode(2);
    TreeNode* d = new TreeNode(1); d->right = new TreeNode(2);
    cout << s.isSameTree(c, d) << endl;   // 0 (false)

    // Test 3: different values      1        1
    //                              / \      / \
    //                             2   1    1   2
    TreeNode* e = new TreeNode(1);
    e->left = new TreeNode(2); e->right = new TreeNode(1);
    TreeNode* f = new TreeNode(1);
    f->left = new TreeNode(1); f->right = new TreeNode(2);
    cout << s.isSameTree(e, f) << endl;   // 0 (false)

    // Test 4: both empty
    cout << s.isSameTree(nullptr, nullptr) << endl;   // 1 (true)

    return 0;
}
