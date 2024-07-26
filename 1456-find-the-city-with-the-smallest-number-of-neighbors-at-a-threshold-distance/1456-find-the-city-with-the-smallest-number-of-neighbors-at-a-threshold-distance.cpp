class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(auto edge : edges){
            int r = edge[0];
            int c = edge[1];
            dist[r][c] = edge[2];
            dist[c][r] = edge[2];
        }   

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i == j) continue;
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        int city = -1;
        int cntmax = 1e9;


        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(dist[i][j] <= threshold){
                    cnt ++;
                }
            }
            if(cnt <= cntmax){
                cntmax = cnt;
                city = i;
            }
        }

        return city;
    }
};