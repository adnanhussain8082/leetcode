class Solution {
private:
    bool solve4(int n , int sum , vector<int>& arr){
        vector<bool> prev(sum+1 , false);
        
        //base case equivalent
        prev[0]=true;
        
        if(arr[0]<=sum) prev[arr[0]]=true;
        
        for(int ind=1;ind<n;ind++){
            vector<bool> curr(sum+1 , false);
            curr[0]=true; //again, this is the base case equivalent of if ind==0 of recursion
            
            for(int target=1;target<=sum;target++){
                bool notTake = prev[target];
                bool take = false; //initially for every call
                if(arr[ind]<=target){
                    take = prev[target-arr[ind]];
                }
        
                curr[target] = take || notTake;
            }
            
            prev=curr;
        }
        
        return prev[sum];
        
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        //this is based on gfg Subset Sum Problem-already solved(DP lec 14)
        int soa=accumulate(nums.begin(),nums.end(),0);

        //catch
        if((soa & 1)==1) return false; //soa=odd,so we cant divide this array into exactly two arrays having same sum

        //otherwise apply Subset Sum Problem logic
        int target=soa/2;
        return solve4(n , target , nums);
    }
};