class Solution {
public:
    int maxi = 0;
    int count = 0;
    void solve(vector<int>&nums,int ind,vector<int>ds){
        if(ind == (int)nums.size()){
            int xorvalue = 0;
            for(auto it : ds){
                xorvalue |= it;
            }
            if(xorvalue > maxi){
                maxi = xorvalue;
                count = 1;
            }
            else if(xorvalue == maxi) count++;
            return ;
        }

        ds.push_back(nums[ind]);
        solve(nums,ind+1,ds);
        ds.pop_back();
        solve(nums,ind+1,ds);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        solve(nums,0,{});
        return count;
    }
};