class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int Totalsum = 0;

        for(int num : cardPoints){
            Totalsum = Totalsum + num;
        } //22

        int windowsize = cardPoints.size() - k; //4
        int sum = 0;
        int minsum = INT_MAX;

        for(int i = 0; i < cardPoints.size(); i++){
            sum = sum + cardPoints[i];

            if(i >= windowsize){
                sum = sum - cardPoints[i - windowsize];
            }
            if(i >= windowsize - 1){
                minsum = min(minsum, sum);
            }
        }
        return Totalsum - minsum; //22 - 10 = 12
    }
};