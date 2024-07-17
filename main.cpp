#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

#include "hash.h"
#include "timer.h"

using namespace std;

// ---------- Function prototypes.
string cleanWord(string);

int main() {
  Timer Watch;

  // ---------- Initializing the hash function.
  myHash<string> dictionary;

  // ---------- Cleaning the dictionary, and loading it into the linked list.
  ifstream file("dict.txt");

  string dictWord;

  while (file >> dictWord) {
    dictWord = cleanWord(dictWord);
    dictionary.insert(dictWord);
  }

  // ---------  Close the dictionary file and start the timer.
  file.close();
  Watch.Start();

  // ---------- Opening the book and initializing some required counter
  // variables.
  ifstream book("book.txt");
  string bookWord;

  int unproccessedWords = 0;

  ofstream notChecked("misspelled.txt", ios::app);
  // ---------- Beginning the loop to clean book words and check them if they
  // meet a certain criteria.
  // ---------- If they do not meet the criteria they are skipped for spell
  // checking.
  while (book >> bookWord) {
    bookWord = cleanWord(bookWord);
    if (bookWord.empty()) {
    } else if (!isalpha(bookWord[0])) {
      unproccessedWords++;

    } else {
      bool found = dictionary.find(bookWord);
      if (!found) {
        notChecked << bookWord << "\n";
      } else {
      }
    }
  }
  // --------- Closing the book and misspelled file.
  notChecked.close();
  book.close();

  Watch.Stop();

  // --------- Outputting results from the spell checking.
cout << "dictionary size " << dictionary.getSize() << endl;
cout << "Done checking and these are the results" << endl;
cout << "finished in time: " << Watch.Time() << endl;
cout << "finished in Milliseconds Time: " << Watch.TimeMS() << endl;

  cout << "There are " << myHash<string>::correctCount
       << " words found in the dictionary." << endl;
  cout << myHash<string>::c_compareCount << " compares. Average: "
       << myHash<string>::c_compareCount / myHash<string>::correctCount
       << endl;
  cout << "There are " << myHash<string>::falseCount
       << " words NOT found in the dictionary." << endl;
  cout << myHash<string>::f_compareCount << " compares. Average: "
       << myHash<string>::f_compareCount / myHash<string>::falseCount
       << endl;

cout << "There are " << unproccessedWords << " words not checked. " << endl;

}

// ---------- Clean word function.
string cleanWord(string word) {
  string cleanedWord;
  for (char c : word) {
    if (isalpha(c) || c == '\'' || isdigit(c)) {
      cleanedWord += tolower(c);
    }
  }
  return cleanedWord;
}
