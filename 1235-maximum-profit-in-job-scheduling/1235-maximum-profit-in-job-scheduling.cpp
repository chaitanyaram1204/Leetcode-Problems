class Solution {
public:
    int solve(int i,int n,vector<int>& startTime,vector<vector<int>>&job,vector<int>&dp)
    {
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        int index = lower_bound(startTime.begin(),startTime.end(),job[i][1])-startTime.begin();
        int pick = job[i][2]+solve(index,n,startTime,job,dp);
        int not_pick = solve(i+1,n,startTime,job,dp);
        return dp[i]=max(pick,not_pick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>job;
        vector<int>dp(n+1,-1);
        for(int i = 0;i<n;i++)
        {
            job.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(job.begin(),job.end());
        sort(startTime.begin(),startTime.end());
        return solve(0,n,startTime,job,dp);
    }
};