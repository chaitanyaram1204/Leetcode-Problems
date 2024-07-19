class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i<n; i++){
            int colMin,mini = INT_MAX;

            for(int j = 0; j < m; j++){
                if(matrix[i][j] < mini){
                    mini = matrix[i][j];
                    colMin = j;
                }
            }

            int rowMax , maxi = INT_MIN;

            for(int j = 0; j < n; j++){
                if(matrix[j][colMin] > maxi){
                    maxi = matrix[j][colMin];
                    rowMax = j;
                }
            }

            if(rowMax == i) return {matrix[i][colMin]};
        }

        return {};
    }
};