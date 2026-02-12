class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& v, int target) {
        vector<vector<int>> ans;
        int n=v.size();
        sort(v.begin(),v.end());

        for(int i=0;i<n;i++){
            if(i>0 and v[i-1]==v[i]) continue;

            for(int j=i+1;j<n;j++){
                if(j>i+1 and v[j-1]==v[j]) continue;

                int k=j+1 , l=n-1;

                while(k<l){
                    long long sum = v[i];
                    sum += v[j];
                    sum += v[k];
                    sum += v[l];

                    if(sum==target){
                        ans.push_back({v[i],v[j],v[k],v[l]});
                        k++ , l--;

                        while(k<l and v[k-1]==v[k]) k++;
                        while(l>k and v[l]==v[l+1]) l--;
                    }
                    else if(sum<target) k++;
                    else l--;
                }
            }
        }

        return ans;
    }
};