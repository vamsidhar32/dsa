class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>>minheap;
    priority_queue<int>maxheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minheap.push(num);
        
        if(minheap.size() > maxheap.size()+1){
            maxheap.push(minheap.top());
            minheap.pop();
        }

        if(!maxheap.empty() && minheap.top() < maxheap.top()){
            int k = maxheap.top();
            maxheap.pop();
            maxheap.push(minheap.top());
            minheap.pop();
            minheap.push(k);
        }
        
    }
    
    double findMedian() {
        if(minheap.size() > maxheap.size()){
            return minheap.top();
        }
        else{
            return (minheap.top()+maxheap.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */