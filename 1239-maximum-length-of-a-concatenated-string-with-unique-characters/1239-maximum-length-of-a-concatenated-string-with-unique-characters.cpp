class Solution {
public:
   int maxLength(vector<std::string>& arr) {
        int result = 0;
        generateSubsequences(arr, 0, "", result);
        return result;
    }

private:
    void generateSubsequences(const std::vector<std::string>& arr, int index, const std::string& current, int& result) {
        std::unordered_set<char> uniqueChars(current.begin(), current.end());

        if (uniqueChars.size() == current.size()) {
            result = std::max(result, static_cast<int>(current.size()));
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
