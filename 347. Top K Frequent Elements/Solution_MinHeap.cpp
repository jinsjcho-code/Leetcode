// ===== 347. Top K Frequent -- MIN-HEAP (size k) version =====
//
// Mock interview
// 1. Clarify 
// Let me make sure I understand the problem. I'm given an array and an integer k.
// I need to return a vector contanining the TOP K most frequent elements.
// For example, if the array is [1,1,1,2,2,3]... Top 1 is 1, Top 2 is 2. So I need to return 1,2"

// 2. Approach
// Before I start coding, Let me walk through my approach.
// The brute-force approach would be to sort the array first, which would work but take O(n log n)
// After sorting, I'd pick the top K. Overall, it takes O(N log N)

// My approach is to use a min-heap. First a hash map counts the frequencies, then a heap keeps the top K.
// Using heap, time complexity is O(nlogK). When k is small, it's faster than brute-force.

// Does that approach sound resonable?


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    // 3. Narrate
    // "I'll start by defining a min-heap. In C++ that's a priority_queue with `greater`, which puts the smallest element on top" 
    

        unordered_map<int, int> hash;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;

    // "Now I'll iterate through the array, and for each number I increment its count in the hash map."
        for (int x:nums) {
            hash[x]++;
        }


    // "Now I'll iterate through the hash map, and for each counter and number pair I push it onto the min-heap."

        for (auto& p:hash) {
            min_heap.push({p.second, p.first});

            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

    // "I'll define the answer vector for return"
        vector<int> ans;
     
    // "pop everything from the heap, and push each number onto the answer array."
        int c= min_heap.size();
        for (int i =0 ; i<c ; i++) {
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return ans;

        //"Let me run it to check"

        
    }
};
// 4. Test
//"Let me trace through [1,1,1,2,2,3] with k = 2. The counts are 1→3, 2→2, 3→1. The min-heap keeps the two highest-count entries, {2:2, 1:3}, so the answer is [1, 2]."


//"Let me also think about edge cases:
// - "If k equals the number of distinct elements, I return all of them."
// - "If every element is unique, any k of them is valid — they all tie."
// - "Duplicates are the whole point here — that's what I'm counting."

// 5. Complexity
// "Time is O(n + m log k), where m is the number of distinct elements. 
//  Space is O(m) overall — the hash map dominates; the heap itself is O(k)."


// 6. Wrap up
// "there's also an O(n) bucket-sort approach — since frequencies range 
//  from 1 to n, I can bucket numbers by their frequency and read off 
//  the top k."


// ---- given: compares ignoring order ----
bool sameSet(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

int main() {
    Solution s;

    vector<int> a = {1,1,1,2,2,3};
    cout << sameSet(s.topKFrequent(a, 2), {1,2}) << endl;       // 1

    vector<int> b = {1};
    cout << sameSet(s.topKFrequent(b, 1), {1}) << endl;         // 1

    vector<int> c = {4,4,4,5,5,6,6,6,6,7};
    cout << sameSet(s.topKFrequent(c, 2), {6,4}) << endl;       // 1

    vector<int> d = {1,2,3,4,5};
    cout << sameSet(s.topKFrequent(d, 5), {1,2,3,4,5}) << endl; // 1

    vector<int> e = {5,5,5,5};
    cout << sameSet(s.topKFrequent(e, 1), {5}) << endl;         // 1

    // 힙에 뭐가 남는지 눈으로 보기
    vector<int> f = {1,1,1,2,2,3};
    cout << "--- top 2 of {1,1,1,2,2,3}: ";
    for (int x : s.topKFrequent(f, 2)) cout << x << " ";
    cout << endl;   // 2 1  (빈도 낮은 것부터 나옴 -- 순서는 무관)

    return 0;
}
