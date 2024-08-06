class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        vector<pair<int,char>>freq;
        for(auto it : word){
            mp[it]++;
        }
        for(auto it:mp)
            freq.push_back({it.second,it.first});
        sort(freq.begin(),freq.end());
        int n = freq.size();
        int cnt = 8;
        int mul = 1;
        int count = 0;
        for(int i = n-1; i >= 0; i--){
            count += freq[i].first*mul;
            cnt --;
            if(cnt == 0){
                mul++;
                cnt = 8;
            }
        }
        return count;
    }
};