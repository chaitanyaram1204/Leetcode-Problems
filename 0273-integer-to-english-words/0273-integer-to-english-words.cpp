class Solution {
public:
    unordered_map<int, string> onemap{
        {90, "Ninety"},   {80, "Eighty"},   {70, "Seventy"},   {60, "Sixty"},
        {50, "Fifty"},    {40, "Forty"},    {30, "Thirty"},    {20, "Twenty"},
        {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"},
        {15, "Fifteen"},  {14, "Fourteen"}, {13, "Thirteen"},  {12, "Twelve"},
        {11, "Eleven"},   {10, "Ten"},      {9, "Nine"},       {8, "Eight"},
        {7, "Seven"},     {6, "Six"},       {5, "Five"},       {4, "Four"},
        {3, "Three"},     {2, "Two"},       {1, "One"}};
    string getstring(int n) {
        int hundred = n / 100;
        vector<string>result;
        if (hundred > 0) {
            result.push_back(onemap[hundred] + " Hundred");
        }
        int left = n % 100;
        cout << left << endl;
        if (left >= 20) {
            int tens = left / 10;
            int ones = left % 10;
            result.push_back(onemap[tens * 10]); 
            if(ones > 0)
            result.push_back(onemap[ones]);
        } else if (left != 0) {
            result.push_back(onemap[left]);
        }
        string results = "";
        for(auto it : result){
            if(results.size() > 0){
                results += " " + it;
            }
            else{
                results += it;
            }
        }
        return results;
    }
    string numberToWords(int n) {
        if(n == 0){
            return "Zero";
        }
        vector<string> postvalue{"", " Thousand", " Million", " Billion"};
        int i = 0;
        string result = "";
        while (n > 0) {
            int number = n % 1000;
            string curr = "";
            curr += getstring(number);
            if (curr.size() > 0) {
                curr += postvalue[i];
            }
            if(result.size() == 0 && curr.size()){
                result += curr;
            }
            else if(curr.size())
                result = curr + " " + result;
            i++;
            n /= 1000;
        }
        return result;
    }
};