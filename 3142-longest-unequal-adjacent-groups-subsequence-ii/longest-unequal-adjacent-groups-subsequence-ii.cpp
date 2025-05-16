class Solution {
private:
    bool differByOneChar(string& s1 , string& s2){
        if(s1.length() != s2.length()) return false;
        int diffchar=0;

        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]) diffchar++; 
        }

        return diffchar == 1;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();

        vector<int> dp(n , 1);
        vector<int> parent(n , -1);
        int maxi=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(groups[j]!=groups[i] && differByOneChar(words[j],words[i]) && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    parent[i]=j;
                }
            }
            maxi = max(maxi , dp[i]);
        }

        vector<string> ans;

        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                while(i!=-1){
                    ans.push_back(words[i]);
                    i=parent[i];
                }
                break;
            }
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};