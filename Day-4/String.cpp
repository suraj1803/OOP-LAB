#include <iostream>
#include <string.h>
using namespace std;

class String
{
private:
    char *str;

public:
    String(const char *s)
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    bool operator==(const String &s)
    {
        return strcmp(this->str, s.str) == 0;
    }

    friend bool operator==(const String &s1, const String &s2);

    ~String()
    {
        delete[] str;
    }
};

bool operator==(const String &s1, const String &s2)
{
    return strcmp(s1.str, s2.str) == 0;
}

int main()
{
    String s1("hi"), s2("hii");
    if (s1 == s2)
    {
        cout << "Strings are equal\n";
    }
    else
    {
        cout << "Strings are not equal\n";
    }

    return 0;
}
