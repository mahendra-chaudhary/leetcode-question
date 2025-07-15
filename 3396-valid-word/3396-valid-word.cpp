class Solution {
public:
    bool isValid(string word) {

        if(word.size()<3) return false;
        string vowel = "aeiouAEIOU";

         int vowels = 0;
         int consonants = 0;

        for(char c : word){
            if(isalpha(c)){
                if(vowel.find(c) != -1) vowels++;
                else{
                    consonants ++;
                }
                
            }
            else if(!isdigit(c)){
                return false;
            }
        }

 return vowels >=1 && consonants >=1;


        
    }
};