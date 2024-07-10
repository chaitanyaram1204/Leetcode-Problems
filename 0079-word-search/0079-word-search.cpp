class Solution {
public:

    vector<pair<int,int>>directions = {{0,-1},{-1,0},{0,1},{1,0}};
    bool isValid(int i,int j,int n,int m,vector<vector<char>>&board,string word,vector<vector<int>>&vis,int ind)
    {
        return (i >= 0 && i < n && j >= 0 && j < m && board[i][j] == word[ind] && vis[i][j] == 0);
    }
    bool dfs(int i,int j,int n,int m,vector<vector<char>>& board,string word,vector<vector<int>>&vis,int ind)
    {
        if(ind == word.size())
            return true;

        vis[i][j] = 1;
        bool ans = false;
        for(auto dir : directions)
        {
            int x = i + dir.first;
            int y = j + dir.second;
            if(isValid(x,y,n,m,board,word,vis,ind))
            {
               // cout << x << " " << y << endl;
                ans = ans | dfs(x,y,n,m,board,word,vis,ind+1);
            } 
        }

        vis[i][j] = 0;

        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        bool ans = false;
        for(int i = 0; i < n ; i++ )
        {
            for( int j = 0 ; j < m ; j++ )
            {
                if(board[i][j] == word[0])
                {
                    //cout << i << " " << j << endl;
                    ans = ans | dfs(i,j,n,m,board,word,vis,1);

                    if(ans) return true;
                }
            }
        }
        return ans;
    }
};