class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        vector<int> ans(nums.size(), 0);

        for(int i = nums.size()-1; i >= 0; i--){
            int leftsquare = nums[left] * nums[left];
            int rightsquare = nums[right] * nums[right];

            if(leftsquare > rightsquare){
                ans[i] = leftsquare;
                left++;
            } else {
                ans[i] = rightsquare;
                right--;
            }
        }
        return ans;
    }
};