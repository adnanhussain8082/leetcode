class Solution {
public:
    int trap(vector<int>& height) {
    //here optimal soln others are present in striver notes link in notepad

    int l=0;
    int r=height.size()-1;
    int leftmax , rightmax , total;
    leftmax=rightmax=total=0;

        while(l<r){
            if(height[l]<=height[r]){
                //check if leftmax is greater then current left block
                if(leftmax > height[l]){
                    total += leftmax - height[l];
                }
                else{ //means leftmax is less than or equal to the current left block
                    leftmax = height[l];
                }

                l++;  //in either cases increment left pointer
            }

            else{
                //check if rightmax is greater then the current right block
                if(rightmax > height[r]){
                    total += rightmax - height[r];
                }
                else{ //means rightmax is smaller than or equal to the current right block
                    rightmax = height[r];
                }

                r--; //in either cases decrement the right pointer
            }
        }
    return total;
    }
};