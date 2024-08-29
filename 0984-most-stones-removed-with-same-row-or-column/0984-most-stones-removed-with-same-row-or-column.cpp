class Disjointset {
public:
    vector<int> parent, size;
    Disjointset(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <=n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = findUPar(parent[i]);
    }

    void unionBySize(int u, int v) {
        int uu = findUPar(u);
        int vv = findUPar(v);
        if (uu == vv)
            return;
        if (size[uu] < size[vv]) {
            parent[uu] = vv;
            size[vv] += size[uu];
        } else {
            parent[vv] = uu;
            size[uu] += size[vv];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0;
        int maxcol = 0;
        for(auto it : stones){
            maxrow = max(it[0],maxrow);
            maxcol = max(it[1],maxcol);
        }

        Disjointset ds(maxrow+maxcol+1);
        unordered_set<int>se;
        for(auto stone : stones){
            int r = stone[0];
            int c = stone[1] + maxrow + 1;
            ds.unionBySize(r,c);
            se.insert(r);
            se.insert(c);
        }

        int count = 0;
        int n = stones.size();
       
        for(auto it : se){
            if(ds.findUPar(it) == it) count++;
        }
        return n - count;
    }
};