class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();

        //base case
        if(n==1) return {1};

        vector<int> ans(n,0);
        vector<int> seen(n+1,0);

        //handle i==0
        ans[0] = A[0]==B[0];
        seen[A[0]]=1 , seen[B[0]]=1;

        for(int i=1;i<n;i++){
            if(A[i]==B[i]){
                ans[i] = ans[i-1] + 1;
            }
            else{
                int count=0;
                if(seen[A[i]]==1) count++;
                if(seen[B[i]]==1) count++;
                ans[i] = ans[i-1] + count;

                // Mark both A[i] and B[i] as seen
                seen[A[i]]=1;
                seen[B[i]]=1;
            }
        }
        return ans;
    }
};