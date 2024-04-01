class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int flag = false;
        for(int i = s.size()-1;i>=0;i--)
        {
            //cout<<"hellp"<<endl;
            if(flag && s[i] == ' ')
            {
                return ans;
            }
            
            if(s[i] != ' ') {
                ans++;
                flag = true;
            }
            
        }
        return ans;
    }
};