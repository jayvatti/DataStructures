#include <iostream>

int length(char length[]){
    int i;
    for( i = 0; length[i] != '\0'; i++){
    }
    return i;
}
void uppercase(char uppercase[]){
    int i = 0;
    for(i = 0; uppercase[i] != '\0';i++){
        if(int(uppercase[i]) >= 97 && int(uppercase[i]) <= 122){
            uppercase[i] = uppercase[i] - 32;

        }
    }
}
void reverse(char reverse[]){
    int reverseLen = length(reverse);
    reverseLen = reverseLen - 1;
    int i;
    for(i = 0; i < reverseLen; i++, reverseLen--){
        char temp = reverse[i];
        reverse[i]=reverse[reverseLen];
        reverse[reverseLen] = temp;
    }

}

bool validateWord(char *validate){
    for(int i = 0;validate[i] != '\0'; i++){
        if((int(validate[i]) >= 65 && int(validate[i]) <= 90) || (int(validate[i]) >= 97 && int(validate[i]) <= 122)){
            return true;
        }
    }
    return false;
}

bool palindrome(char palindrome[]){
    int len = length(palindrome);
    len = len - 1;
    int i;
    for(i = 0; i < len; i++, len--){
        if(palindrome[i] == palindrome[len]){
            return true;
        }
    }
    return false;
}


int main() {

    char a = 'a';
    a = a + 2;

    std::cout<<a<<std::endl; // c

    char array[] = {'a','b','c','d','\0'};
    char array2[] = "hello"; //automatically assigns \0 at the end;
    std::cout<<array<<std::endl;
    std::cout<<array2<<std::endl;
    std::cout<<"Length:"<<length(array)<<std::endl;



    char *name = "jay";
    std::cout<<"Validate Word: "<<validateWord(name)<<std::endl;

    uppercase(array);//uppercase array
    reverse(array);
    std::cout<<"ReverseArray:"<<array<<std::endl; //OUTPUT: DCBA

    char palindromeWord[] = "liril";
    std::cout<<"Palindrome:"<<palindrome(palindromeWord)<<std::endl;
    std::cout<<"Palindrome:"<<palindrome(array)<<std::endl;

    //-------------------------------------------------------------------------
    //DUPLICATES for small letters //increase the HASH for capitals and numbers
    int hash[26] = {0};
    char word[] = "strings";
    for(int i = 0; word[i] != '\0'; i++ ){
        hash[word[i] - 97] += 1;
    }
    for(int i = 0; i < 26 ; i++){
        if(hash[i] > 1){
            std::cout<<char(i + 97)<<":"<<hash[i]<<std::endl;
        }
    }
    //-------------------------------------------------------------------------
    //ANAGRAMS for small letters
    char word1[] = "heart";
    char word2[] = "ecrth";

    int anagramHash[26] = {0};
    for(int i = 0; word1[i] != '\0'; i++){
        anagramHash[word1[i] - 97] += 1;
    }
    for(int i = 0; word2[i] != '\0'; i++ ){
        anagramHash[word2[i] - 97] -= 1;
    }
    for(int i = 0; i < 26; i++ ){
        if(anagramHash[i] != 0){
            std::cout<<"Not anagrams"<<std::endl;
            break;
        }
    }
}
//-------------------------------------------------------------------------
//PERMUTATIONS
