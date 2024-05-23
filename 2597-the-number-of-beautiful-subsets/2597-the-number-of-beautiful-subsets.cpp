class Solution {
public:
    int p,ans=0;
    vector<int>a ;
    map<int,int>mp;
    void dp(int j){
        if(j==a.size()){
            ans++;
            return ;
        }
        if(mp[a[j]-p]==0 and mp[a[j]+p]==0){
            mp[a[j]]++;
            dp(j+1);
            mp[a[j]]--;
        }
        dp(j+1);
    }
    int beautifulSubsets(vector<int>& nums, int k) { 
        p=k;
        a=nums;
        dp(0); 
        return ans-1; 
    }
};