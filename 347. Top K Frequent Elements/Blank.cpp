// ===== Day 8: 347. Top K Frequent Elements  (heap + hashmap) =====
//
// Return the k most FREQUENT elements. (Any order is fine.)
//
//   nums=[1,1,1,2,2,3], k=2   -> [1,2]     (1 appears 3x, 2 appears 2x)
//   nums=[1], k=1             -> [1]
//
//   vector<int> topKFrequent(vector<int>& nums, int k);
//
// ---------------------------------------------------------------
// This combines TWO things you already know:
//   1) unordered_map  -> count how often each number appears
//   2) heap           -> keep the top k by that count
//
// PLAN:
//   (a) Count frequencies:  unordered_map<int,int> freq;
//   (b) Push (count, number) pairs into a MIN-heap of size k.
//       If the heap grows past k -> pop (that throws out the LEAST
//       frequent one so far).
//   (c) Whatever's left in the heap = the k most frequent.
//
// Heap of pairs:
//   priority_queue<pair<int,int>,
//                  vector<pair<int,int>>,
//                  greater<pair<int,int>>> minHeap;   // smallest .first on top
//
//   push {count, number}  -- put COUNT first so the heap orders by count!
//   minHeap.top().second  -> the number
//
//   SIGNAL: "top K" -> heap of size K.
// ---------------------------------------------------------------
//
// FILL IN:
//   (1) What do I count, with what?  -> frequently number
//   (2) What goes in the heap, in what order?  -> {count, number}
//   (3) Time / Space?  ->
//
// (Bonus: there's an O(n) "bucket sort" solution too -- try it after.)


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> hash;

        for (int x:nums) {
            if (hash.find(x) == hash.end()) { // is that empty?
            }
        
            hash[x]++;
        }

        for (auto& p : hash) {
            pq.push({p.second, p.first});
        }        

        vector<int> ans;

        for (int i = 0 ; i<k ; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;

    }
};

// ---- given: compares ignoring order ----
bool sameSet(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

int main() {
    Solution s;

    vector<int> a = {1,1,1,2,2,3};
    cout << sameSet(s.topKFrequent(a, 2), {1,2}) << endl;      // 1

    vector<int> b = {1};
    cout << sameSet(s.topKFrequent(b, 1), {1}) << endl;        // 1

    vector<int> c = {4,4,4,5,5,6,6,6,6,7};
    cout << sameSet(s.topKFrequent(c, 2), {6,4}) << endl;      // 1  (6:4x, 4:3x)

    vector<int> d = {1,2,3,4,5};
    cout << sameSet(s.topKFrequent(d, 5), {1,2,3,4,5}) << endl; // 1 (all tie)

    vector<int> e = {5,5,5,5};
    cout << sameSet(s.topKFrequent(e, 1), {5}) << endl;         // 1

    return 0;
}
