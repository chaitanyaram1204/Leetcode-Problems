class Solution {
public:
    vector<vector<int>> buildTopo(int k, vector<vector<int>>& edges) {
        vector<vector<int>> graph(k + 1);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
        }
        return graph;
    }
    vector<int> getOrder(int k, vector<vector<int>> graph) {
        vector<int> indegree(k + 1, 0);
        for (int node = 1; node <= k; node++) {
            for (auto it : graph[node]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        vector<int> vis(k + 1, 0);

        for (int i = 1; i < k + 1; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> toposort;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front();
                q.pop();
                vis[node] = 1;
                toposort.push_back(node);
                for (auto child : graph[node]) {
                    if (!vis[child]) {
                        indegree[child]--;
                        if(indegree[child] == 0){
                            q.push(child);
                        }
                    }
                }
            }
        }

        vector<int> dummy;
        for (int i = 1; i <= k; i++) {
            if (indegree[i] != 0)
                return dummy;
        }

        return toposort;
    }
    void fillRemaining(int k, vector<int>& arr) {
        unordered_map<int, bool> mp;
        for (auto it : arr) {
            mp[it] = true;
        }

        for (int i = 1; i <= k; i++) {
            if (!mp[i])
                arr.push_back(i);
        }
    }
    void solve(unordered_map<int, int> colInd, int k, vector<int>& rowtop,
               vector<vector<int>>& ans) {
        for (int i = 0; i < k; i++)
            ans[i][colInd[rowtop[i]]] = rowtop[i];
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        vector<vector<int>> rowgr = buildTopo(k, rowConditions);
        vector<vector<int>> colgr = buildTopo(k, colConditions);

        vector<int> rowtop = getOrder(k, rowgr);
        vector<int> coltop = getOrder(k, colgr);

        vector<vector<int>> ans;
        if (rowtop.size() == 0 || coltop.size() == 0) {
            return ans;
        }

        fillRemaining(k, rowtop);
        fillRemaining(k, coltop);

        unordered_map<int, int> colInd;
        for (int j = 0; j < k; j++) {
            colInd[coltop[j]] = j;
        }

        ans = vector<vector<int>>(k, vector<int>(k, 0));
        solve(colInd, k, rowtop, ans);

        return ans;
    }
};