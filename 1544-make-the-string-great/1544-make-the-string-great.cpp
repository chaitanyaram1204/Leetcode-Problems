class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(auto c : s)
        {
            if(!st.empty() && (c-'A' == st.top()-'a' || c-'a' == st.top()-'A'))
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }

        string res= "";
        while(!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        return res;

    }
};

