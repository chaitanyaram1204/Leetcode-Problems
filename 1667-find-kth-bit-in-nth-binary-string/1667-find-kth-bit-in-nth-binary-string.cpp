class Solution {
public:
    string solve(int n){
        if(n == 1) return "0";
        string result = solve(n-1);
        string temp = result;
        result += "1";
        for(auto &ch : temp){
            if(ch == '0') ch = '1';
            else ch = '0';
        }
        reverse(temp.begin(),temp.end());
        result += temp;
        //cout << result << endl;
        return result;
    }
    char findKthBit(int n, int k) {
        string result = solve(n);
        //cout << result ;
        return result[k-1];
    }
};