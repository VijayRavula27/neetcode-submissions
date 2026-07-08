class MedianFinder {
public:
priority_queue<int> maxhp;
priority_queue<int, vector<int>, greater<int>> minhp;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxhp.push(num);
        minhp.push(maxhp.top());
        maxhp.pop();

        if(minhp.size() > maxhp.size()){
            maxhp.push(minhp.top());
            minhp.pop();
        }
    }
    
    double findMedian() {
        if(maxhp.size() > minhp.size()){
            return maxhp.top();
        } else {
            return (maxhp.top() + minhp.top()) / 2.0;
        }
    }
};
