#ifndef STRING
#define STRING

#include <iostream>
#include <cstring>
#include <fstream>

class String{
    char* data = nullptr;
    int length = 0;
    public:
        String();
        String(char c);
        String( char*);
        String(const String&);
        String(const String&&);

        void clear();
        const char * allocate(int);
        const char * copy(const char *);

        operator const char * () const;
        String& operator= (const char *);
        String& operator= (const String&);
        String operator+ (const String&);
        String operator+= (const String&);
        bool operator== (/*const*/ char*);
        bool operator== (const String&);
        bool operator> (const String&);
        bool operator< (const String&);
        char& operator[] (const int);
        void getline(std::istream&, String&);
        void get(std::istream&, String&);

        String substring(int, int);
        const char* c_str() const;
        int size();
        int index(char c) const;

        friend std::ostream& operator<< (std::ostream&, const String&);
        friend std::istream& operator>> (std::istream&, const String&);

        ~String();

};

#endif
