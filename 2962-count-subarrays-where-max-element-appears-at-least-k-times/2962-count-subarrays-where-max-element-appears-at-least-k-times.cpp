class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int freq = 0,i =0,j=0;
        long long ans = 0; 
        int maxi = *max_element(nums.begin(),nums.end());
        while(j<nums.size())
        {
            if(nums[j] == maxi) freq++;
            while(freq >=k && i<=j)
            {
                //cout<<" i "<<i<<"  j "<<j<<endl;
                ans += (nums.size()-j);
                if(nums[i] == maxi) freq--;
                i++;
            }
            j++;
        }
        return ans;
    }
};