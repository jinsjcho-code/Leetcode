// ===== Practice (CoderPad style): 338. Counting Bits =====
//
// CoderPad gives you nothing - write #include / main() yourself!
//
// [Problem]
//   Given an integer n, return an array 'ans' of length n+1 where
//   ans[i] = number of 1 bits in i, for every i from 0 to n.
//
//   Examples:
//     n = 2  -> [0, 1, 1]
//        (0=0b0->0, 1=0b1->1, 2=0b10->1)
//     n = 5  -> [0, 1, 1, 2, 1, 2]
//        (3=0b11->2, 4=0b100->1, 5=0b101->2)
//
//   vector<int> countBits(int n);
//
// Approach 1 (simple): for each i, count its bits like problem 191.
// Approach 2 (O(n) DP): reuse a previous answer.
//     ans[i] = ans[i >> 1] + (i & 1)
//     (i>>1 drops the last bit; add 1 if the last bit was set)
//
// Hardware angle: "Building a lookup table of popcounts - each entry
//   reuses a smaller shifted result, like a prefix computation."
//
// Steps: skeleton -> logic -> test
//
// Start from a blank slate below:

#include <bits/stdc++.h>
using namespace std;

class Counting_Bits {
private:

public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0)
        int cnt;
        int bits;

        for (int i =0 ; i<=n ; i++) {
            bits = i;
            cnt=0;

            while (bits>0) {
                if (bits&1) {
                    cnt++;
                }

                bits = bits >> 1;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

int main () {

    Counting_Bits cb;

    vector<int> ans = cb.countBits(2);

    for (int i : ans) {
        cout << i << endl;
    }

      vector<int> ans2 = cb.countBits(5);

    for (int i : ans2) {
        cout << i << endl;
    }


    return 0;
}