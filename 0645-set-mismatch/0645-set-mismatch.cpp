class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    int dupli;

    for (int num : nums)
      if (nums[abs(num) - 1] < 0)
        dupli = abs(num);
      else
        nums[abs(num) - 1] *= -1;

    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] > 0)
        return {dupli, i + 1};

    return {0,0};
  }
};