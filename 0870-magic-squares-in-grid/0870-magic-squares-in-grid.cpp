class Solution {
public:
    int check(int i, int j, vector<vector<int>>&grid,int n){
        long long rows[4] = {0,0,0,0};
        long long cols[4] = {0,0,0,0};
        unordered_set<int>total;
        for(int r = i-1; r <= i+1; r++){
            for(int c = j-1; c <= j+1; c++){
                if(grid[r][c] >= 10){
                    return 0;
                }
                total.insert(grid[r][c]);
                //cout << " ro " <<(r-i+1) << endl;
                rows[r - i + 1] += grid[r][c];
                cols[c - j + 1] += grid[r][c];
            }
        }
        long long first = 5 + grid[i-1][j-1] + grid[i+1][j+1];
        long long second = 5 + grid[i-1][j+1] + grid[i+1][j-1];

        cout << first << " " << second << endl;
        if(total.size() < 9 || first != second || first != 15)return 0;
        for(int i = 0; i < 4-1; i++)
        {
            if(rows[i] != 15 || cols[i] != 15) return 0;
            cout << rows[i] << " " << cols[i] << endl;
        }

        return 1;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        for(int i = 1; i < grid.size()-1; i++){
            for(int j = 1; j < grid[0].size()-1; j++){
                if(grid[i][j] == 5){
                    //cout << i << " " << j;
                    count += check(i,j,grid,n);
                }
            }
        }
        return count;
    }
};