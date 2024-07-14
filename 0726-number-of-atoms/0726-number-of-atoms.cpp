class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        stack<int> temp;
        int mul = 1;
        int i, j, k;
        vector<int> result(n,0);
        for (i = n - 1; i >= 0; i--) {
            char ch = formula[i];
            cout << ch << " ";
            if (ch == ')') {
                string s = "";
               // cout << (i + 1);

                for (j = i + 1; j < n; j++) {
                    char curr = formula[j];
                    cout << curr << " ";
                    if (!isdigit(curr))
                        break;
                    s += curr;
                    cout << s << " ";
                }
                cout << endl;

                if (s.size() == 0)
                    s = "1";
                int digit = stoi(s);
                mul = mul * digit;
                temp.push(digit);
            } else if (ch == '(') {
                int digit = temp.top();
                temp.pop();

                mul = mul / digit;
            }

            result[i] = mul;
        }
        /* for(auto i : result){
            cout << i << " ";
        } */
        map<string, int> mp;

        for( i = 0; i < n; i++){
            char ch = formula[i];

            if(isupper(ch)){
                int mul = result[i];
                string s = "";
                s += ch;
                for(j = i+1; j < n ; j++){
                    ch  = formula[j];
                    if(!islower(ch)) break;
                    s += ch;
                }
                string digit = "";
                for(k = j ; j < n; j++){
                    ch = formula[j];
                    if(!isdigit(ch)) break;
                    digit += ch;
                }

                if(digit == "") digit = "1";
                int digits = stoi(digit);

                mp[s] += mul*digits;
                i = k-1; 
            }
        }

        string ans = "";
        for(auto i : mp){
            string elem = i.first;
            int value = i.second;
            ans += elem;
            if(value > 1) ans += to_string(value);
        }

        return ans;
    }
};