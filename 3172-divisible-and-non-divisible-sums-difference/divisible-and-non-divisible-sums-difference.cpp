class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalsum = (n*(n+1))/2;
        int num1=0 , num2=0;
        int i=1;

        while(i*m <= n){
            num2 += i*m;
            i++;
        }

        // cout<<num2<<" ";
        // cout<<totalsum;

        num1 = totalsum - num2;
        return num1 - num2;
    }
};