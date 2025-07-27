// class Solution {
// public:

//     // /Basic explanation:
//     // /They are using the first row and column as a memory to keep track of all the 
//     // /0's in the entire matrix.

//     void setZeroes(vector<vector<int>>& matrix) {
//         bool fr=false , fc=false;
//         int m=matrix.size() , n=matrix[0].size();

//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j]==0){
//                     if(i==0) fr=true;
//                     if(j==0) fc=true;
//                     matrix[0][j]=0; //mark in the first row
//                     matrix[i][0]=0; //mark in the first col
//                 }
//             }
//         }

//         //now start from ist row and ist col, and using them start putting zeros
//         for(int i=1;i<m;i++){
//             for(int j=1;j<n;j++){
//                 if(matrix[0][j]==0 || matrix[i][0]==0){
//                     matrix[i][j]=0;
//                 }
//             }
//         }

//         //now deal the with first row and first col
//         if(fr){
//             for(int j=0;j<n;j++){
//                 matrix[0][j]=0;
//             }
//         }

//         if(fc){
//             for(int i=0;i<m;i++){
//                 matrix[i][0]=0;
//             }
//         }
//     }
// };



class Solution {
public:

    // /Basic explanation:
    // /They are using the first row and column as a memory to keep track of all the 
    // /0's in the entire matrix.

    void setZeroes(vector<vector<int>>& matrix) {
        bool fr=false , fc=false;
        int m=matrix.size() , n=matrix[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(i==0) fr=true;
                    if(j==0) fc=true;

                    matrix[0][j]=0;
                    matrix[i][0]=0;

                }
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[0][j]==0 or matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }

        if(fr){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }

        if(fc){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};