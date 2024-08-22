class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = ~0;
        int result = 0;

        for(int b = 0;num;b++){
            result += (1-num&1)<<b;
            num >>= 1;
        }
        return result;

    }
};