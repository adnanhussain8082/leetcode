class Solution {
private:
    bool isVowel(char& ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    long long CountAtleast(string& word , int k){
        int left=0 , right=0;
        int consonantCount=0;
        long long validCount=0;
        unordered_map<char,int> vowelFreq;

        while(right<word.length()){
            if(isVowel(word[right])){
                vowelFreq[word[right]]++;
            }
            else{
                consonantCount++;
            }

            while(vowelFreq.size()==5 && consonantCount>=k){
                validCount += word.length()-right;
                if(isVowel(word[left])){
                    if(--vowelFreq[word[left]]==0){
                        vowelFreq.erase(word[left]);
                    }
                }
                else{
                    consonantCount--;
                }

                left++;
            }

            right++;
        }
        return validCount;
    }
public:
    long long countOfSubstrings(string word, int k) {
        return CountAtleast(word , k) - CountAtleast(word , k+1);
    }
};