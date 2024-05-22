class Solution {
private:
    bool isPalindrome(string& str) {
        int left = 0, right = str.length() - 1;
        while (left <= right) {
            if (str.at(left) != str.at(right))
                return false;
            left++, right--;
        }
        return true;
    }

    void helper(string currentStr, vector<string> currentStep, vector<vector<string>>& result) {
        if (currentStr.empty()) {
            result.push_back(currentStep);
            return;
        }
        for (int len = 1; len <= currentStr.length(); len++) {
            string substring = currentStr.substr(0, len);
            if (!isPalindrome(substring))
                continue;
            currentStep.push_back(substring);
            helper(currentStr.substr(len, currentStr.length()), currentStep, result);
            currentStep.pop_back();
        }
        return;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        helper(s, {}, result);
        return result;
    }
};
