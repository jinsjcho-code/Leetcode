// ===== Practice (CoderPad style): 1. Two Sum =====
//
// CoderPad gives you nothing - write #include / main() yourself!
//
// [Problem]
//   Given an array nums and an integer target, return the INDICES of
//   the two numbers that add up to target.
//   Exactly one solution exists; you may not use the same element twice.
//
//   Examples:
//     nums=[2,7,11,15], target=9  -> [0,1]   (2+7=9)
//     nums=[3,2,4],     target=6  -> [1,2]   (2+4=6)
//     nums=[3,3],       target=6  -> [0,1]
//
//   vector<int> twoSum(vector<int>& nums, int target);
//
// Hint (O(n) with a hash map):
//   For each number x at index i, the number you NEED is (target - x).
//   Have you seen (target - x) before? Store each number -> its index
//   in a map as you go, and check the map for the complement.
//
// Steps: skeleton -> logic -> test
//
// Start from a blank slate below:

// Goal: Find a sum value using two numbers
// Idea#1: Brute force O(N^2)
// for + for

// Idea#2: Hash -> O(1)

#include <bits/stdc++.h>
using namespace std;


class Two_Sum {
private:
        
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
    
        for (int i =0 ; i<nums.size() ; i++) {
            int need = target - nums[i];

            if (table.find(need) != table.end()) {
                return {table[need], i};
            }
            table[nums[i]] = i;
        
            
        }
        return {0,0};
    }
};

int main () {
    Two_Sum ts;
    vector<int> v = {3,2,4};
    vector<int> r = ts.twoSum(v, 6);
    cout << r[0] << " " << r[1] << endl;   // 1 2

    return 0;
}

