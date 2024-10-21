class Solution {
public:
    void solve(int i, int n, string &s, string curr, unordered_set<string>added,int &maxi){
        if(i == n){
            maxi = max(maxi,(int)added.size());
            return;
        }
        string temp = "";
        curr += s[i];
        if(added.find(curr) == added.end()){
            added.insert(curr);
            solve(i+1,n,s,"",added,maxi);
            added.erase(curr);
        }
        solve(i+1,n,s,curr+s[i],added,maxi);
        
    }
    int maxUniqueSplit(string s) {
        unordered_set<string>added;
        int n = s.size();
        int maxi = 0;
        solve(0,n,s,"",added,maxi);
        return maxi;
    }
};