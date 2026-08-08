class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        int maxlen = 0;

        for(int num : set){
            if(set.find(num - 1) == set.end()){
                int length = 1;
                while(set.find(num + length) != set.end()){
                    length++;
                }
                maxlen = max(maxlen, length);
            }
        }
        return maxlen;
    }
};
