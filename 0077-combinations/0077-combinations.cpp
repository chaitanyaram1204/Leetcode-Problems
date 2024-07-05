class Solution {
public:
    void solve(int ind,int k,int n,vector<vector<int>>&ans,int cnt,vector<int>&temp)
    {
        
        if(cnt == k)
        {
            ans.push_back(temp);
            return;
        }
        if(ind > n)
            return;
        solve(ind+1,k,n,ans,cnt,temp);
        temp.push_back(ind);
        solve(ind+1,k,n,ans,cnt+1,temp);
        temp.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(1,k,n,ans,0,temp);
        return ans;
    }
};