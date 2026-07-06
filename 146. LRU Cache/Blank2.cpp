// ===== Blank retry #2 + NARRATE practice: 146 LRU Cache =====
//
// CoderPad gives you nothing - write #include / main() yourself!
// (Don't peek at Solution.cpp / Solution_STL.cpp / Blank.cpp!)
//
// [Problem] Design an LRU cache with fixed capacity. All ops O(1):
//   - LRUCache(int capacity)
//   - int  get(int key):            return value if present (and mark MRU),
//                                    else return -1.
//   - void put(int key, int value): insert/update (mark MRU).
//                                    If over capacity, evict the LRU item.
//
// This round: SPEAK as you code (in English). For each step say:
//   - what data structure and WHY
//   - the hardware angle: "this is the eviction policy a cache
//     controller uses for the memory hierarchy"
//
// Steps (small + Run): skeleton -> members/ctor -> get -> put/evict
//
// Start from a blank slate below:

#include <bits/stdc++.h>
using namespace std;


class LRUCache {
private:
    list<pair<int, int>> items; // key, value
    unordered_map<int, list<pair<int,int>>::iterator> LRU;
    int cap;

public:
    LRUCache(int capacity) {
        cap = capacity;
        
    }

    //   - int  get(int key):            return value if present (and mark MRU),
//                                    else return -1.
    int get(int key) {
        // if not present return -1
        if(LRU.find(key) == LRU.end()) return -1;

        // if present -> return value
        auto it = LRU[key];
        
        //update the cache
        items.splice(items.begin(), items, it);

        return it->second;
    }

    //   - void put(int key, int value): insert/update (mark MRU).
//                                    If over capacity, evict the LRU item.

    void put(int key, int value) {
        // if key present -> update
        if(LRU.find(key) != LRU.end()) {
            auto it = LRU[key];
            it->second = value;
            
            items.splice(items.begin(), items, it);

            return;
        }

        // if key not present -> insert
        items.push_front({key, value});
        
        auto it = items.begin();
        LRU[key] = it;

        // check the evict condition
        if (LRU.size() > cap) {
            // find oldkey for LRU
            int oldkey = items.back().first;

            // delete the evict in the items
            items.pop_back();

            // delete the evict in the LRU
            LRU.erase(oldkey);
        }
    }

};

int main() {
    LRUCache lru(2);

    lru.put(1, 1); // {1, 1}
    lru.put(2, 2); // RU {2, 2} - {1, 1} -> LRU
    cout << lru.get(1) << endl; // return 1, {1, 1} - {2, 2}
    lru.put(3, 3);  // {3, 3} - {1, 1} - {2, 2} -> evict in the cache
    cout << lru.get(2) << endl; // return -1


    return 0;
}
