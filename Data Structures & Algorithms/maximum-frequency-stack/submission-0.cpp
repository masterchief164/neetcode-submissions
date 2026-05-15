class FreqStack {
    priority_queue<vector<int>> pq;
    unordered_map<int, int> freq;
    int index;

public:
    FreqStack() {
        index = 0;
    }
    
    void push(int val) {
        freq[val]++;
        pq.push({freq[val], index++, val});
    }
    
    int pop() {
        auto tmp = pq.top();
        pq.pop();
        freq[tmp[2]]--;
        return tmp[2];
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */