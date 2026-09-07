class MedianFinder {
public:
priority_queue<int> left;  // MAX HEAP
priority_queue<int, vector<int>, greater<int>> right; // MIN HEAP
    
    void addNum(int num) {
        if(left.empty() || num <= left.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }
         if (left.size() > right.size() + 1){
        right.push(left.top());
        left.pop();
    }

    if(right.size() > left.size() + 1){
        left.push(right.top());
        right.pop();
    }
    }
    
    double findMedian() {
        if(left.size() > right.size() ){
            return left.top();
        }
        if(right.size() > left.size()){
            return right.top();
        }
        else{
          return ((left.top() + right.top()) / 2.0 );
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */