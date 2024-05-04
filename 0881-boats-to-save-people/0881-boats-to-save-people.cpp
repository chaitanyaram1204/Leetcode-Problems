class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        int l = 0;
        int r = people.size()-1;
        sort(people.begin(),people.end());
        for(;l<=r;r--)
        {
            if(people[l] + people[r] <= limit)
            {
                l++;
            }
            ans++;
        }

        return ans;
    }
};