#include <bits/stdc++.h>
using namespace std;

void reverse_st(vector <string> &words){
    int i=0;
    int j=words.size()-1;
     while(i<j){
        swap(words[i],words[j]);
        i++;
        j--;
     }
}

int main() {
    string st;

    cout << "Enter the string: ";
    getline(cin, st);

    cout << endl << st << endl;  // Print the original string

    int word = 0;
    vector<string> words;  // Use a more descriptive name

    for (int i = 0; st[i] != '\0'; i++) {
        if (st[i] == ' ') {
            word++;  // Increment word count only when a space is encountered
        } else {
            if (word >= words.size()) {  // Check if word index is within bounds
                words.push_back("");    // Add an empty string for a new word
            }
            words[word].push_back(st[i]); // Push character to the current word
        }
    }

    reverse_st(words);


    cout << "Words:" << endl;
    for (string j : words) {
        cout << j << " ";
    }
    cout << endl;
    string ans;

    for(int k=0;k<words.size();k++){

        if(k==words.size()-1) ans+=words[k];

        else {
            ans+=words[k];
            ans+=' ';
        }

    }

    cout<<endl<<ans;

    return 0;
}