class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for(auto&i:tasks)
        {
            freq[i-'A']++;
        }
        sort(begin(freq),end(freq));
        int chunk = freq[25]-1;
        int idel = chunk*n;
        for(int i=24;i>=0;i--)
        {
            idel -= min(chunk,freq[i]);
        }
        return idel<0?tasks.size():tasks.size()+idel;
    }
};