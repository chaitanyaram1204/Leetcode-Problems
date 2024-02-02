class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for(int startDigit = 1;startDigit<10;startDigit++)
        {
            int val = startDigit;
            int curr = val+1;
            if(val>= low && val <= high)
            {
                ans.push_back(val);
            }
            for(;curr<10;curr++)
            {
                val *= 10;
                val += curr;
                if(val >= low && val <= high)
                    ans.push_back(val);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};