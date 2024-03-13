class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0;
        for(int i =1;i<=n;i++)
        {
            sum += i;
        }
       
        int prefix = 0;
        for(int i = 1;i<=n;i++)
        {
            prefix += i;
            if(prefix == sum-prefix+i)
            return i;
        }
        return -1;
    }
};