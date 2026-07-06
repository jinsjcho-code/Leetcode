// ===== 338. Counting Bits - DP version (O(n)) =====
//
// Idea: ans[i] = ans[i >> 1] + (i & 1)
//   - i >> 1  : drop the last bit of i -> a SMALLER number we already solved
//   - i & 1   : the last bit we dropped (0 or 1)
//   So the count for i = (count for the smaller number) + (that last bit)

#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
    // Make an array of size n+1, all filled with 0.
    // ans[0] is already correct: 0 has zero 1-bits.
    vector<int> ans[6];

    // Fill from 1 up to n. Each ans[i] REUSES an earlier answer.
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i >> 1] + (i & 1);
    }

    return ans;
}

int main() {
    vector<int> ans = countBits(5);
    for (int x : ans) cout << x << " ";   // expect: 0 1 1 2 1 2
    cout << endl;
    return 0;
}
