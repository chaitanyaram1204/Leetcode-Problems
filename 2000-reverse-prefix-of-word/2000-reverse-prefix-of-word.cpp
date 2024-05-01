class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i;
        string ans = "";
        stack<char>st;
        for(i =0;i<word.size();i++)
        {
            if(word[i] == ch){
            st.push(word[i++]);
            break;
            }
            st.push(word[i]);
        }

        while(!st.empty() && (i != word.size() || (i == word.size() && ch == word[i-1])))
        {
            ans += st.top();
            st.pop();
        }
        if((i != word.size() || (i == word.size() && ch == word[i-1]))){
        ans += word.substr(i);
        return ans;}
        return word;
    }
};