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
    if(*A == 'A' || *A == 'A'){
        return true;
    }
    else if(*A == 'E' || *A == 'e'){
        return true;
    }
    else if(*A == 'I' || *A == 'i'){
        return true;
    }
    else if(*A == 'O' || *A == 'o'){
        return true;
    }
    else if(*A == 'U' || *A == 'u'){
        return true;
    }
    else{
        return false;
    }
}

string removeVowels(string word){
    string answer;
    //Initialize a stack to utilize LIFO
    stack<char> reverser;
    for(int i=0; i<word.length(); i++){
        //If the letter is not a vowel, it is added to the stack
        if(!checkForVowels(&word[i])){
            reverser.push(word[i]);
        }
    }
    int size = reverser.size();
    //Go through the stack elements and get characters in the reverse order
    for(int j=0; j<size; j++){
        answer += reverser.top();
        reverser.pop();
    }
    return answer;
}

int main() {
    string word = "AIRPLANE";
    string finalAnswer = removeVowels(word);
    cout << "Initial word: " << word;
    cout << "\nWord reversed without vowels: " << finalAnswer << endl;
}
