class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> stks;
    int maxF;

public:
    FreqStack() {
        maxF = 0;
    }
    
    void push(int val) {
        freq[val]++;
        stks[freq[val]].push(val);
        maxF = max(maxF, freq[val]);
    }
    
    int pop() {
        int ans = stks[maxF].top();
        stks[maxF].pop();
        freq[ans]--;
        if(!stks[maxF].size()) maxF--;
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */