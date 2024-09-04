class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> se;
        int d = 0;
        int first = 0;
        int second = 0;
        int maxi = 0;
        vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto it : obstacles) {
            string temp = to_string(it[0]) + "," + to_string(it[1]);
            se.insert(temp);
        }

        for (auto command : commands) {
            if (command == -1) {
                d = (d + 1) % 4;
            } else if (command == -2) {
                d = (d + 3) % 4;
            } else {
                for (int i = 0; i < command; i++) {
                    int nx = first + directions[d].first;
                    int ny = second + directions[d].second;
                    string temp = to_string(nx) + "," + to_string(ny);
                    if (se.find(temp) != se.end()) {
                        break;
                    }
                    first = nx;
                    second = ny;
                    maxi = max(maxi, first * first + second * second);
                }
            }
        }
        return maxi;
    }
};