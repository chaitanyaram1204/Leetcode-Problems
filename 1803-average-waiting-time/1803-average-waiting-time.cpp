class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double waitingTime = 0;
        int n = customers.size();
        int waiter = 0;
        for(int i = 0;i < n ; i++)
        {
            if(waiter < customers[i][0])
                waiter = customers[i][0];
            waiter += customers[i][1];
            waitingTime += (waiter - customers[i][0]);  
        }
        return waitingTime/n;
    }
};