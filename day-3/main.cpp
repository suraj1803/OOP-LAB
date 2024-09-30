#include <iostream>
#include <string.h>
using namespace std;

class String{
private:
    char *str;
public:
    String() {
        String("");
    }
    String(const char *s1) {
        int i = 0;
        while (s1[i] != '\0') {
            i++;
        }

        str = new char[i + 1];

        for (int j = 0; j < i; j++) {
            str[j] = s1[j];
        }
        str[i] = '\0';
    }

    String(String &s) {
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }

    void display() {
        cout << this->str << endl;
    }

    int size() {
        return strlen(str);
    }

    friend String concat(const String &s1, const String &s2);

    ~String() {
        delete[] str;
    }
};

String concat(const String &s1, const String &s2) {
    String newString(s1.str);

    strcat(newString.str, s2.str);
    return newString;
}


int main() {
    String *str1 = new String("suraj");
    cout << (*str1).size() << endl;
    String *str2 = new String("biswas");

    String str3 = concat(*str1, *str2);

    str3.display();
    cout << str3.size() << endl;

    delete str1;
    delete str2;

    return 0;
}