class Solution {
public:
    int maxDifference(string s) {
        vector<int> hash(26,0);
        // int n=s.size();

        for(char ch : s){
            hash[ch-'a']++;
        }

        int maxOddCount=0 , minEvenCount=1e9;

        for(int i : hash){
            if (i==0) continue;

            else if((i&1)==1){
                maxOddCount = max(maxOddCount , i); 
            }
            
            else{
                minEvenCount = min(minEvenCount , i);
            }
        }

        return maxOddCount - minEvenCount;
    }
};