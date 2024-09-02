class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum = 0;
        sum = accumulate(chalk.begin(),chalk.end(),sum);
        k = k%sum;
        for(int i = 0; i < chalk.size(); i++){
            int required = chalk[i];
            if(required > k) return i;
            k -= required;
        }
        return 0;
    }
};