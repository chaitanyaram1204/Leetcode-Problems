class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int>dp(arr.size()+1,0);
        for(int i =0;i<arr.size();i++)
        {
            dp[i+1] = dp[i]^arr[i];
        }

        int count = 0;

        for(int i = 0;i<arr.size();i++)
        {
            for(int j = i+1;j<arr.size();j++)
            {
                if(dp[i] == dp[j+1])
                {
                    count += (j-i);
                }
            }
        }
        return count;
    }
};