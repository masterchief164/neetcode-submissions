class MedianFinder {
    priority_queue<int> smallHeap;
    priority_queue<int, vector<int>, greater<int>> largeHeap;
public:
    MedianFinder() {
       
    }
    
    void addNum(int num) {
        smallHeap.push(num);

        if(smallHeap.size() && largeHeap.size() && smallHeap.top() > largeHeap.top()) {
            int tmp = smallHeap.top();
            smallHeap.pop();
            largeHeap.push(tmp);
        }

        if (smallHeap.size() > largeHeap.size() + 1) {
            int tmp = smallHeap.top();
            smallHeap.pop();
            largeHeap.push(tmp);
        }
        
        if(smallHeap.size() + 1 < largeHeap.size()) {
            int tmp = largeHeap.top();
            largeHeap.pop();
            smallHeap.push(tmp);
        }
    }
    
    double findMedian() {
        if(smallHeap.size() == largeHeap.size()){
            return (smallHeap.top() + largeHeap.top()) / 2.0;
        } else if(smallHeap.size() > largeHeap.size()){
            return smallHeap.top();
        } else {
            return largeHeap.top();
        }
    }
};
