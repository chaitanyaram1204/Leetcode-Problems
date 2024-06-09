class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int cnt = 0;
        int sum = 0;
        map<int,int>mpp;
        mpp[0] = 1;
        for(auto x :nums)
        {
            sum=(sum+x%k+k)%k;
            cnt+=mpp[sum];
            mpp[sum]++;
        }
        return cnt;
    }
};