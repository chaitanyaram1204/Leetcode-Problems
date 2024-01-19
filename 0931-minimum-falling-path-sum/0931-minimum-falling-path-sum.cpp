class Solution {
public:
    // Space optimization
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
         int n = matrix.size();
        vector<int>front(n,0),curr(n,0);
        for(int j = 0;j<n;j++)
        {
            front[j] = matrix[0][j];
        }
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                int u = matrix[i][j]+front[j];
                int ul = 1e8;
                if(j-1 >=0)     ul = matrix[i][j]+front[j-1];
                int ur = 1e8;
                if(j+1 < matrix.size())   ur = matrix[i][j]+front[j+1];
                curr[j] = min(u,min(ul,ur));
            }
            front = curr;
        }
        int maxi = front[0];
        for(int j = 1;j<n;j++)
        {
            maxi = min(maxi,front[j]);
        }
        return maxi;
    }
    
    
   
};