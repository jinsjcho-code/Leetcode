// ===== Mock Interview (CoderPad style): RandomizedSet =====
//
// Design a data structure that supports these operations, each in
// AVERAGE O(1) time:
//
//   - insert(val): insert val if not already present.
//                  return true if inserted, false if already present.
//   - remove(val): remove val if present.
//                  return true if removed, false if not present.
//   - getRandom(): return a random element. Every element must have
//                  EQUAL probability of being returned.

#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;              // holds the actual values (for O(1) random access)
    unordered_map<int, int> pos;   // value -> its index in nums

public:
    RandomizedSet() {
        // nothing to initialize; nums and pos start empty
    }

    bool insert(int val) {
        // already present -> do nothing, return false
        if (pos.find(val) != pos.end()) return false;

        // new value: append to vector, record its index
        pos[val] = nums.size();    // its index will be the current last slot
        nums.push_back(val);
        return true;
    }

    bool remove(int val) {
        // not present -> return false
        if (pos.find(val) == pos.end()) return false;

        int i    = pos[val];        // index of the value we remove
        int last = nums.back();     // value currently at the end

        // move the last value into the hole, fix its index in the map
        nums[i]   = last;
        pos[last] = i;

        // drop the last slot (now a duplicate) and erase val from the map
        nums.pop_back();
        pos.erase(val);
        return true;
    }

    int getRandom() {
        // every index equally likely -> uniform
        return nums[rand() % nums.size()];
    }
};

int main() {
    RandomizedSet s;
    cout << s.insert(1) << endl;   // expect 1 (true)
    cout << s.insert(1) << endl;   // expect 0 (false, already there)
    cout << s.remove(2) << endl;   // expect 0 (false, not there)
    cout << s.insert(2) << endl;   // expect 1 (true)
    cout << s.remove(1) << endl;   // expect 1 (true)
    cout << s.insert(2) << endl;   // expect 0 (false, already there)
    cout << s.getRandom() << endl; // expect 2 (only element left)
    return 0;
}
