#include "dsstring.h"

String::String(){ //default constr
    length = 0;
    data = new char [0];
}

String::String(const char c){
    length = 1;
    data = new char(c);
}

String::String( char * c){
    if(c){
        unsigned count = 0;
        while(c[count] != '\0')
            count++;
        length = count;
        data = new char [count];
        for(unsigned i{0}; i < count; i++)
            data [i] = c[i];
    }else clear();
}

String::String(const String & s){ // copy constr
    length = s.length;
    data = new char [length];
    for (int i{0}; i < length; i++)
        data[i] = s[i];
}

String::String(const String && s){  // move copy constr
    clear();
    length = s.length;
    data = s.data;
}

void String::clear(){
    if(data){
        length = 0;
        data = new char [0];
    }
}

const char * String::allocate(int new_length){
    if(data)
        clear();
    length = new_length;
    data = new char [length + 1]();
    return data;
}

String::operator const char * () const{
    return c_str();
}

String & String::operator = (const char * c){
    if(c){
        unsigned count = 0;
        while(c[count] != '\0')
            count++;
        length = count;
        data = new char [count];
        for(unsigned i{0}; i < count; i++)
            data [i] = c[i];
    } return * this;
}

String & String::operator = (const String & s){
    if (this == &s)
        return * this;
    delete [] data;
    length = s.length;
    data = new char [length];
    for(int i{0}; i < length; i++)
        data[i] = s[i];
    return * this;
}

String String::operator += (const String & s){
    int new_length = length + s.length;
    char * new_data = new char[new_length];
    for (int i{0}; i < length; i++)
        new_data[i] = data[i];
    for (int j{0}; j < s.length; j++)
        new_data[length + j] = s[j];
    delete [] data;
    length = new_length;
    data = new_data;
    return * this;

}

String String::operator + (const String & s){
    String temp = *this;
    temp += s;
    return temp;
}

bool String::operator == (/*const*/ char * c){
    return (*this == String(c));
}

bool String::operator == (const String & s){
    if (length != s.length)
        return false;
    int l_temp = s.length;
    int count = 0;
    while (count < l_temp && data[count] == s[count])
        count++;
    return (count == s.length);
}

bool String::operator > (const String & s){
    int l_temp = s.length;
    int count = 0;
    while (count < l_temp && data[count] == s[count])
        count++;
    if (count == s.length)
        return (length > s.length);
    if ( ('A' <= data[count] && data[count] <= 'Z') ||
         ('a' <= data[count] && data[count] <= 'z') &&
         ('A' <= s[count] && s[count] <= 'Z') ||
         ('a' <= s[count] && s[count] <= 'z')){
        char A = data[count] & ~32;
        char B = s[count] & ~32;
        if(A != B)
            return (A > B);
    }
        return (data[count] > s[count]);
}

bool String::operator< (const String& s){
    int l_temp = s.length;
    int count = 0;
    while (count < l_temp && data[count] == s[count])
        count++;
    if (count == s.length)
        return (length > s.length);
    if ( ('A' <= data[count] && data[count] <= 'Z') ||
         ('a' <= data[count] && data[count] <= 'z') &&
         ('A' <= s[count] && s[count] <= 'Z') ||
         ('a' <= s[count] && s[count] <= 'z')){
        char A = data[count] & ~32;
        char B = s[count] & ~32;
        if(A != B)
            return (A < B);
    }
        return (data[count] < s[count]);
}



char & String::operator [] (const int n){\
    if(n < 0){
        int _n = length + n;
        return data[_n];
    } return data[n];
}

String String::substring(int start, int finish){
    String s;
    if(start < 0)
        start = length + start + 1;
    if(finish < 0)
        finish = length + finish + 1;
    int new_length = abs(finish - start);
    char * new_str = new char[new_length];
    int count = 0;
    for (int i{start}; i < finish; i++){
//        if (count < new_length)
        new_str[count] = data[i];
        count++;
    }
    s = new_str;
    delete [] new_str;
    return s;
}

int String::index(char c) const{
    for (int i{0}; i < length; i++)
        if (data[i] == c)
            return i;
    return -1;
}

const char* String::c_str() const{
    char * s = this -> data;
    return s;
}

int String::size(){
    return (int)length;
}

std::ostream& operator << (std::ostream & out, const String & s){
    if(s.length > 0){
        for (int i{0}; i < s.length; i++)
            out << s[i];
    } else
        out << "";
    return out;
}

std::istream& operator >> (std::istream & in,  String & s){
    char c_string[256];
    in >> c_string;
    s = String(c_string);
    return in;
}

void String::getline(std::istream& in, String& s){
    String temp;
    char c;
    in.get(c);
    while (!in.eof() && c!= '\n'){
        temp += c;
        in.get(c);
    }
    s = temp;
}

void String::get(std::istream& in, String& s){
    String temp;
    char c;
    in.get(c);
    while (!in.eof() && c!= '\n' && c != ' ' && c != '\0'){
        temp += c;
        in.get(c);
    }
    s = temp;
}

String::~String(){
    delete [] data;
    length = 0;
}
