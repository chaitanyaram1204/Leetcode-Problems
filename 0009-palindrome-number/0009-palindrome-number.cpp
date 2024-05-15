class Solution {
public:
    bool isPalindrome(int x) {
        int r;
        int n = x;
        long long sum =0;
        while(x > 0)
        {
            r = x%10;
            sum = sum*10 + r;
            x/=10;
        }
        return sum == n;
    }
};