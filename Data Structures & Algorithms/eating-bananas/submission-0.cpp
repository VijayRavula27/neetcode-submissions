class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = 0;

        while(left <= right){
            int mid = left + (right - left) / 2;

            long long time = Timetaken(piles, mid);

            if(time <= h){
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
    long long Timetaken(vector<int>& piles, int mid){
        long long hours = 0;

        for(int num : piles){
            hours = hours + (num + mid - 1) / mid;
        }
        return hours;
    }
};