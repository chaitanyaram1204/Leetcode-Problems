class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>>worker;
        for(int i = 0;i<quality.size();i++)
        {
            worker.push_back({(double)wage[i]/quality[i],quality[i]});
        }
        
        sort(worker.begin(),worker.end());
        
        double ans = DBL_MAX;
        
        int queueSum = 0;
        priority_queue<int>q;
        for(auto i : worker)
        {
            double ratio = i.first;
            queueSum += i.second;
            q.push(i.second);
            if(q.size() > k)  queueSum -= q.top(),q.pop();
            if(q.size() == k) ans = min(ans,ratio*queueSum);
        }
        return ans;
    }
};