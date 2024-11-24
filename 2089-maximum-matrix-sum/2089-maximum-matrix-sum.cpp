class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalsum = 0;
        int miniCount = 0;
        int mini = INT_MAX;
        for(auto it : matrix){
            for(auto e : it){
                if(e < 0){
                    miniCount++;
                }
                totalsum += abs(e);
                mini = min(mini,abs(e));
            }
        }

        if(miniCount%2){
            totalsum -= 2*mini;
        }
        return totalsum;
    }
};