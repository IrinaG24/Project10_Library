#ifndef STRING_H_
#define STRING_H_
#include<iostream>

class String {
private:
	char* arr;
	int lenght;

	void copyString(const String&);

	void addToString(const char);
public:
	String(const char* = "");
	String(const String&);
	String& operator=(const String&);
	~String();

	int Size()const;

	bool operator==(const String&) const;
	char& operator[](const int);
	const char& operator[](const int)const;
	String operator+(const String&);
	String& operator+=(const String&);

	bool operator>(const String&) const;
	bool operator<(const String&) const;

	friend std::istream& operator>>(std::istream&, String&);
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend void getline(std::istream&, String&);
	friend void getline(std::istream&, String&, char);
};

#endif
