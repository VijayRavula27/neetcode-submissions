class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int Totalsum = 0;

        for(int num : nums){
            Totalsum = Totalsum + num;
        } //27
        int leftsum = 0;

        for(int i = 0; i < nums.size(); i++){
            int rightsum = Totalsum - leftsum - nums[i];

            if(leftsum == rightsum){
                return i;
            }
            leftsum = leftsum + nums[i]; 
        }
        return -1;
    }
};