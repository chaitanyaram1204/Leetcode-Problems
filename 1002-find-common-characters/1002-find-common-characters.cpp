class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>overAllFreq(26,101);
        for(auto i : words)
        {
            vector<int>freq(26,0);
            for(int j = 0;j<i.size();j++)
            {
                freq[i[j]-'a']++; 
            }
            for(int j = 0;j<26;j++)
            {
                overAllFreq[j] = min(overAllFreq[j],freq[j]);
            }
        }

        for(int i =0;i<26;i++)
        {
            cout<<overAllFreq[i]<<" ";
        }
        vector<string>ans;
        for(int i =0;i<26;i++)
        {
            while(overAllFreq[i]-- > 0)
            {   
                ans.push_back(string(1,i+'a'));
            }
        }
        return ans;
    }
};