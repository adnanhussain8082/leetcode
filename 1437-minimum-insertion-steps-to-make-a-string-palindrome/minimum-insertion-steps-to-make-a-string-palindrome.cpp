// class Solution {
// private:
//     //method5: space-optimization
//     int solve5(int& n , int& m , string& text1, string& text2){
//         vector<int> prev(m+1 , 0);
//         vector<int> curr(m+1 , 0);
//         //base cases equivalent
//         for(int j=0;j<=m;j++) prev[j]=0;

//         //nested loops
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(text1[i-1]==text2[j-1]){  //shifted index's
//                     curr[j] = 1+prev[j-1];
//                 }
//                 else{
//                     curr[j] = max( curr[j-1] , prev[j] );
//                 }
//             }

//             prev=curr;
//         }

//         return prev[m];
//     }
// public:
//     int minInsertions(string s) {
//         int i=s.size();
//         int j=i;
//         string rev_s = s; //rev_s=reversed s
//         reverse(rev_s.begin(),rev_s.end());
//         //method5:
//         int longest_palindromic_seq = solve5(i , j , s , rev_s);

//         return i - longest_palindromic_seq;
//     }
// };







class Solution {

public:
    int minInsertions(string s) {
       int m=s.size();
       vector<int> prev(m+1,0);
       
       string rev_s = s;
       reverse(s.begin(),s.end());

       for(int i=1;i<=m;i++){
        vector<int> temp(m+1,0);
        for(int j=1;j<=m;j++){
            if(s[i-1]==rev_s[j-1]){
                temp[j] = 1 + prev[j-1];
            }
            else{
                temp[j] = max(prev[j] , temp[j-1]);
            }
        }
        prev=temp;
       }

       return m-prev[m];
    }
};