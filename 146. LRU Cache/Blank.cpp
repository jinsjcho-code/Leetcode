// ===== Blank retry (CoderPad style): 146 LRU Cache =====
//
// CoderPad는 #include / main()을 안 줌. 전부 직접 작성!
// (Solution.cpp / Solution_STL.cpp / Rehearsal.cpp 보지 말기!)
//
// [Problem] Design an LRU cache with fixed capacity. All ops O(1):
//   - LRUCache(int capacity)
//   - int  get(int key):            return value if present (and mark MRU),
//                                    else return -1.
//   - void put(int key, int value): insert/update (mark MRU).
//                                    If over capacity, evict the LRU item.
//

// Design an LRU cache

#include<bits/stdc++.h>
using namespace std;

class LRUCache {

    // Basic idea: Linked list which manage the LRU cache;
    // cache: hash table -> unorderd_map : O(1), space: O(N)
    // list<pair<int, int>> items;
    // unordered_map<int, list<pair<int, int>>::iterator> LRU;


private:
    list<pair<int, int>> items;
    unordered_map<int, list<pair<int, int>>::iterator> LRU;
    int cap;   // capacity

public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    //   - int  get(int key):            return value if present (and mark MRU),
//                                    else return -1.
    int get(int key) {
        // if it is not present return -1
        if (LRU.find(key) == LRU.end()) return -1;

        // if exist, then return value
        auto it = LRU[key];
        
        // LRU Cache
        items.splice(items.begin(), items, it);  // head -> List #1 -> List #2 -> Tail
        return it->second;

    }
    
    //   - void put(int key, int value): insert/update (mark MRU).
//                                    If over capacity, evict the LRU item.

    void put(int key, int value) {
        // if present then update
        if (LRU.find(key) != LRU.end()) {
            auto it = LRU[key];
            
            it->second = value;
            items.splice(items.begin(), items, it);
            return ;
        }

        // if not present, then add key-value pair
        items.push_front({key, value});
        
        auto it = items.begin();
        LRU[key] = it;

        // check the evict condition and evict
        if (LRU.size() > cap) {
            int oldkey = items.back().first;
            
            
            LRU.erase(oldkey);
            items.pop_back();
        }
    }

    
};

int main() {
    LRUCache lru(2);
    lru.put(1,1);
    lru.put(2,2);
    cout << lru.get(1) << endl;  // 1 : (2,2) -> (1,1)
    lru.put(3,3);                // evict 1 (3,3) -> (2,2) -> evict(1,1)
    cout << lru.get(2) << endl;  // 2 (2,2) -> (3,3)
    cout << lru.get(3) << endl;  // 3 (3,3) -> (2,2)
    lru.put(4,4);                // evict? (4,4) -> (3,3) -> evict (2,2)
    cout << lru.get(1) << endl;  // return -1
    cout << lru.get(3) << endl;  // 3 (3,3) -> (4,4)
    cout << lru.get(4) << endl;  // 4 (4,4) -> (3,3)
    return 0;
}