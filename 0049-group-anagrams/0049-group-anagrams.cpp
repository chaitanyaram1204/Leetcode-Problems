class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,int>mp;
        for(auto i : strs)
        {
            string temp = i;
            sort(temp.begin(),temp.end());
            if(mp.find(temp) != mp.end())
            {
                ans[mp[temp]].push_back(i);   
            }
            else
            {
                mp[temp] = ans.size();
                ans.push_back({i});
            }
        }
        return ans;
    }
};
