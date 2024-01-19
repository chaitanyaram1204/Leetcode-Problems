class Solution {
public:
    //Greedy 
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        if(n==0) return 0;
        if(n==1) return matrix[0][0];
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                int m = matrix[i-1][j];
                if( j-1 >= 0) 
                    m = min(m , matrix[i-1][j-1]);
                if( j+1 < n) 
                    m = min(m , matrix[i-1][j+1]);
                matrix[i][j] += m;
                if(i==n-1) ans=min(ans,matrix[i][j]);
            }
        }
        return ans;
    }
    
    // Space optimization
    
    /*int minFallingPathSum(vector<vector<int>>& matrix) {
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
    }*/
    //Dynamic Programming
    /*int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int j = 0;j<n;j++)
        {
            dp[0][j] = matrix[0][j];
        }
        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                int u = matrix[i][j]+dp[i-1][j];
                int ul = 1e8;
                if(j-1 >=0)     ul = matrix[i][j]+dp[i-1][j-1];
                int ur = 1e8;
                if(j+1 < matrix.size())   ur = matrix[i][j]+dp[i-1][j+1];
                dp[i][j] = min(u,min(ul,ur));
            }
        }
        int maxi = dp[n-1][0];
        for(int j = 1;j<n;j++)
        {
            maxi = min(maxi,dp[n-1][j]);
        }
        return maxi;
    }*/
    //Recursion
    /*
    int solve(int i,int j,vector<vector<int>>& matrix)
    {
        if(j>=matrix.size() || j<0 ) return 1e4;
        if(i == 0) return matrix[i][j];
        int u = matrix[i][j]+solve(i-1,j,matrix);
        int ul = matrix[i][j]+solve(i-1,j-1,matrix);
        int ur = matrix[i][j]+solve(i-1,j+1,matrix);
        return min(u,min(ul,ur));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = 1e8;
        for(int i = 0;i<matrix.size();i++)
        {
            int value = solve(matrix.size()-1,i,matrix);
            mini = min(mini,value);
        }
        return mini;
    }*/
    
    // Memoization
    /*int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp)
    {
        if(j>=matrix.size() || j<0 ) return 1e8;
        if(i == 0) return matrix[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int u = matrix[i][j]+solve(i-1,j,matrix,dp);
        int ul = matrix[i][j]+solve(i-1,j-1,matrix,dp);
        int ur = matrix[i][j]+solve(i-1,j+1,matrix,dp);
        return dp[i][j] = min(u,min(ul,ur));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = 1e8;
        int n = matrix.size();
        
        for(int i = 0;i<matrix.size();i++)
        {
            vector<vector<int>>dp(n,vector<int>(n,-1));
            int value = solve(matrix.size()-1,i,matrix,dp);
            mini = min(mini,value);
        }
        return mini;
    }*/
   
};