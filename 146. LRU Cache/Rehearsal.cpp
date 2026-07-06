// ===== CoderPad-style (hard mode): 146 LRU Cache =====
// (Do NOT look at Solution.cpp / Solution_STL.cpp!)
//
// [Interviewer prompt]
//   Design an LRU (Least Recently Used) cache with a fixed capacity:
//     - get(key):  return the value if the key exists and mark it as most
//                  recently used; otherwise return -1.
//     - put(key, value):  insert or update, and mark as most recently used.
//                  If over capacity, evict the least recently used item.
//   Both get and put must run in O(1) average time.
//
// Write the full class yourself, including the signatures.
// (Infer them from how main() below calls it.)
//   - LRUCache(int capacity)
//   - int get(int key)
//   - void put(int key, int value)
//
// Practice: write the whole class -> Run -> output should be  1/-1/-1/3/4/33

#include<bits/stdc++.h>
using namespace std;


// vvv  Write the entire LRUCache class here (including signatures)  vvv
class LRUCache {
private:
    // define the struct Node* (List)
    // hash table <int key, Node*> -> key - Node* (list)
    // head(dummy) -> List #2 -> List #1 -> List #3 -> tail(dummy)
    // capacity < size of list: evict the Least Recently used list. 
    struct Node {
        int key, value;
        Node* prev;
        Node* next;

        Node (int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {} // How can I call this fucntion in english?
    };
    
    int cap=0; // manage for capacity
    Node* head;
    Node* tail;
    
    unordered_map<int, Node*> LRU;
    
    // void remove(Node* node)
    void remove(Node* node) {
        // head -> List #1 -> List #2 -> List #3 -> Tail
        //                       o
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    // void addFront(Node* node)
    void addFront(Node* node) {
        // head -> List #1 -> List #2 -> List #3 -> Tail
        //            o
        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        head->next = node;       
    }


public:
    LRUCache(int capacity) {  // Q.여기서 LRUCache는 calss의 이름하고 같은건가? int랑 void형이 아닌데 어떻게 해석해?
        // initilize cap, head, tail, connect between head and tail
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        // If key doesn't exit then return -1
        if (LRU.find(key) == LRU.end()) return -1;

        // if has key, then set the LRU and return the value: Time: O(1), Space: O(N) ? O(1)?
        auto it = LRU[key];
        remove(it);
        addFront(it);
        
        return it->value;
    }

    void put(int key, int value) { // Time: O(1), Space: O(N)?
        // If key exist then update the value and return
        if (LRU.find(key)!=LRU.end()) {
            auto it = LRU[key];
            it->value = value;

            remove(it);
            addFront(it);

            return;
        }


        // If key doesn't exist then add key-value pair in the Lists and LRU updated
        Node* node = new Node(key, value);
        
        LRU[key] = node;
        addFront(LRU[key]);

        
        // check evict condition (size > cap), then evict LRU lists.
        if (LRU.size() > cap) {
            auto it = tail->prev;
            int oldkey = it->key;

            remove(it);
            LRU.erase(oldkey);
            delete it;
            
        }
    }
};



// ^^^  End of class  ^^^


// ===== Tests =====
int main() {
    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    cout << cache.get(1) << endl;   // expect: 1
    cache.put(3,3);                 // evicts key 2
    cout << cache.get(2) << endl;   // expect: -1
    cache.put(4,4);                 // evicts key 1
    cout << cache.get(1) << endl;   // expect: -1
    cout << cache.get(3) << endl;   // expect: 3
    cout << cache.get(4) << endl;   // expect: 4
    cache.put(3,33);                // update existing
    cout << cache.get(3) << endl;   // expect: 33
    return 0;
}
