class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> mp;
        mp[5] = 0;
        mp[10] = 0;
        for (auto bill : bills) {
            if (bill == 5) {
                mp[5]++;
            } else if (bill == 10) {
                if (mp[5] < 1) {
                    return false;
                }
                mp[5]--;
                mp[10]++;
            } else {
                if (mp[10] >= 1) {
                    mp[10]--;
                    if (mp[5] < 1) {
                        return false;
                    }
                    mp[5]--;
                } else if (mp[5] >= 3) {
                    mp[5] -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};