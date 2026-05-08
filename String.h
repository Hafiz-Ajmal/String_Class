
#include <iostream>
#include <fstream>
using namespace std;

class String
{
private:
    char* data;
    int size;

    void copyString(const char* src);
    void copyString(const char* src, char* des);
    int getIntegerLength(const long long int num);

public:
    // constructors
    String();
    String(const char c);
    String(const char* src);
    String(const String& a);
    String(String&& s);
    

    // destructor
    ~String();

    
    String& operator=(const String& a);
    String& operator=(String&& s);
    String& operator=(const long long int num);
   String& operator=(const double num);
   bool operator ! () const;
   explicit operator long long int() const;
   explicit operator double() const;
   explicit operator bool() const;
    int getLength() const;
    int getLength(const char* src) const;
    int getSize() const;
    void display() const;
    int find(const String& subStr, const int start = 0) const;
    void insert(const int index, const String& subStr);
    void reSize(int capacity);
    int replace(const String& old, const String& newSubStr);
    int operator==(const String& s2) const;
    String operator+(const String& s2) const;
    void operator+=(const String& s2);
    String right(const int count);
    String left(const int count);
    void shrink();
    void reverse();
    void makeUpper();
    void makeLower();
    void trimLeft();
    void trimRight();
    void trim();
    void remove(const int index, const int count);
    void input();
    char& operator[](const int index);
    const  char& operator[](const int index) const;
    const char& at(const int index) const;
    char& at(const int index);
    String operator()(const String& delim);
    friend istream& operator>>(istream& op, String& s);
    friend ostream& operator<<(ostream& op, String& s);


    
   
};

int main()
{
  
    
        String names[3] = { "Alice", "Bob", "Charlie" };

        // Save
        fstream fs("names.txt", ios::out);
        for (int i = 0; i < 3; i++) {
            fs << names[i] << "\n";
        }
        fs.close();

        // Read
        fstream fsIn("names.txt", ios::in);
        String temp;
        while (fsIn >> temp) 
        {
            cout << "Loaded: " << temp << endl;
        }
    
    return 0;
}