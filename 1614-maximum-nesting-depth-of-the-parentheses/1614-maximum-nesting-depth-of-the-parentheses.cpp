class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int openCount = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                openCount++;
            }
            else if(s[i] == ')')
            {
                openCount--;
            }
            ans = max(ans,openCount);
        }
        return ans;
    }
};