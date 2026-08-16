class MinStack {
    private:
    vector<vector<int>> ans;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        int Curr_min = getMin();
        if(ans.empty() || value < Curr_min){
            Curr_min = value;
        }
        ans.push_back({value, Curr_min});
    }
    
    void pop() {
        ans.pop_back();
    }
    
    int top() {
        if(ans.empty()) return -1;
        return ans.back()[0];
    }
    
    int getMin() {
        if(ans.empty()) return -1;
        return ans.back()[1];
    }
};