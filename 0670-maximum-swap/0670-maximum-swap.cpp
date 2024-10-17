class Solution {
public:
    int maximumSwap(int num) {
        string number = to_string(num);
        int n = number.size();
        vector<int> lastOccurence(10, -1);
        for (int i = 0; i < n; i++) {
            lastOccurence[number[i] - '0'] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int d = 9; d > (number[i] - '0'); d--) {
                if(lastOccurence[d] > i){
                    swap(number[i],number[lastOccurence[d]]);
                    return stoi(number);
                }
            }
        }
        return num;
    }
};