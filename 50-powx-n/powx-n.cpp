                   //  using binary exponentiation(O(logn , base 2))
class Solution {
public:
    double myPow(double x, long n) {
        long y = abs(n);
        double res=1.0;

        while(y>=1){
            if(y & 1 == 1){
                res *= x;
            }

            x = x*x;
            y = y/2;
        }

        return n > 0 ? res : 1/res;  //because n can be negative as well
    }
};




// class Solution {
//     double mul(double x , long n){
//         if(n==1){
//             return x;
//     }
//         else if(n%2==0){
//             return mul(x*x , n/2);
//         }
//         else{
//             return x*mul(x,n-1);
//         }
//     }
// public:
//     double myPow(double x, long n) {
//         if(n==0){
//             return 1;
//         }
//         if(n<0){
//             n*=-1;
//             return mul(1/x,n);
//         }
//         return mul(x,n);
//     }
// };