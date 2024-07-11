class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<char> st;

        for(auto ch : s)
        {
            string temp = "";
            if(ch == ')')
            {
                while(!st.empty() && st.top() != '(')
                {
                    temp += st.top();
                    st.pop();
                }

                if(!st.empty())
                {
                    st.pop();
                }
            }else
            {
                st.push(ch);
            }
            for(int i = 0;i<temp.size();i++)
            {
                st.push(temp[i]);
            }
        }
        while(!st.empty()){
            ans  = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};