class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>st;
        int n = expression.size();
        for(auto curtop : expression){
            if(curtop == '(' || curtop == ',') continue;
            else if(curtop == ')'){
                bool hast = false;
                bool hasf = false;
                while(st.top() != '!' && st.top() != '&' && st.top() != '|'){
                    char ch = st.top();
                    st.pop();
                    if(ch == 't') hast = true;
                    else if(ch == 'f') hasf = true;
                }

                char ch = st.top();
                st.pop();
                if(ch == '&'){
                    st.push(hasf ? 'f' : 't');
                }
                else if(ch == '|'){
                    st.push(hast ? 't' : 'f');
                }
                else st.push(hast ? 'f' : 't');
            }
            else st.push(curtop);
        }
        return st.top() == 't';
    }
};