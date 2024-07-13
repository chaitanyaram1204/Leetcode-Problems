class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& health, string directions) {
        int n = positions.size();
        vector<int> ids;

        for (int i = 0; i < n; i++) {
            ids.push_back(i);
        }

        auto comp = [&](int id1, int id2) {
            return positions[id1] <= positions[id2];
        };
        sort(ids.begin(), ids.end(), comp);

        stack<int> st;

        for (auto id : ids) {
            if (directions[id] == 'R') {
                st.push(id);
            } else {
                while (!st.empty() && health[id] > 0) {
                    if (health[st.top()] > health[id]) {
                        health[id] = 0;
                        health[st.top()]--;
                    } else if (health[st.top()] < health[id]) {
                        health[id]--;
                        health[st.top()] = 0;
                        st.pop();
                    } else {
                        health[id] = 0;
                        health[st.top()] = 0;
                        st.pop();
                    }
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (health[i]) {
                ans.push_back(health[i]);
            }
        }

        return ans;
    }
};