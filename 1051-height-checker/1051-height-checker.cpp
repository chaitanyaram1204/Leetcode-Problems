class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>freq(101,0);
        for(int i =0;i<heights.size();i++)
        {
            freq[heights[i]]++;
        }
        int ans = 0;
        int id = 0;
        for(int i = 0;i<heights.size();i++)
        {
            while(freq[id] == 0) id++;
            if(heights[i] != id)
            {
                ans++;
            }
            freq[id]--;
        }
        return ans;
    }
};