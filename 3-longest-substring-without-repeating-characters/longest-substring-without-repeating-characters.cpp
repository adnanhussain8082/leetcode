class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);
        int n=s.size();
        int i=0 , j=0;
        int maxLen=0;

        for(int j=0;j<n;j++){
            if(hash[s[j]]!=-1){
                if(hash[s[j]]>=i){
                    i=hash[s[j]]+1;
                }
            }

            maxLen = max(maxLen , j-i+1);
            hash[s[j]]=j;

        }
        return maxLen;
    }
};