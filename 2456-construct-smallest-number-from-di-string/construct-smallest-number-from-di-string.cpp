class Solution {
public:
    string smallestNumber(string pattern) {
        string res;
        int n=pattern.size() , j=0;

        for(int i=0;i<=n;i++){
            res.push_back('1' + i);
            
            if(pattern[i]=='I' || i==n){
                reverse(res.begin()+j , res.end());
                j=i+1;
            }
        }
        return res;
    }
};