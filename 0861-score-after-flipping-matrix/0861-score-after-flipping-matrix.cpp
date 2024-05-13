class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            int originalnum=0;
            int modifiednum=0;
            for(int j=0;j<n;j++){
                int num=grid[i][j];
                originalnum=originalnum*2+num;
                num=!num;
                modifiednum=modifiednum*2+num;
            }
            if(modifiednum>originalnum){
               for(int j=0;j<n;j++){
                    grid[i][j]=!grid[i][j];
                } 
            }

        }
        for(int j=0;j<n;j++){
            int zero=0;
            int one=0;
            for(int i=0;i<m;i++){
                if(grid[i][j]==0){
                    zero++;
                }else{
                    one++;
                }
            }
            if(zero>one){
               for(int i=0;i<m;i++){
                    grid[i][j]=!grid[i][j];
                } 
            }
        }
        int sum=0;
        for(auto x:grid){
            int num=0;
            for(auto y:x){
                num=(num*2)+y;
            }
            sum+=num;
        }
        return sum;
    }
};