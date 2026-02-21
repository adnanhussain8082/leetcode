class Solution {
public:
    unordered_map<char,bool>rowCheck;
    unordered_map<char,bool>upperleftdiagoalCheck;
    unordered_map<char,bool>lowerleftdiagoalCheck;

    void storeAnswer(vector<vector<char>>& board ,vector<vector<string>>& ans , int n){
        vector<string> temp;
        for(int i=0;i<n;i++){
            string output="";
            for(int j=0;j<n;j++){
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row , int col , vector<vector<char>>& board , int n){

        if(rowCheck[row]==true){
            return false;
        }

        if(upperleftdiagoalCheck[(n-1)+(col-row)]==true){
            return false;
        }

        if(lowerleftdiagoalCheck[row+col]==true){
            return false;
        }

        return true;
    }

    void solve(vector<vector<char>>& board , int col , int n , vector<vector<string>>& ans ){

        //base case
        if(col>=n){
            storeAnswer(board , ans , n);
            return;
        }
        //sol for one case
        for(int row=0;row<n;row++){

            if(isSafe(row , col , board , n)){

                //placing the queeen
                board[row][col]='Q';
                //put entry in map
                rowCheck[row]=true;
                upperleftdiagoalCheck[(n-1)+(col-row)]=true;
                lowerleftdiagoalCheck[col+row]=true;

                //call the function again for col+1
                solve(board , col+1 , n , ans);

                //backTracking
                board[row][col]='.';
                //put entry in map
                rowCheck[row]=false;
                upperleftdiagoalCheck[(n-1)+(col-row)]=false;
                lowerleftdiagoalCheck[col+row]=false;

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n , vector<char>(n , '.'));
        vector<vector<string>> ans;
        int col=0;

        solve(board , col , n , ans);
        return ans;
    }
};