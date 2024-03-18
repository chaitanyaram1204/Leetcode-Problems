class Solution {
public:
    void solve(int e, priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>>&pq)
    {
        while(!pq.empty() && pq.top().first <= e)
        {
            e = min(e,pq.top().second);
            pq.pop();
        }
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        for(int i = 0;i<points.size();i++)
        {
            pq.push({points[i][0],points[i][1]});
        }
        int cnt = 0;
        while(!pq.empty())
        {
            int e = pq.top().second;
            pq.pop();
            solve(e,pq);
            cnt++;
        }
        return cnt;
    }
};