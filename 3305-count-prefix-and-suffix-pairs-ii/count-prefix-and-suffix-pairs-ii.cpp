#define ll long long int
class TrieNode{
public:
    unordered_map<int,TrieNode*> children;
    int count;

    TrieNode(){
        count=0;
    }
};

class Solution {
public:
    TrieNode* root;

    Solution(){
        root = new TrieNode();
    }

    long long countPrefixSuffixPairs(vector<string>& words) {
        ll ans=0;

        for(auto word : words){
            TrieNode* cur = root;
            int n=word.size();

            for(int i=0;i<n;i++){
                int node = word[i]*128 + word[n-i-1];
                
                if(cur->children.find(node) == cur->children.end()){
                    cur->children[node] = new TrieNode();
                }

                cur = cur->children[node];
                ans += cur->count;
            }
            cur->count++;
        }
        return ans;
    }
};