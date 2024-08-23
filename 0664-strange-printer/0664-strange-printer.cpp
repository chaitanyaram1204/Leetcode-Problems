class Solution {
public:
    int solve(int i, int j, string s, vector<vector<int>>& dp) {

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == j)
            return dp[i][j] = 1;

        int result;

        if (s[i] == s[i + 1]) {
            result = solve(i + 1, j, s, dp);
        } else if (s[i] == s[j] || s[j] == s[j - 1]) {
            result = solve(i, j - 1, s, dp);
        } else {
            result = 1 + solve(i, j - 1, s, dp);

            for (int k = i + 1; k < j; k++) {
                if (s[k] == s[j]) {
                    result = min(result,
                              solve(i, k - 1, s, dp) + solve(k, j - 1, s, dp));
                }
            }
        }

        return dp[i][j] = result;
    }
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int value = solve(0, n - 1, s, dp);
        return value;
    }
};