class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>times;
        for(auto it : timePoints){
            int first = stoi(it.substr(0,2));
            int second = stoi(it.substr(3,2));
            times.push_back(first*60+second);
        }
        sort(times.begin(),times.end());
        int miniDiff = INT_MAX;
        for(int i = 0; i < times.size()-1; i++){
            int first = times[i];
            int second = times[i+1];
            miniDiff = min(miniDiff,second-first);
        }
        for(auto it : times){
            cout << it << endl;
        }
        miniDiff = min(miniDiff,24*60+times[0]-times[times.size()-1]);
        return miniDiff;

    }
};