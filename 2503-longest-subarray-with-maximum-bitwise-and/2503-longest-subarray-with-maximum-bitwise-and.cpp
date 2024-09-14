class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int m = max_element(nums.begin(),nums.end())-nums.begin();
        int n = nums.size();
        int maxi = nums[m];
        int maxlen = 0;

        for(int i = m ; i < n; i++){
            int len = 0;
            while(i < n && nums[i] == maxi){
                i++;
                len++;
            }
            maxlen = max(len,maxlen);
        }
        return maxlen;
    }
};