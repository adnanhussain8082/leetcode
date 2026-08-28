class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0 , j=0 , maxlen=0 , maxfreq=0;
        int hash[26]={0};

        while(j<n){
            hash[s[j]-'A']++;
            maxfreq = max(maxfreq , hash[s[j]-'A']);

            //check validity of the current substring/current window
            if( (j-i+1) - maxfreq > k ){
                hash[s[i]-'A']--;
                i++;
            }

            //update the maxlen if condition allows
            if( (j-i+1) - maxfreq <= k ){
                maxlen = max(maxlen , (j-i+1));
            }

            j++;
        }

        return maxlen;
    }
};