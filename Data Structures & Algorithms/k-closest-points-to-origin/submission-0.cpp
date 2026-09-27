class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int, int>>> maxhp;

        for(int i = 0; i < points.size(); i++){
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if(maxhp.size() < k){
                maxhp.push({dist, {points[i][0], points[i][1]}});
            } else {
                if(maxhp.top().first > dist){
                    maxhp.pop();
                    maxhp.push({dist, {points[i][0], points[i][1]}});
                }
            }
        }
        while(!maxhp.empty()){
            ans.push_back({maxhp.top().second.first, maxhp.top().second.second});
            maxhp.pop();
        }
        return ans;
    }
};

//{dist,[0,2]}
