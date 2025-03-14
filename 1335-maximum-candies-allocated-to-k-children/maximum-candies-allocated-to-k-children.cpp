class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left=0 , right=1e7;

        //check Note

        while(left<right){
            long sum=0 , mid = left + (right-left+1)/2; // Notice the +1 in mid (when moving left up.)

            for(auto& it : candies){
                sum += it/mid;
            }

            if(k > sum){
                right = mid-1;
            }
            else{  // k<=sum
                left=mid;
            }
        }
        return left;
    }
};