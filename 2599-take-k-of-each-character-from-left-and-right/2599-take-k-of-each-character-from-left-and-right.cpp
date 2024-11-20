class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char,int>mp;

        for(auto ch : s){
            mp[ch]++;
        }
        int n = s.size();
        if(mp['a'] < k || mp['b'] < k || mp['c'] < k)
            return -1;
        int mini = n;
        int i = 0, j = 0;

        while( i <= j && j < n){
            mp[s[j]]--;
            while(i <= j && mp['a'] < k || mp['b'] < k || mp['c'] < k){
                mp[s[i]]++;
                i++;
            }

            mini = min(mini,n-(j-i+1));
            j++;
        }
        return mini;
    }
};