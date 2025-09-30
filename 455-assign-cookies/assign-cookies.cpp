class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g),end(g));
        sort(begin(s),end(s));

        int i=0 , j=0 , c=0;

        while(i<g.size() and j<s.size()){
            if(s[j]>=g[i]){
                i++ , j++ , c++;
            }
            else j++;
        }

        return c;
    }
};