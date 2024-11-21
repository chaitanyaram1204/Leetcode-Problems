class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<char>> matrix(m, vector<char>(n, 'A'));
        //vector<vector<bool>> matrix(m, vector<bool>(n, false));

        for (auto it : walls) {
            matrix[it[0]][it[1]] = 'W';
        }
        for (auto it : guards) {
            matrix[it[0]][it[1]] = 'G';
        }
        for (auto it : guards) {
            int row = it[0];
            int col = it[1];
            int rr = row-1;
            while(rr >= 0){
                if(matrix[rr][col] == 'W' || matrix[rr][col] == 'G'){                  break;
                }
                    matrix[rr][col] = 'V';
                rr--;
            }
            rr = row+1;
            while(rr < m){
                if(matrix[rr][col] == 'W' || matrix[rr][col] == 'G'){               break;
                }
                    matrix[rr][col] = 'V';
               
                rr++;
            }
            int cc = col-1;
             while(cc >= 0){
                if(matrix[row][cc] == 'W' || matrix[row][cc] == 'G'){               break;
                }
                matrix[row][cc] = 'V';
                cc--;
            }
            cc = col+1;
            while(cc < n){
                if(matrix[row][cc] == 'W' || matrix[row][cc] == 'G'){               break;
                }
                    matrix[row][cc] = 'V';
                cc++;
            }
        }

        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 'A') {
                    count++;
                }
            }
        }
        return count;
    }
};