#include <iostream>
using namespace std;

int main() { 
  char c;
  int char_count = 0;
  int word_count = 0;
  int lines_count = 0;

  bool in = false;
  while ((c = getchar()) != EOF) {
    char_count++;
    if (c == '\n') {
      lines_count++;
      in = false;
    }
    else if (c == ' ' || c == '\t') {
      in = false;
    }
    else {
      if (!in) {
        word_count++;
        in = true;
      }
    }
  }

  cout << "Characters: " << char_count << endl;
  cout << "Words: " << word_count << endl;
  cout << "lines: " << lines_count << endl;

  return 0;
}
