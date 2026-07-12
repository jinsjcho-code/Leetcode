// ===== 230. Kth Smallest -- OPTIMIZED (stop early, no vector) =====
//
// The simple version walks the WHOLE tree into a vector, then reads v[k-1].
//   Time O(N), Space O(N)   -- even when k == 1!  Wasteful.
//
// Better: walk inorder (smallest first) and COUNT as you go.
// The moment you reach the k-th node, that's the answer -- stop.
//   Time O(H + k), Space O(H)   -- no vector at all.
//
//     3
//    / \        inorder visits: 1, 2, 3, 4
//   1   4       k=2 -> we can stop right after visiting 2!
//    \
//     2
//
// ---------------------------------------------------------------
// FILL IN FIRST:
//
//   (1) What does the helper RETURN?
//       -> nothing
//
//   (2) Base case?
//       -> check the null node
//
//   (3) What state do I need to carry?  (this is shape B!)
//       -> accumulate
// ---------------------------------------------------------------
//
// HINT: you need TWO pieces of state that survive across calls:
//         - how many nodes have I visited so far?  (a counter)
//         - the answer, once found
//       Members, or pass them by reference (int& count, int& ans).
//
//       And to actually STOP early, add a guard at the top:
//         if (already found) return;      // don't keep walking
//
// (Recursion_Cards.md: shape B = accumulator. Reminder: a plain
//  `return` only exits ONE call -- the parents keep going unless you
//  guard against it.)

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
    int count;
    int ans;

    void inorderDFS(TreeNode* node, int k) {
        if (!node) return;
        if (count > k) return;

        inorderDFS(node->left, k);
        count++;
        if (count == k) {
            ans = node->val;
            return;
        }

        inorderDFS(node->right, k);

    }
    int kthSmallest(TreeNode* root, int k) {
        count=0;
        ans=0;

        inorderDFS(root, k);

        return ans;

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
    cout << s.kthSmallest(b, 1) << endl;   // 1
    cout << s.kthSmallest(b, 3) << endl;   // 3
    cout << s.kthSmallest(b, 6) << endl;   // 6

    return 0;
}
