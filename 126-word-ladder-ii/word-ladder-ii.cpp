class Solution {
unordered_map<string,int> mpp;
vector<vector<string>> ans;
string BeginWord;

private:
    void dfs(string word , vector<string>& seq){
        //base case
        if(word == BeginWord){
            reverse(seq.begin(),seq.end());

            ans.push_back(seq);

            reverse(seq.begin(),seq.end());

            return;
        }

        int steps=mpp[word];
        int sz=word.size();

        for(int i=0;i<sz;i++){
            char original = word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;

                if((mpp.find(word) != mpp.end()) and (mpp[word]+1 == steps)){
                    seq.push_back(word);

                    dfs(word , seq);

                    seq.pop_back();
                }
            }

            word[i] = original;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        BeginWord = beginWord;
        queue<string> q;

        unordered_set<string> st(wordList.begin(),wordList.end());

        q.push(beginWord);
        mpp[beginWord] = 1;
        st.erase(beginWord);
        int sz=beginWord.size();

        while(!q.empty()){
            string word = q.front();
            q.pop();

            int steps = mpp[word];

            if(word == endWord) break;

            for(int i=0;i<sz;i++){
                char original = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;

                    if(st.find(word) != st.end()){
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps+1;
                    }
                }

                word[i] = original;
            }
        }

        if(mpp.find(endWord) != mpp.end()){
            vector<string> seq;

            seq.push_back(endWord);

            dfs(endWord , seq);
        }

        return ans;
    }
};