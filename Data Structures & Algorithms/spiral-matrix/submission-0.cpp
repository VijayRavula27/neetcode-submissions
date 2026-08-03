class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowbegin = 0;
        int colbegin = 0;
        int rowend = matrix.size()-1;
        int colend = matrix[0].size()-1;

        vector<int> ans;

        while(rowbegin <= rowend && colbegin <= colend){
            //left to right
            for(int i = colbegin; i <= colend; i++){
                ans.push_back(matrix[rowbegin][i]);
            }
            rowbegin++;
            //top to bottom

            for(int i = rowbegin; i <= rowend; i++){
                ans.push_back(matrix[i][colend]);
            }
            colend--;
            //right to left

            if(rowbegin <= rowend){
                for(int i = colend; i >= colbegin; i--){
                ans.push_back(matrix[rowend][i]);
                }
            }
            rowend--;
            //bottom to top

            if(colbegin <= colend){
                for(int i = rowend; i >= rowbegin; i--){
                ans.push_back(matrix[i][colbegin]);
                }
            }
            colbegin++; 
        }
        return ans;
    }
};
