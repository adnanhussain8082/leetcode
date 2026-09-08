class Solution {
private:
    bool helper(vector<int>& weights, int& wt , int& days){
        //int n=weights.size();
        int wt_sum=0;
        int day_count=1; //start with day 1

        for(auto it : weights){

            if(wt_sum+it > wt){ //we will first check that if adding current days weight exceeds the limit
                day_count++;
                wt_sum = it;

                if(day_count > days){
                    return false;
                }
            }
            else{
                wt_sum += it;
            }

        }

        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        //int n=weights.size();

        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans=-1;

        //linear search
        // for(int i=low;i<=high;i++){
        //     if(helper(weights , i , days)){
        //         ans=i;
        //         break;
        //     }
        // }

        //binary search
        while(low<=high){
            int mid = low + (high-low)/2;

            if(helper(weights , mid , days)){
                ans = mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};