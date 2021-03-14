class MyHashMap {
private:
    const int M = 997;
    vector<list<pair<int, int>>> data;

    int hash(int keys) {
        return keys % M;
    }

public:
    /** Initialize your data structure here. */
    MyHashMap():data(M) {

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = hash(key);
        for (auto &p : data[idx]) {
            if (key == p.first) {
                p.second = value;
                return;
            }
        }

        data[idx].emplace_back(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = hash(key);
        for (auto &p : data[idx]) {
            if (key == p.first) return p.second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx = hash(key);
        for (auto it = data[idx].begin(); it != data[idx].end(); ++it) {
            if (key == it->first) {
                data[idx].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */