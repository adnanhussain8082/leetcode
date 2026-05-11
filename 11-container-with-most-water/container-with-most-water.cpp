class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0 , j=height.size()-1;
        int ans=0;
        while(i<j){
            int leftmax=height[i] , rightmax=height[j];
            int temp = (j-i)*min(leftmax,rightmax);
            ans = max(ans , temp);

            if(leftmax<rightmax){
                i++;
            }
            else{
                j--;
            }
        }

        return ans;

    }
};