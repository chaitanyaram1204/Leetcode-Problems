class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int b = sqrt(c);
        long long int a = 0;
        while( a <= b)
        {
            long long int res = a*a + b*b;
            if(res == c) return true;
            else if(res < c) a++;
            else b--;
        }
        return false;
    }
};