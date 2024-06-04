class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        int count = 0;
        for(int i =0;i<s.size();i++)
        {
            if(mp.find(s[i]) == mp.end())
            {
                count++;
            }
            else
            {
                if(mp[s[i]]%2 == 0)
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
            mp[s[i]]++;
        }

        if(count > 1)
        return s.size()-count+1;
        return s.size();

    }
};

