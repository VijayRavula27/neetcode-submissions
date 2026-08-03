class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> zerorow(row, false);
        vector<int> zerocol(col, false);

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(matrix[i][j] == 0){
                    zerorow[i] = true;
                    zerocol[j] = true;
                }
            }
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(zerorow[i] == true || zerocol[j] == true){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
