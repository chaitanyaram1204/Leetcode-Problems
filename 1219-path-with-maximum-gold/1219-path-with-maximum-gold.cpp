class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, int& maxi, int output, vector<vector<bool>>& visited){
        int rows = grid.size(), cols = grid[0].size();
        if(i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j] == true || grid[i][j] == 0){
            return max(output, maxi);
        }

        visited[i][j] = true;
        output += grid[i][j];
        int downMaxi = solve(grid, i+1, j, maxi, output, visited);
        int leftMaxi = solve(grid, i, j-1, maxi, output, visited);
        int rightMaxi = solve(grid, i, j+1, maxi, output, visited);
        int upMaxi = solve(grid, i-1, j, maxi, output, visited);
        visited[i][j] = false;
        maxi =  max(max(downMaxi, leftMaxi), max(rightMaxi, upMaxi));
        return maxi;
    }


    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int maxi = 0, output = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] != 0){
                    cout<<grid[i][j]<<endl;
                    int ans = solve(grid, i, j, maxi, output, visited);
                    maxi = max(ans, maxi);
                }
            }
        }

        return maxi;
    }
};