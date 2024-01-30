class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& token : tokens) {
            if (isOperator(token)) {
                int secondNum = st.top();
                st.pop();
                int firstNum = st.top();
                st.pop();
                int result;
                switch (token[0]) {
                    case '+': result = firstNum + secondNum; break;
                    case '-': result = firstNum - secondNum; break;
                    case '*': result = firstNum * secondNum; break;
                    case '/': result = firstNum / secondNum; break;
                }
                st.push(result);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }

private:
    bool isOperator(const string& token) {
        return token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
    }
};
