class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int currentA = 0;
        int currentB = 0;
        int currentC = 0;
        int maxLen = a + b + c;
        string result = "";
        int i = 0;

        while(i < maxLen){
            if(((currentA != 2) && (a >= b && a >= c)) || (a > 0 &&( currentB == 2 || currentC == 2))){
                result += "a";
                currentA ++;
                currentB = 0;
                currentC = 0;
                a--;
            }
            else if(((currentB != 2) && (b >= c && b >= a)) || (b > 0 &&( currentA == 2 || currentC == 2))){
                result += "b";
                currentB ++;
                currentA = 0;
                currentC = 0;
                b--;
            }
            else if(((currentC != 2) && (c >= b && c >= a)) || (c > 0 &&( currentB == 2 || currentA == 2))){
                result += "c";
                currentC ++;
                currentA = 0;
                currentB = 0;
                c--;
            }
            i++;
        }
        return result;
    }
};