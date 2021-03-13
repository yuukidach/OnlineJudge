class MyHashSet {
private:
    const int M = 997;
    vector<list<int>> data;

    int hash(int key) {
        return key % M;
    }

public:
    /** Initialize your data structure here. */
    MyHashSet(): data(M) {

    }
    
    void add(int key) {
        int idx = hash(key);
        for(auto k : data[idx]) {
            if (k == key) return;
        }
        data[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = hash(key); 
        for (auto it = data[idx].begin(); it != data[idx].end(); ++it) {
            if ((*it) == key) {
                data[idx].erase(it);
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int idx = hash(key);
        for(auto k : data[idx]) {
            if (k == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */