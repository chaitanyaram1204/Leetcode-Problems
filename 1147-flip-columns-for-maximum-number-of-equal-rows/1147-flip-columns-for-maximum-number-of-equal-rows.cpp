class Solution 
{
public:
    vector<int> flip(const vector<int>& row) {
        vector<int> flippedRow(row.size());
        for (int i = 0; i < row.size(); ++i) {
            flippedRow[i] = 1 - row[i];
        }
        return flippedRow;
    }

    bool isEqual(const vector<int>& row1, const vector<int>& row2) {
        for (int i = 0; i < row1.size(); ++i) {
            if (row1[i] != row2[i]) {
                return false;
            }
        }
        return true;
    }

    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int maxCount = 0;

        for (int i = 0; i < matrix.size(); ++i) {
            int count = 1;
            vector<int> flippedRow = flip(matrix[i]);

            for (int j = i + 1; j < matrix.size(); ++j) {
                if (isEqual(matrix[i], matrix[j]) || isEqual(flippedRow, matrix[j])) {
                    ++count;
                }
            }
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};