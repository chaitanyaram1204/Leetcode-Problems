class Solution {
public:
    int solve(int index,vector<int>& arr,int k,int n,vector<int>&dp)
    {
        if(index == n)
        return 0;
        if(dp[index] != -1) return dp[index];
        int maxi = INT_MIN,len = 0,max_ans = INT_MIN;
        for(int i = index;i<min(n,index+k);i++)
        {
            maxi = max(maxi,arr[i]);
            len++;
            int sum = (len*maxi) + solve(i+1,arr,k,n,dp);
            max_ans = max(max_ans,sum);
        }
        return dp[index] = max_ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,-1);
        return solve(0,arr,k,n,dp);
    }
};