class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n=nums1.size() , m=nums2.size();
        vector<vector<int>> ans;
        vector<int> temp(2,-1);
        int i , j;

        for(i=0 , j=0; i<n && j<m;){
            if(nums1[i][0]==nums2[j][0]){
                temp[0]=nums1[i][0];
                temp[1]=nums1[i][1]+nums2[j][1];
                ans.push_back(temp);
                i++ , j++;
            }
            else if(nums1[i][0] < nums2[j][0]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i<n){
            ans.push_back(nums1[i++]);
        }
        while(j<m){
            ans.push_back(nums2[j++]);
        }
        return ans;
    }
};