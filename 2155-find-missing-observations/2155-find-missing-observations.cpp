class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        long long int sum = 0;
        sum = accumulate(rolls.begin(),rolls.end(),sum);
        int m = rolls.size();
        int remaining = mean * (n + m);
        remaining -= sum;
        vector<int>temp;
        if(remaining < n || remaining > 6*n ){
            return {};
        }
        if(remaining == 6*n){
            for(int i = 0; i< n;i++){
                temp.push_back(6);
            }
        }
        else if(remaining%n == 0){
            int num = remaining/n;
            for(int i = 0; i < n; i++){
                temp.push_back(num);
            }
        }
        else{
            int num = remaining/n;
            int rema = remaining % n;
            int i;
            for(i = 0; i< rema; i++){
                temp.push_back(num+1);
            }
            //cout << i << endl;
            for(; i < n; i++){
                temp.push_back(num);
            }
        }
        return temp;
    }
};