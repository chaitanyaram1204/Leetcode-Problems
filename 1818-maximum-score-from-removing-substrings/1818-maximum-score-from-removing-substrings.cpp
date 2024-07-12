class Solution {
public:
    int getMax(string &s, string s2, int x) { 
        int ans = 0;
        stack<char>st;
        for(int i = 0;i < s.size(); i++){
            char ch = s[i];
            if(st.empty()){
                st.push(ch);
            }
            else{
                if(ch == s2[1] && st.top() == s2[0]){
                    ans += x;
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        } 
        s = "";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return ans;
    }

    int maximumGain(string s, int x, int y) {
        string s1 = "ab";
        string s2 = "ba";
        if (x < y) {
            swap(s1, s2);
            swap(x, y);
        }
        int first = getMax(s,s1,x);
        int second = getMax(s,s2,y);

        return first + second ;
    }
};