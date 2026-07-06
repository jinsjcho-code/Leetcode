// ===== Practice (CoderPad style): 136. Single Number =====
//
// CoderPad gives you nothing - write #include / main() yourself!
//
// [Problem]
//   Given a non-empty array where EVERY element appears TWICE except
//   for one, find that single one.
//   Requirement: O(n) time and O(1) extra space.
//
//   Examples:
//     [2,2,1]        -> 1
//     [4,1,2,1,2]    -> 4
//     [1]            -> 1
//
//   int singleNumber(vector<int>& nums);
//
// Key XOR facts:
//   a ^ a = 0      (a number XOR itself cancels to 0)
//   a ^ 0 = a      (XOR with 0 leaves it unchanged)
//   XOR is commutative: order doesn't matter
//
// Hardware angle to say out loud:
//   "XOR is a single logic gate - this is why hardware parity checks
//    use it. Pairs cancel, the odd one out survives."
//
// Steps: skeleton -> logic -> test
//
// Start from a blank slate below:

// Goal: check only one number.
// XOR facts
// a ^ a = 0
// a & 0 = a

#include <bits/stdc++.h>
using namespace std;

class Single_Number {
private:    
public:
    int singleNumber(vector<int>& nums) {
        int ans =0;
        for (int i = 0 ; i < nums.size() ; i++) {
            ans = ans^nums[i];
        }

        return ans;
    }

};

int main () {
    Single_Number s;
    
    vector<int> v = {2, 2,1};    
    cout << s.singleNumber(v) << endl;

    return 0;
}
