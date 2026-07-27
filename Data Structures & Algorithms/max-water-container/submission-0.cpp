class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int water = 0;
        int maxwater = 0;

        while(left < right){
            water = min(heights[left], heights[right]) * (right - left);
            maxwater = max(maxwater, water);
            
            if(heights[left] > heights[right]){
                right--;
            } else {
                left++;
            }
        }
        return maxwater;
    }
};
