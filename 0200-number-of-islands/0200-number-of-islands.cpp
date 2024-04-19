class Solution{
private:
    void bfs(int row, int col, vector<vector<char>>& grid){
        grid[row][col] = '0'; 
        queue<pair<int,int>> q;
        int n= grid.size();
        int m= grid[0].size();
        q.push({row, col});
        vector<int> del({-1, 0, 1, 0, -1}); 
        while (!q.empty()) {
            int row= q.front().first; 
            int col= q.front().second; 
            q.pop(); 
            for (int idx = 0; idx < del.size() - 1; idx++) {
                int nrow = row + del[idx];
                int ncol = col + del[idx + 1];
                if (nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1') {
                    grid[nrow][ncol] = '0';
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char> >& grid){
        int n= grid.size();
        int m= grid[0].size();
        if (n==0 || m==0)   return 0;

        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j]=='1') {
                    cnt++;
                    bfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
};