class Solution {
public:
    long long minimumSteps(string s) {
        long long count = 0;
        int blackCount = 0;
        for(auto ch : s){
            if(ch == '0'){
                count += blackCount;
            }else{
                blackCount++;
            }
        }
        return count;
    }
};