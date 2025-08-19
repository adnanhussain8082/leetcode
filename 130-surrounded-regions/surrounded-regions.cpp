class Solution {

    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};

private:
    void dfs(int row , int col , vector<vector<char>>& board , vector<vector<int>>& vis , int& m , int& n){
        vis[row][col] = 1;

        for(int i=0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and board[nrow][ncol]=='O' and vis[nrow][ncol]==0){
                dfs(nrow , ncol , board , vis , m , n);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>> vis(m , vector<int>(n,0));

        //row wise, ist and last row
        for(int j=0;j<n;j++){

            //ist row
            if(board[0][j]=='O' and vis[0][j]==0){
                dfs(0 , j , board , vis , m , n);
            }

            //last row
            if(board[m-1][j]=='O' and vis[m-1][j]==0){
                dfs(m-1 , j , board , vis , m , n);
            }
        }

        //column wise, ist and last column
        for(int i=0;i<m;i++){

            //ist column
            if(board[i][0]=='O' and vis[i][0]==0){
                dfs(i , 0 , board , vis , m , n);
            }

            //last column
            if(board[i][n-1]=='O' and vis[i][n-1]==0){
                dfs(i , n-1 , board , vis , m , n);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' and vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};