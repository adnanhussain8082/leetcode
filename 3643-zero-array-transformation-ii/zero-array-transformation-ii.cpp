class Solution {
private:
    bool canTransform(vector<int>& nums, vector<vector<int>>& queries , int k){
        int n=nums.size();
        vector<int> diffArr(n,0);

        for(int i=0;i<k;i++){
            int l=queries[i][0] , r=queries[i][1] , val=queries[i][2];

            diffArr[l] += val;
            if(r+1 < n) diffArr[r+1] -= val; 

        }

        //generating prefix sum array
        for(int i=1;i<n;i++){
            diffArr[i] += diffArr[i-1];
        }

        for(int i=0;i<n;i++){
            if(diffArr[i] < nums[i]) return false;
        }

        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l=0 , r=queries.size() , ans=-1;

        //binary search
        while(l<=r){
            int mid = l + (r-l)/2;
            if(canTransform(nums , queries , mid)){
                ans = mid;
                r = mid-1;  //looking for a smaller answer
            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }
};