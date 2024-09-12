class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>allow(allowed.begin(),allowed.end());
        int count = 0;
        for(auto it : words){
            bool flag = true;
           for(int i = 0; i < it.size(); i++){
                char curr = it[i];
                if(allow.find(curr) == allow.end()){
                    flag = false;
                }
           }
           if(flag) count++; 
        }
        return count;
    }
};