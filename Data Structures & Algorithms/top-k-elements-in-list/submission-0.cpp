class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++; //1:1, 2:2, 3:3
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minhp;
        for(auto it = map.begin(); it != map.end(); it++){
            minhp.push({it->second, it->first});

            if(minhp.size() > k){
                minhp.pop();
            }
        }
        vector<int> ans;

        while(k > 0){
            ans.push_back(minhp.top().second);
            minhp.pop();
            k--;
        }
        return ans;
    }
};
