class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int>pq;
        for(auto number : nums) 
            pq.push(number);

        while(k){
            int value = pq.top();
            score += value;
            pq.pop();
            k--;
            pq.push((value+2)/3);
        }
        return score;
    }
};