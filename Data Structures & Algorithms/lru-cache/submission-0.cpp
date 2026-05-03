class LRUCache {
public:
    LRUCache(int capacity) {
        max_capacity = capacity;
    }
    
    // return value corresponding to key if exists, otherwise return -1
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        } else {
            auto it = key_loc[key];
            q.erase(it);
            add_back(key);
            cout << "got key: " << key << ", value: " << cache[key] << "\n";
            return cache[key];
        }
    }
    
    // update value of key if key exists, otherwise add kv pair to cache
    // if new cv pair causes cache to exceed capacity, remove least recently used key
    // FIFO = queue but also have to move key to back if get or put with existing key
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            if (cache.size() + 1 > max_capacity) {
                int to_remove = q.front();
                q.pop_front();
                key_loc.erase(to_remove);
                cache.erase(to_remove);
                cout << "erased " << to_remove << " from queue\n";
            }
            add_back(key);
            cache[key] = value;
            cout << "put key: " << key << ", value: " << value << "\n";
        } else {
            auto it = key_loc[key];
            q.erase(it);
            add_back(key);
            cache[key] = value;
            cout << "put key: " << key << ", value: " << value << "\n";
        }
    }

private:
    unordered_map<int, int> cache;
    unordered_map<int, _List_iterator<int>> key_loc;
    list<int> q;
    int max_capacity;

    void add_back(int key) {
        auto it = q.insert(q.end(), key);
        key_loc[key] = it;
    }
};
