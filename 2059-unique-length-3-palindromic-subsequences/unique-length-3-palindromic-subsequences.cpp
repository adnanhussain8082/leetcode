class Solution {
public:
    int countPalindromicSubsequence(string s) {
        //check Note for some important insights and solution link

        int first[26]={[0 ... 25]=INT_MAX}; //syntax to declare every element of array with same value, but only works with GCC
        int last[26]={};
        int count=0;

        for(int i=0;i<s.size();i++){
            first[s[i]-'a']=min(first[s[i]-'a'],i);
            last[s[i]-'a']=i;
        }

        for(int i=0;i<26;i++){
            if(first[i]<last[i])
                count += unordered_set(s.begin()+first[i]+1 , s.begin()+last[i]).size();
        }
        return count;
    }
};