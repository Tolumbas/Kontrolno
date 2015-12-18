#pragma once
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class Song
{
private:
	string name;
	int minutes;
	int seconds;
	void parceString(string);
public:
	Song();
	Song(const char*,int,int);
	Song(const Song&);

	int getMinutes();
	int getSeconds();
	const char* getName();
	
	void setMinutes(int);
	void setSeconds(int);
	void setName(const char*);

	bool operator!=(Song&);
	bool operator>(Song&);
	Song& operator=(const char*);
	Song& operator=(Song&);

	friend istream& operator>> (istream& in, Song& my) {
		string input;
		getline(cin, input);
		my.parceString(input);
	}
};

