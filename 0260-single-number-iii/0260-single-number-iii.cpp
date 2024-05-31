class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long initialXOR = 0;
        for(int i = 0;i<nums.size();i++)
        {
            initialXOR ^= nums[i];
        }
        cout<<initialXOR<<endl;
        
        cout<<(-initialXOR+1)<<endl;
        long long mask = initialXOR &(-initialXOR );
        cout<<mask<<endl;
        vector<int>setNumbers,unsetNumbers;
        for(int i = 0;i<nums.size();i++)
        {
            if((mask & nums[i]) != 0)
            {
                cout<<(mask ^ nums[i])<<" ";
                setNumbers.push_back(nums[i]);
            }
            else
            {
                cout<<endl;
                cout<<" Unset:"<<(mask ^ nums[i])<<" ";
                unsetNumbers.push_back(nums[i]);
            }
        }
        cout<<endl;
        long long firstNum = 0,secondNum = 0;
        for(auto i : setNumbers)
        {
            cout<<i<<" ";
            firstNum ^= i;
        }
        cout<<endl;
        for(auto i : unsetNumbers)
        {
            cout<<i<<" ";
            secondNum ^= i;
        }
        return {(int)firstNum,(int)secondNum};
    }
};