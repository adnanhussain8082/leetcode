class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> shift(n+1,0);  //this is basically a difference array works on a difference array Technique

        for(int i=0;i<shifts.size();i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int dir = shifts[i][2]; //direction

            shift[start] += (dir==1 ? +1 : -1);
            shift[end+1] += (dir==1 ? -1 : +1);
        }

        int curr=0;
        for(int i=0;i<n;i++){   //to generate the prefix sum (we will do it in the same shift array)
            shift[i] += curr;
            curr = shift[i];
        }

        //now do the shifting of letters
        for(int i=0;i<n;i++){
            shift[i] = (shift[i]%26 + 26)%26; //the +26 added to handle the negatives in the prefix array
            s[i] = 'a' + ((s[i]-'a') + shift[i])%26;
        }

        return s;
    }
};