class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int i  = 0;
        while(i<word.size())
        {
            int count = 0;
            char prev = word[i];
            while(i<word.size() && word[i] == prev && count < 9)
            {
                count++;
                i++;
            }
            ans += to_string(count)+prev;
        }
        return ans;
    }
};