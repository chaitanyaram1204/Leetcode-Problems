class Solution {
public:
    bool checkRecord(string s) {
        int absentCount = 0;
        int lateCount = 0;
        bool late = false;
        for(int i = 0;i<s.size();i++)
        {
            late = (lateCount >= 3);
            cout<<lateCount<<endl;
            if(late) return false;
            if(absentCount >=2) return false;
            if(s[i] == 'A')
                absentCount += 1;
            else if(s[i] == 'L')
            {
                
                
                if(i>0)
                {
                    if(s[i-1] == s[i])
                    {
                        
                        lateCount++;
                    }
                    else
                    {
                        lateCount = 1;
                    }
                }
                else
                {
                    lateCount = 1;
                }
            }
            
        }
        late = true ?(lateCount >= 3) : false;
        return !late && absentCount <=1 ;
    }
};