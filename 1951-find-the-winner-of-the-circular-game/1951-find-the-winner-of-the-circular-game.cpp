class Solution {
public:
    int findTheWinner(int n, int k) {

        if(k > n) k = k%n;
        queue<int>q;
        for(int i = 1;i<=n;i++)
        {
            q.push(i);
        }
        k--;
        while(q.size() > 1)
        {
            int temp = k;
            while(temp-- > 0)
            {
                q.push(q.front());

                q.pop();
            }
            
            cout<<endl;
            q.pop();
        }
        return q.front();

    }
};