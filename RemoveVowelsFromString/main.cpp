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

//Function that returns true if it's a vowel, false otherwise
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
    set<int> vowelIndices;
    //Handle the reversing before doing any manipulation
    reverse(word.begin(),word.end());
    for(int i=0; i<word.length(); i++){
        //If it is a vowel and the number of characters + vowel count doesnt exceed word length
        if(checkForVowels(&word[i])){
            //Keeping track of the vowelCount to use as an index later
            if(!vowelIndices.count(i)){
                vowelCount++;
            }
            //Store the index of the vowel
            vowelIndices.insert(i);
        }

        else if(!vowelIndices.empty()){
            //Get the first available index
            int index = *vowelIndices.begin();
            //Erase that index from the set
            vowelIndices.erase(vowelIndices.begin());
            //Insert new index into the set
            vowelIndices.insert(i);
            //Store the current consonant
            char temp = word[i];
            //Set the current consonants place = to the vowels
            word[i] = word[index];
            //Store the old consonant into the vowels place
            word[index] = temp;
        }
        
    }
    //Cut off the vowels at the end of the string
    word = word.substr(0,word.length()-vowelCount);
    return word;
}

int main() {
    string word = "siiaxasiuebvalvvnueaioewhfhaljkbcsxcal";
    cout << "Initial word: " << word;
    string finalAnswer = removeVowels(word);
    cout << "\nWord reversed without vowels: " << finalAnswer << endl;
}
