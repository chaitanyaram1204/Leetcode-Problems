class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> temp;
        for(auto num : nums){
            string digit = to_string(num);
            for(auto &ch : digit){
                ch = '0' + mapping[(int)ch-'0'];
            }
            int value = stoi(digit);
            cout << value << endl;
            temp.push_back({value,num});
        }
        sort(temp.begin(),temp.end(),[&](pair<int,int> a, pair<int,int> b){
            if(a.first == b.first){
                return false;
            }
            return a.first < b.first;
        });

        vector<int>ans;
        for(auto it : temp){
            ans.push_back(it.second);
        }
        return ans;
    }
};