class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>vp;
        int n = worker.size();
        int m = difficulty.size();
        for(int i = 0;i<m;i++)
        {
            vp.push_back({difficulty[i],profit[i]});
        }
        sort(vp.begin(),vp.end());
        sort(worker.begin(),worker.end());
        int ans = 0,maxi = 0,j = 0,i = 0;
        for(i = 0;i < n;i ++)
        {
            while(j < m && vp[j].first <= worker[i])
            {
                maxi = max(maxi,vp[j].second);
                j++;
            }
            //cout<<maxi<<endl;
            ans += maxi;
        }
    return ans;
    }
};