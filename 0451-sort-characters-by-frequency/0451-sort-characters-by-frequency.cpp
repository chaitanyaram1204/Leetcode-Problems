class Solution {
public:
    static bool cmp(pair<char, int>& a, pair<char, int>& b) 
    { 
        return a.second > b.second; 
    }
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto i : s)
        {
            mp[i]++;
        }
        string ans = "";
        vector<pair<char,int>>freq(mp.begin(),mp.end());
        sort(freq.begin(), freq.end(), cmp);
        for(auto i : freq)
        {
            for(int j = 0;j<i.second;j++)
            {
                ans += i.first;
            }
        }
        return ans;
    }
};