#include <iostream>
#include "string.hpp" 

String::String ()
{
    stringSize = 1;
    str = new char[stringSize];
    str[0] = '\0';
} //Empty string
String::String (char x)
{
    if (x == '\0')
    {
        stringSize = 1;
        str = new char[stringSize];
        str[0] = '\0';
        return;
    }
    stringSize = 2;
    str = new char[stringSize];
    str[0] = x;
    str[1] = '\0';
} //String('x')
String::String (const char x[])
{
    stringSize = 1;
    while (x[stringSize - 1] != '\0')
        stringSize++;
    str = new char[stringSize];
    for (int i = 0; i < stringSize; i++)
        str[i] = x[i];
} //String("abc")
String::String (const String& oString)
{
    stringSize = oString.stringSize;
    str = new char[stringSize];
    for (int i = 0; i < stringSize; i++)
        str[i] = oString.str[i];
} //Copy Constructor
String::~String ()
{
    delete[] str;
} //Destructor
void String::swap (String& oString)
{
    char* x = str;
    int y = stringSize;
    str = oString.str;
    stringSize = oString.stringSize;
    oString.str = x;
    oString.stringSize = y;
} //Constant time swap
String& String::operator= (String oString)
{
    swap(oString);
    return *this;
} //Assignment Copy

int String::capacity () const
{
    return stringSize - 1;
}  //Max chars that can be stored
int  String::length () const
{
    int x = 0;
    while (str[x] != '\0')
        x++;
    return x;
}  //Actual number of chars in string
char& String::operator[] (int x)
{
    return str[x];
} //Accessor/Modifier
char String::operator[] (int x) const
{
    return str[x];
}  //Accessor
    
String& String::operator+= (const String& oString)
{
    char* result = new char[length() + oString.capacity()+1] {'\0', };
    for (int i=0; i<length(); i++)
    {
        result[i] = str[i];
    }
    for (int i=length(); i<length() + oString.capacity(); i++)
    {
        result[i] = oString.str[i-length()];
    }
    *this = String(result);
    delete[] result;
    return *this;
}
bool String::operator== (const String& oString) const
{
    int i=0;
    while (str[i]!='\0' || oString.str[i]!='\0')
    {
        if (str[i]!=oString.str[i])
            return false;
        i++;
    }
    return true;
}
bool String::operator< (const String& oString) const
{
    int i = 0;
    while (str[i] != '\0' && oString.str[i] != '\0' && str[i] == oString.str[i]) {
        i++;
    }
    return str[i] < oString.str[i];
}
String  String::substr (int x, int y) const
{
    if (x<0 || y<0 || x>y || str[0]=='\0')
        return String();
    char* result = new char [capacity()+1] {'\0', };
    for (int i=x; i<=y && i<length(); i++)
        result[i-x]=str[i];
    String result2(result);
    delete[] result;
    return result2;
}  //sub from staring to ending position
int  String::findch (int x,  char y) const
{
    if (x<0 || x>=capacity())
        return -1;
    for (int i=x; str[i]!='\0'; i++)
        if (str[i]==y)
            return i;
    return -1;
}  //Location of charater starting at position
int  String::findstr (int x,  const String& oString) const
{
    if (x<0 || x>capacity())
        return -1;
    for (int i=x; str[i]!='\0'; i++)
    {
        int j=0;
        while (str[i+j]!='\0' && oString.str[j]!='\0' && str[i+j]==oString.str[j])
            j++;
        if (oString.str[j]=='\0')
            return i;
    }
    return -1;
}  //Location of string starting at a position

std::istream& operator>>(std::istream& iString, String& oString)
{
    char x;
    String result;
    iString >> x;
    if (!iString) return iString;
        result += String(x);
    while (iString.get(x) && x != ' ' && x != '\n' && x != '\t' && x != '\r')
        result += String(x);
    oString = result;
    return iString;
}
std::ostream& operator<<(std::ostream& iString, const String& oString)
{
    iString << oString.str;
    return iString;
}


String operator+ (String x, const String& oString)
{
    return x += oString;
}
bool operator== (const char x[], const String& oString)
{
    String temp(x);
    return temp == oString;
}
bool operator== (char x, const String& oString)
{
    String temp(x);
    return temp == oString;
}
bool operator< (const char x[], const String& oString)
{
    String temp(x);
    return temp < oString;
}
bool operator< (char x, const String& oString)
{
    String temp(x);
    return temp < oString;
}
bool operator<= (const String& oString, const String& iString)
{
    return !(oString > iString);
}
bool operator!= (const String& oString, const String& iString)
{
    return !(oString == iString);
}
bool operator>= (const String& oString, const String& iString)
{
    return !(oString < iString);
}
bool operator> (const String& oString, const String& iString)
{
    return iString < oString;
}
std::vector<String> String::split(char x) const
{
    std::vector<String> result;
    int y = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == x)
        {
            result.push_back(substr(y, i - 1));
            y = i + 1;
        }
    }
    result.push_back(substr(y, length() - 1));
    return result;
}
String::String(int x) {
    int temp = x;
    int len = 0;
    bool negative = false;
    if (x < 0) {
        negative = true;
        x *= -1;
    }
    while(temp > 0) {
        ++len;
        temp /= 10;
    }
    if (negative) {
        stringSize = len + 2;
        str = new char[stringSize];
    }
    else {
        stringSize = len + 1;
        str = new char[stringSize];
    }
    int end = negative ? 1 : 0;
    str[stringSize-1]='\0';
    if (x==0)
        str[end]='0';
    while (len >= end) {
        str[len] = x % 10;
        x /= 10;
        len--;
    }
    if (negative)
        str[0]='-';
}
