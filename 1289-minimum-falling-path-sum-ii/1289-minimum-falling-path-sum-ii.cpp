class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> sumState(rows, vector<int>(cols, 0));
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                sumState[r][c] = grid[r][c];
                int minContri = INT_MAX;
                if(r-1 > -1){
                    for(int prevC = 0; prevC < cols; prevC++){
                       if(prevC != c)     
                        minContri = min(minContri, sumState[r-1][prevC]);
                    }
                }
                if(minContri != INT_MAX){
                    sumState[r][c] += minContri;
                }   
            }
        }
        return *min_element(sumState[rows-1].begin(), sumState[rows-1].end());
    }
};