class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int len=0;
        vector<int> freq(26,0);
        
        for(auto c : s){
            freq[c-'a']++;
        }

        for(auto f : freq){
            if(f==0) continue;
            if((f&1)==0){ //even freq of a char
                len+=2;
            }
            else{
                len+=1;
            }
        }
        return len;
    }
};