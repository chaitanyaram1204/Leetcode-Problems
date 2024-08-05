class Solution {
public:
    string kthDistinct(vector<string>& array, int k) {
        unordered_map<string,int>mp;
        for(auto it : array){
            mp[it]++;
        }
        for(auto it : array){
            if(mp[it] < 2){
                k--;
            }
            if(k == 0){
                return it;
            }
        }
        return "";
    }
};