class Solution {
private:
    int sumofdigits(int n){
        int sum=0;
        while(n>0){
            int digit=n%10;
            sum += digit;
            n/=10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> mpp;

        for(int i=1;i<=n;i++){
            mpp[sumofdigits(i)]++;
        }

        int maxLenCount=0;
        int maxLen=0;

        for(auto it : mpp){
            int len = it.second;
            if(len > maxLen){
                maxLenCount=0;
                maxLen=len;
                maxLenCount++;
            }
            else if(len == maxLen){
                maxLenCount++;
            }
        }

        return maxLenCount;
    }
};