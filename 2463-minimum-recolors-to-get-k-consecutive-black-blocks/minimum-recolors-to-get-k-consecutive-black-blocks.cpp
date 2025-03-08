class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        vector<int> map(n,0);
        int cnt=0;

        for(int i=0;i<n;i++){
            if(blocks[i]=='W') cnt++;
            map[i]=cnt;
        }

        if(cnt==0) return 0;

        int ans=INT_MAX;
        int i=0 , j=k-1;
        int temp;

        while(j<n){
            if(i!=0){
               temp = map[j]-map[i-1];
            }
            else{
                temp = map[j];
            }
            ans = min(ans , temp);
            i++ , j++;
        }
        return ans;
    }
};