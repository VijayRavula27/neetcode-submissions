class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int mid = 0;
        int right = nums.size()-1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[mid] == 0){
                swap(nums[left], nums[mid]);
                left++;
                mid++;
            } else if(nums[mid] == 1){
                mid++;
            } else {
                swap(nums[mid], nums[right]);
                right--;
            }
        }
    }
};