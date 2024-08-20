class Solution {
public:
    int
    solve(bool alice, int i, int m,
          vector<int> piles,map<pair<bool, pair<int, int>>, int>& mp) {
        if (i == piles.size())
            return 0;

        if (mp.find({alice, {i, m}}) != mp.end())
            return mp[{alice, {i, m}}];

        int res;
        if (alice)
            res = 0;
        else
            res = 1e9;

        int total = 0;
        for (int j = 1; j <= 2 * m; j++) {
            if (j + i > piles.size())
                break;
            total += piles[i + j - 1];

            if (alice) {
                res =
                    max(res, total + solve(false, i + j, max(m, j), piles, mp));
            } else {
                res = min(res, solve(true, i + j, max(m, j), piles, mp));
            }
        }

        return mp[{alice, {i, m}}] = res;
    }
    int stoneGameII(vector<int>& piles) {
        map<pair<bool, pair<int, int>>, int> mp;
        return solve(true, 0, 1, piles, mp);
    }
};