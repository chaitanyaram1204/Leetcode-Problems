class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp1,mp2;
        for(int i =0;i<s.size();i++)
        {
            char s1 = s[i],s2 = t[i];
            if(mp1.count(s1) == 0 && mp2.count(s2) == 0)
            {
                mp1[s1] = s2;
                mp2[s2] = s1;
            }
            else if(mp1[s1] != s2 || mp2[s2] != s1)
            {
                return 0;
            }
        }
        return 1;
    }
};
