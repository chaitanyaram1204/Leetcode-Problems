class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long count = 0;
        for(int i = 0; i < nums.size()-1; i++){
            auto ub = upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i]);
            auto lb = lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]);
            count += (ub-lb);
        }
        return count;
    }
};