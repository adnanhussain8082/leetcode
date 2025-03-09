class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // int n=colors.size();  this calculated here gives wrong answer
        int left=0 , count=0;

        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }

        int n=colors.size();

        for(int right=0;right<n;right++){
            if(right>0 && colors[right]==colors[right-1]){
                left=right;
            }

            if(right-left+1 >= k){
                count++;
            }
        }

        return count;
    }
};