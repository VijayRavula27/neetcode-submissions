class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int Maxarea = 0;

        for(int i = 0; i < heights.size(); i++){
            while(st.top() != -1 && heights[i] <= heights[st.top()]){
                int height = heights[st.top()];
                st.pop();
                int width = i - st.top() - 1;
                Maxarea = max(Maxarea, height * width);
            }
            st.push(i);
        }
        while(st.top() != -1){
             int height = heights[st.top()];
                st.pop();
                int width = heights.size() - st.top() - 1;
                Maxarea = max(Maxarea, height * width);
        }
        return Maxarea;
    }
};
