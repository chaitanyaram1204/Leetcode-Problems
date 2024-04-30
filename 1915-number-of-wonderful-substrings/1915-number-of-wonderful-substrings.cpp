class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int>mp(1024,0);
        long long ans = 0;
        mp[0] = 1;
        int mask =0;
        long long result = 0;
        for(auto& i : word)
        {
            mask ^= (1<<(i-'a'));

            result +=mp[mask];

            for(int i =0;i<10;i++)
            {
                result += mp[mask^(1<<i)];
            }
            mp[mask]++;


        }
        return result;
    }
};