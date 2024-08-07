class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        priority_queue<pair<int,int>>q;

        for(auto i : nums) mp[i]++;

        for(auto i : mp) q.push({i.second,i.first});

        vector<int>ans;
        for(int i = 0;i<k;i++)
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};