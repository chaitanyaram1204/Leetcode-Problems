class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i = 0;i<arr1.size();i++)
        {
            mp[arr1[i]]++;
        }

        for(int i = 0;i<arr2.size();i++)
        {
            while(mp[arr2[i]]-- > 0)
            {
                ans.push_back(arr2[i]);
            }
        }
        vector<int>ans2;
        for(int i = 0;i<arr1.size();i++)
        {
            while(mp[arr1[i]]-- > 0)
            ans2.push_back(arr1[i]);
        }
        sort(ans2.begin(),ans2.end());
        for(auto i: ans2) ans.push_back(i);
        return ans;
    }
};