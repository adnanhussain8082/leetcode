// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n=s.size();
//         int cnt=0;
//         int hash[3]={-1,-1,-1};

//         for(int i=0;i<n;i++){
//             hash[s[i]-'a']=i;

//             if(hash[0]!=-1 && hash[1]!=-1 && hash[2]!=-1){
//                 cnt = cnt + (1 + min(hash[0] , min(hash[1] , hash[2])));
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int left=0 , right=0;
        int res=0;

        unordered_map<char,int> mpp;
        mpp['a']=0 , mpp['b']=0 , mpp['c']=0; 

        while(right<n){
            mpp[s[right]]++;

            while(mpp.size()==3 && mpp['a']!=0 && mpp['b']!=0 && mpp['c']!=0){
                res += s.size() - right;

                if(--mpp[s[left]]==0){
                    mpp.erase(s[left]);
                }
                left++;
            }
            right++;
        }
        return res;
    }
};