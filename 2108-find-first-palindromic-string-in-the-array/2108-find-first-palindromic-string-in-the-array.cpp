class Solution {
public:
    bool pal(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto i : words)
        {
            if(pal(i)) 
            return i;
        }
        return "";
    }

};