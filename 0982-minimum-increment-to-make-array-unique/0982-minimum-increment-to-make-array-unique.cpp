class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int>freq(*max_element(nums.begin(),nums.end())+nums.size()+1,0);
        for(int i : nums) freq[i]++;
        int ans = 0;
        for(int i = 0;i<freq.size();i++)
        {
            if(freq[i] <= 1) continue;
            freq[i+1] += freq[i] - 1;
            ans += freq[i]-1;
        }
        return ans;
        

    }
};