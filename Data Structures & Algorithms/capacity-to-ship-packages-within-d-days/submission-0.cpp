class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high){
            int mid = low + (high - low) / 2;

            int currdays = Daysrequired(weights, mid);

            if(currdays > days){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
public:    
    int Daysrequired(vector<int>& weights, int mid){
        int daycount = 1;
        int load = 0;

        for(int i = 0; i < weights.size(); i++){
            if(load + weights[i] > mid){
                daycount++;
                load = weights[i];
            } else {
                load = load + weights[i];
            }
        }
        return daycount;
    }
};