class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int set = 0;
        for(int i = 0;i<n;i++)
        {
            if(s[i] == '1')
                set++;
        }
        string ans = "";
        for(int i =0;i<set-1;i++)
        {
            ans+='1';
        }
        for(int i = ans.size();i<n-1;i++)
        {
            ans += '0';
        }
        ans+='1';
        return ans;
    }
};