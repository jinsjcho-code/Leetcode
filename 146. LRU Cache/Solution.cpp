class LRUCache {
private:
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int cap=0;

    unordered_map<int, Node*> LRU;

    void remove(Node* node) { // helper #1: remove the node
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        head->next = node;
    }

public:

    LRUCache(int capacity) {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        cap=capacity;
    }
    
    int get(int key) {
        // if key doesn't exist then return -1
        if (LRU.find(key) == LRU.end()) return -1;

        // if key exist, return value;
        else {
            Node* node = LRU[key];
            remove(node);
            addFront(node);
            return node->val;
        }
    }
    
    void put(int key, int value) {
        // if key exist then update the value;
        if (LRU.find(key)!=LRU.end()) {
            Node* node = LRU[key];
            node->val = value;
            remove(node);
            addFront(node);
            return;
        }

        Node* node = new Node(key, value);
        addFront(node);
        LRU[key] = node;

        if (LRU.size() > cap) {
            Node* current= tail->prev;
            
            current->prev->next = tail;
            tail->prev = current->prev;
            LRU.erase(current->key);
            delete current;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */