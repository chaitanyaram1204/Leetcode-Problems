class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>se;
        long long maxi = 0;
        long long sum = 0;
        for(int i = 0; i < k; i++){
            se[nums[i]]++;
            sum += nums[i];
        }
        int j = k;
        int i = 0;
        int n = nums.size();
        while(j < n){
            if(se.size() == k){
                maxi = max(maxi,sum);
            }
                se[nums[i]]--;
                if(se[nums[i]] == 0) se.erase(nums[i]);
            se[nums[j]]++;
            //cout << i << " " << j << " " << nums[i] << " " << nums[j] << endl;
            sum -= nums[i++];
            sum += nums[j++];
            while(se.size() != k && j < n){
            //cout << i << " " << j << " " << nums[i] << " " << nums[j] << " " << sum << endl;

                se[nums[i]]--;
                if(se[nums[i]] == 0) se.erase(nums[i]);
                se[nums[j]]++;
                sum -= nums[i++];
                sum += nums[j++];
            }
        }
        if(se.size() == k){
                maxi = max(maxi,sum);
            }
        return maxi;
    }
};