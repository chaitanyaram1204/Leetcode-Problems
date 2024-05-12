class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>>ans;
        for(int i =0;i<grid.size()-2;i++)
        {
            vector<int>row;
            for(int j =0;j<grid.size()-2;j++)
            {
                int maxi = INT_MIN;
                for(int m = i;m<i+3;m++)
                {
                    for(int n = j;n<j+3;n++)
                    {
                        maxi = max(maxi,grid[m][n]);
                    }
                }
                row.push_back(maxi);
            }
            ans.push_back(row);
        }
        return ans;
    }
};