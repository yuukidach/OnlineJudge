class MinStack {
public:
    vector<int> a;
    multiset<int> b;

    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        a.push_back(x);
        b.insert(x);
    }
    
    void pop() {
        int tmp = a[a.size()-1];
        a.erase(--a.end());
        b.erase(b.lower_bound(tmp));
    }
    
    int top() {
        return a[a.size()-1];
    }
    
    int getMin() {
        return *(b.begin());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */