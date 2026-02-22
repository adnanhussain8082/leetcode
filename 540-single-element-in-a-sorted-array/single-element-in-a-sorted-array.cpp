class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int s=0 , e=v.size()-1;

        while(s<=e){

            int mid = s + (e-s)/2; 

            if(s==e) return v[s];

            if((mid & 1)==0){ //even case
                if(v[mid]==v[mid+1]){
                    s=mid+2;
                }
                else{
                    e=mid;
                }
            }

            else{
                if(v[mid]==v[mid-1]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }
        return -1;
    }
};