class Solution {
public:
    int climbStairs(int n) {
        long long int h,f =0,g = 1;
        for(int i = 0;i<n;i++)
        {
            h = f+g;
            f = g;
            g = h;
        }
        return h;
    }
};