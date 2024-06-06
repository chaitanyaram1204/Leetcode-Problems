class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0) return false;

        map<int,int>mp;

        for(int i = 0;i<hand.size();i++)  mp[hand[i]]++;

        for(auto [ele,freq] : mp)
        {
            if(freq == 0) continue;
            while(freq --)
            {
                for(int curr = ele;curr<ele+groupSize;curr++)
                {
                    if(mp[curr] == 0) return false;
                    mp[curr]--;
                }
            }
        }
        return true;

    }
};