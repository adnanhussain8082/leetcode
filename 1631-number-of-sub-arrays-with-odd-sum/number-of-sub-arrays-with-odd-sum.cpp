class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9+7;
        int prefixSum=0 , odd_count=0 , even_count=1;
        long total=0;

        for(auto& ele : arr){
            prefixSum += ele;

            if(prefixSum & 1){    //odd 
                total = (total + even_count)%mod;
                odd_count++;
            }
            else{
                total = (total + odd_count)%mod;
                even_count++;
            }
        }
        return total;
    }
};