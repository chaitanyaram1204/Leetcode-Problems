class Solution {
public:
    bool rotateString(string s, string goal) {
        int i = 0;
        if(s.size() != goal.size()) return false;
        int n = s.size();
        vector<int>choices;
        while(i < n){
            if(goal[i] == s[0]){
                choices.push_back(i);
            }
            i++;
        }
        if(choices.size() == 0) return false;
        bool result = false;
        for(auto i : choices){
            cout << i << " ";
            int j = 0;
            bool flag = true;
            while(j < n){
                if(s[j] != goal[i]){
                     flag = false;
                     break;
                }
                j++;
                i = (i+1)%n;
            }
            if(flag) return flag;
        }
        return false;
    }
};