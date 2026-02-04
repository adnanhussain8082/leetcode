class Solution {
public:
    string getPermutation(int n, int k) {
        string v(n, '\0');  // n null characters
        for(int i=0;i<n;i++){
            v[i]=char('1'+i);
        }

        for(int i=0;i<k-1;i++){

            int index , j;

            for(index=n-2;index>=0;index--){
                if(v[index]<v[index+1]){
                    break;
                }
            }

            if(index<0){
                reverse(v.begin(),v.end());
            }

            else{
                for(j=n-1;j>index;j--){
                    if(v[j]>v[index]){
                        break;
                    }
                }

                swap(v[index],v[j]);
                reverse(v.begin()+index+1,v.end());
            }
        }

        return v;
    }
};