class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        
        for (int i = 1; i < items.size(); i++) {
            items[i][1] = max(items[i][1], items[i - 1][1]);
        }

        vector<int> result(queries.size());
        
        for (int i = 0; i < queries.size(); i++) {
            int query = queries[i];
            auto it = upper_bound(items.begin(), items.end(), vector<int>{query, INT_MAX});

            if (it != items.begin()) {
                result[i] = (it - 1)->at(1);
            } else {
                result[i] = 0;
            }
        }
        
        return result;
    }
};