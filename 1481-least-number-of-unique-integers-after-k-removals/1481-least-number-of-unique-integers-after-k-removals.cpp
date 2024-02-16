class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int count = 0;
        for(int i =0;i<arr.size();i++)
        {
            if(mp.find(arr[i]) == mp.end())
            count++;
            mp[arr[i]]++;
        }
        vector<int>freq;
        for(auto i : mp)
        {
            freq.push_back(i.second);
        }
        sort(freq.begin(),freq.end());
        int j =0;
        for(int i = 0;i<k;i++)
        {
            if(freq[j] == 1)
            {
                count--;
                j++;
            }
            else
            {
                freq[j]--;
            }
        }
        return count;
    }
};