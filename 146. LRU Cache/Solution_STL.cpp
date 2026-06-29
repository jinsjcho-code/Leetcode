class LRUCache {
private:
    int cap;
    list<pair<int, int>> items;
    unordered_map<int, list<pair<int, int>>::iterator> LRU;


public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // if key doesn't exit return
        if (LRU.find(key) == LRU.end()) {
            return -1;
        }
        
        // check key exist
        auto it = LRU[key];
        items.splice(items.begin(), items, it);

        return it->second;
    }
    
    void put(int key, int value) {
        // key exist then update
        if (LRU.find(key) != LRU.end()) {
            auto it = LRU[key];
            it->second = value;

            items.splice(items.begin(), items, it);
            return;
        }

        // key doesn't exist, then add key-value pair
        //key, key, value인건가???
        items.push_front({key, value});
        auto it = items.begin();
        LRU[key] = it;

        // evict check
        if (LRU.size() > cap) {
            int oldkey = items.back().first;
            
            items.pop_back();
            LRU.erase(oldkey);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */