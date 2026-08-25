class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        //we can use hashmap as well but since nums[i]<=100
        //so we will use const size array instead

        vector<bool> present(101,false);

        for(int num : nums){
            present[num]=true;
        }

        for(int multiple=k ;; multiple+=k){
            if(multiple>100 or !present[multiple]){
                return multiple;
            }
        }

        return -1;
        
    }
};