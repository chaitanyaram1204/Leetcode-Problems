class Solution {
public:
   int maxLength(vector<string>& arr) {
        int result = 0;
       string curr = "";
        generateSubsequences(arr, 0, curr, result);
        return result;
    }

private:
    void generateSubsequences(vector<string>& arr, int index, string current, int& result) {
        unordered_set<char> uniqueChars(current.begin(), current.end());

        if (uniqueChars.size() == current.size()) {
            result = max(result, static_cast<int>(current.size()));
            for (int i = index; i < arr.size(); ++i) {
            generateSubsequences(arr, i + 1, current + arr[i], result);
            }
        }
        else
        {
            return;
        }

        
    }
};
