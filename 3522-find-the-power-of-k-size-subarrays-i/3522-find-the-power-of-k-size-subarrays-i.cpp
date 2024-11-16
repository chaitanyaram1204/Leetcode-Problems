class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int m = n - k + 1;
        vector<int> arr(m);
        int preSum = 0;
        for (int l = 0; l < k - 1; l++) {
            preSum += nums[l];
        }

        int idx = 0;
        for (int i = 0, j = k - 1; j < n; i++, j++, idx++) {
            preSum += nums[j];
            if ((k * (nums[i] + nums[i] + k - 1) / 2) == preSum && nums[i] <= nums[j]) {
                arr[idx] = nums[j];
            } else {
                arr[idx] = -1;
            }
            
            preSum -= nums[i]; 
        }

        return arr;
    }
};