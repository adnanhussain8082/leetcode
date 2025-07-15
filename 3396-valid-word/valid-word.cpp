class Solution {
private:
    bool isVowel(char ch){
        return (ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='i' || ch=='I' || ch=='o' || ch=='O' || ch=='u' || ch=='U');
    }

    bool isAlphabet(char ch){
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
    }

    bool isValid(char ch){
        return (isAlphabet(ch) || (ch>='0' && ch<='9'));
    }

public:
    bool isValid(string word) {
        int n=word.length();
        if(n<3) return false;

        bool hasVowel=false, hasConsonant=false;

        for(char ch : word){
            if(!isValid(ch)) return false;

            if(isVowel(ch)){
                hasVowel = true;
            }

            else if(isAlphabet(ch) && !isVowel(ch)){
                hasConsonant = true;
            }
        }

        // cout<<vowel<<consonant;

        return (hasVowel && hasConsonant);
    }
};