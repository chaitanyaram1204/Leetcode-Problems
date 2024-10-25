class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>result;
        int n = folder.size();
        int i = 0;
        int j = 1;
        while(j < n){
            string first = folder[i];
            string second = folder[j];
                    //cout << "Inside all " << first <<" " << second << " " << i << " " << j << endl;
            if(second.size() > first.size()){
                if(second.substr(0,first.size()) == first && second[first.size()] == '/'){
                    j++;
                }else{
                    result.push_back(folder[i]);
                    i = j;
                    j++;
                }
            }else{
                result.push_back(folder[i]);
                i = j;
                j++;
            }
        }
        result.push_back(folder[i]);
        return result;
    }
};