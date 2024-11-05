class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        if(n%2){
            int zeroCount = 0;
            int oneCount = 0;
            for(int i = 0; i < n; i++){
                if(s[i] == '0') zeroCount++;
                else oneCount++;
            }
            return min(zeroCount,oneCount);
        }
        int i = 0;
        int result = 0;
        while(i < n){
            if(s[i] != s[i+1]){
                result++;
            }
            i += 2;
        }
        return result;
    }
};