class Solution {
public:
    int solve(bool alice, int i, int m, vector<int>& piles, vector<vector<vector<int>>>& dp) {
        if (i == piles.size())
            return 0;

        if (dp[alice][i][m] != -1)
            return dp[alice][i][m];

        int res;
        if (alice)
            res = 0;
        else
            res = 1e9;

        int total = 0;
        for (int j = 1; j <= 2 * m; j++) {
            if (i + j > piles.size())
                break;
            total += piles[i + j - 1];

            if (alice) {
                res = max(res, total + solve(false, i + j, max(m, j), piles, dp));
            } else {
                res = min(res, solve(true, i + j, max(m, j), piles, dp));
            }
        }

        return dp[alice][i][m] = res;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(n + 1, -1)));
        return solve(true, 0, 1, piles, dp);
    }
};
