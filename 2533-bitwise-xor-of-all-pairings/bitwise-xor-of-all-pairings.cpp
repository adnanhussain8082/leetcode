class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size() , l2=nums2.size();
        int x1=0 , x2=0;

        if((l1 & 1)==1){  //l1 has odd length
           for(auto num : nums2){   //nums2 contributes (table on n/b)
            x2^=num;
            }
        }

        if((l2 & 1)==1){  //l2 has odd length
           for(auto num : nums1){   //nums1 contributes (table on n/b)
            x1^=num;   
            }
        }
        return x1^x2;
    }
};