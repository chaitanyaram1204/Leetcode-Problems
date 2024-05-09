class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        long long ans = happiness[happiness.size()-1];
        int count = 1;
        k--;
        for(int i = happiness.size()-2;i>=0;i--)
        {
            if(happiness[i]-count <= 0 || k == 0)
            {
                return ans;
            }
            ans += happiness[i]-count++;
            k--;
        }
        return ans;

    }
};