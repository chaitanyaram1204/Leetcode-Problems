class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        for(auto it : s){
            num += to_string(it-'a'+1);
        }
        while(k>0){
            int value = 0;
            for(auto it : num){
                value += it-'0';
            }
            num = to_string(value);
            k--;
        }
        return stoi(num);
    }
};