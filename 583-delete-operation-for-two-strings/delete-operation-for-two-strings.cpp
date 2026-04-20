class Solution {
private:
    //method5: space-optimization
    int solve5(int& n , int& m , string& text1, string& text2){
        vector<int> prev(m+1 , 0);
        vector<int> curr(m+1 , 0);
        //base cases equivalent
        // for(int j=0;j<=m;j++) prev[j]=0;

        //nested loops
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){  //shifted index's
                    curr[j] = 1+prev[j-1];
                }
                else{
                    curr[j] = max( curr[j-1] , prev[j] );
                }
            }

            prev=curr;
        }

        return prev[m];
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size() , m=word2.size();
        int LCS_length = solve5(n , m , word1 , word2);

        return m+n - 2*LCS_length;
    }
};