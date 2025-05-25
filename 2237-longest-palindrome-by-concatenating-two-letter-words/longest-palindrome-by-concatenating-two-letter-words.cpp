class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mpp;

        int unpaired=0 , ans=0;

        for(string st : words){
            if(st[0]==st[1]){
                if(mpp[st]>0){
                    ans+=4;
                    unpaired--;
                    mpp[st]--;
                }
                else{
                    unpaired++;
                    mpp[st]++;
                }
            }
            else{
                string rev = st;
                reverse(rev.begin(),rev.end());
                if(mpp[rev]>0){
                    ans+=4;
                    mpp[rev]--;
                }
                else{
                    mpp[st]++;
                }
            }
        }

        if(unpaired>0) ans+=2;

        return ans;
    }
};