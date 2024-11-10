class Solution {
public:
    void update(vector<int>& count, int num, int val) {
        for (int i = 0; i < 32; i++) {
            if ((num >> i) & 1) {
                count[i] += val;
            }
        }
    }

    int getVal(const vector<int>& count) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (count[i] > 0) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> count(32, 0);
        int start = 0, end = 0, minLength = INT_MAX;

        while (end < nums.size()) {
            update(count, nums[end], 1);
            while (start <= end && getVal(count) >= k) {
                minLength = min(minLength, end - start + 1);
                update(count, nums[start], -1);
                start++;
            }
            end++;
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};