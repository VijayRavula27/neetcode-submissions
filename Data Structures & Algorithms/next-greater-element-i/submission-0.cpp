class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        stack<int> st;

        for(int i = 0; i < nums2.size(); i++){
            while(!st.empty() && st.top() < nums2[i]){
                map[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        
        for(int i = 0; i < nums1.size(); i++){
            if(map.count(nums1[i])){
                ans.push_back(map[nums1[i]]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};