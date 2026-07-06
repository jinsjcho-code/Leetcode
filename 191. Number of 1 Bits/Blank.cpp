// ===== Practice (CoderPad style): 191. Number of 1 Bits =====
//
// CoderPad gives you nothing - write #include / main() yourself!
//
// [Problem]
//   Given an unsigned integer n, return the number of '1' bits
//   in its binary representation (a.k.a. the popcount / Hamming weight).
//
//   Examples:
//     n = 11   (binary 1011)      -> 3
//     n = 128  (binary 10000000)  -> 1
//     n = 255  (binary 11111111)  -> 8
//
//   int hammingWeight(uint32_t n);   // or int / unsigned
//
// Bit tools:
//   n & 1     -> is the last bit 1?
//   n >>= 1   -> shift right by one (drop last bit)
//   loop while n != 0
//
// Hardware angle to say out loud:
//   "Population count is a single instruction (popcnt) on modern CPUs;
//    on an ASIC it's just a tree of adders."
//
// Steps: skeleton -> logic -> test
//
// Start from a blank slate below:

//Goal: check the how many count 1 bits in the numbers.
// Basic Idea:
// 1) decimal -> binary -> count the 1 bits
// 2)  11 -> 1011  
//             &1 = 1
// 3)        1011 >> 1 -> 101
//                         &1
//                          1
//                      101 >> 1 -> 10
//                                  &1
//                                   0

// Time: O(1), Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class hamming {
private:

public:
    hamming() {

    }

    int hammingWeight(uint32_t n) {
        int cnt=0;
        
        while (n>0) {
            if (n&1) {
                cnt++;
            }

            n = n >> 1;
        }
    
        return cnt;
    }


};

int main() {
    hamming h;

    cout << h.hammingWeight (11) << endl;
    cout << h.hammingWeight (128) << endl;
    cout << h.hammingWeight (255) << endl;

    return 0;
}
