class LRUCache {
// define linked list and hash table for key is good structure for this.
   
// 1) Define the List
//   Head(dummy) - List#1 - List#2 - List#3 .... - Tail (Dummy)
// 2) Hash table
//   Key | List // Hash table
// 3) function 
//  - remove
//  - AddFront

private:
    struct Node {
        int key, value;
        Node* next;
        Node* prev;
        
        Node (int k, int v): key(k), value(v), next(nullptr), prev(nullptr) {}
     
    };

    Node* head;
    Node* tail;
    int cap=0;

    unordered_map<int, Node*> LRU;

    void remove(Node* node) { // Goal: disconnect link prev and next;
        // Head - List#1 - List#2 - List#3 - tail
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addFront(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }


 public:
    LRUCache(int capacity) {
        // Define cap to decide evict condition
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next =tail;
        tail->prev = head;
        cap = capacity;
    }
    
    int get(int key) {
        // need to check key
        // if it has the key return value
        // otherwise, return -1;

        // Hash table(LRU) set the LRU based on key
        // Head - List#1 - List#2 - Tail
        // Head - List#2 - List#1 - Tail

        // remove -> AddFront
        if (LRU.find(key) == LRU.end()) {
            return -1;
        }

        Node* node = LRU[key];

        remove(node);
        addFront(node);

        return node->value;
    }
    
    void put(int key, int value) {
        // 1) update the key
        //   - update the LRU
        // 2) If it doesn't have the key, add key-value pair
        //   - update the LRU
        // 3) check the evict condition and evcit when it has more than cap
        //   - check the evict condition (cap > hash.size())
        //   -- if yes, evict near the tail
        

        if (LRU.find(key)!= LRU.end()) { //  exist key
            Node* node = LRU[key];
            node->value = value;
            
            remove(LRU[key]);
            addFront(LRU[key]);
            return;
        }

        // doesn't exist key
        Node* node = new Node(key, value);
        LRU[key] = node;
        addFront(LRU[key]);

        //evict
        if (LRU.size() > cap) {
            Node* node = tail->prev;

            remove (node);
            LRU.erase(node->key);
            delete node;
        }

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */