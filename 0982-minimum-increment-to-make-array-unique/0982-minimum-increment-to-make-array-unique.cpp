class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int no = 0;
        multiset<int> st;
        vector<int> temp;
        unordered_map<int, int> mp;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                no++;
                st.insert(nums[i]);
            }
            mp[nums[i]]++;
        }

        int count = 0;
        if (!st.empty()) count = *st.begin() + 1; // Just to avoid pointing to NULL

        while (no != 0) {
            if (st.find(count) == st.end() && mp.find(count) == mp.end() && count > *st.begin()) {
                mp[count]++;
                temp.push_back(count);
                no--;
                if (!st.empty()) // Remove only if not empty
                    st.erase(st.begin());
                count++;
            } else if (st.empty() && mp.find(count) == mp.end()) {
                temp.push_back(count);
                no--;
                count++;
            } else {
                count++;
            }
        }

        int op = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
                if (it != temp.end()) {
                    op += (*it - nums[i]);
                    temp.erase(it);
                }
            }
        }
        return op;
    }
};