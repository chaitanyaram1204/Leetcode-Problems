class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays[0][0];
        int maxi = arrays[0].back();
        int maxDistance = 0;
        int m = arrays.size();
        for(int i = 1; i < m; i++){
            maxDistance = max(maxDistance,abs(arrays[i][0] - maxi));
            maxDistance = max(maxDistance,abs(arrays[i].back() - mini));
            mini = min(mini,arrays[i][0]);
            maxi = max(maxi,arrays[i].back());
        }
        return maxDistance;
    }
};