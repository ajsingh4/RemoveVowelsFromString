//
//  main.cpp
//  RemoveVowelsFromString
//
//  Created by Aj Gill on 7/28/19.
//  Copyright © 2019 Aj Gill. All rights reserved.
//

#include <iostream>
#include <stack>

//For ease of access
using namespace std;

bool checkForVowels(char* A){
    if(*A == 'A' || *A == 'a' || *A == 'E' || *A == 'e' || *A == 'I' || *A == 'i' || *A == 'O' || *A == 'o' || *A == 'U' || *A == 'u'){
        return true;
    }
    else{
        return false;
    }
}
string removeVowels(string word){
    int vowelCount = 0;
    reverse(word.begin(),word.end());
    for(int i=0; i<word.length(); i++){
        //If it is a vowel and the number of characters + vowel count doesnt exceed word length
        if(checkForVowels(&word[i]) && (i+vowelCount <= word.length())){
            cout << "Run #" << i << " word: " << word << "\n";
            //Keeping track of the vowelCount to use as an index later
            vowelCount++;
            //Store the vowel temporarily
            char vowel = word[i];
            //Iterate through the rest of the array moving the characters up
            for(int j=i; j<word.length(); j++){
                word[j] = word[j+1];
            }
            //Append the vowel at the end
            word[word.length()-1] = vowel;
        }
    }
    //Cut off the vowels at the end of the string
    word = word.substr(0,vowelCount);
    return word;
}

int main() {
    string word = "AIRPLANE";
    string finalAnswer = removeVowels(word);
    cout << "Initial word: " << word;
    cout << "\nWord reversed without vowels: " << finalAnswer << endl;
}
