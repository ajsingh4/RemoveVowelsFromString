//
//  main.cpp
//  RemoveVowelsFromString
//
//  Created by Aj Gill on 7/28/19.
//  Copyright © 2019 Aj Gill. All rights reserved.
//

#include <iostream>
#include <set>

//For ease of access
using namespace std;

void removeVowels(string &word){
    //Initialize strings of vowels to search
    string capitalVowels = "AEIOU", lowercaseVowels = "aeiou";
    //Initialize "slow" pointer
    int consonantLocation = 0;
    for(int i=0; i<word.length(); i++){
        //If it's not a vowel
        if(capitalVowels.find(word[i]) == string::npos && lowercaseVowels.find(word[i]) == string::npos){
            //Swapping the consonant for a vowel location & moving the consonant location pointer up
            word[consonantLocation] = word[i];
            consonantLocation++;
        }
    }
    //Get the beginning portion of the word that contains only consonants
    word.resize(consonantLocation);
}

int main() {
    string word = "AIRPLANE";
    cout << "Initial word: " << word;
    removeVowels(word);
    cout << "\nWord without vowels: " << word << endl;
}
