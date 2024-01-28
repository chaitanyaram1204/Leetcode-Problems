class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>prefix(n,vector<int>(m,0));
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                prefix[i][j] = matrix[i][j];
                if(i>0)
                    prefix[i][j] += prefix[i-1][j];
                if(j>0)
                    prefix[i][j] += prefix[i][j-1];
                //if both are true then we need to remove one
                if(i>0 && j>0) 
                    prefix[i][j] -= prefix[i-1][j-1];
            }
        }
        
        int ans = 0;
        
        for(int i = 0;i<n;i++)
        {
            for(int ex = i;ex<n;ex++)
            {
                for(int j = 0;j<m;j++)
                {
                    for(int ey = j;ey<m;ey++)
                    {
                        int curr = prefix[ex][ey];
                        if(i>0)
                            curr -= prefix[i-1][ey];
                        if(j>0)
                            curr -= prefix[ex][j-1];
                        if(i>0 && j>0)
                            curr += prefix[i-1][j-1];
                        ans += curr == target;
                    }

                }
            }
        }
        return ans;
    }
};