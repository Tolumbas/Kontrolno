#include "Song.h"



Song::Song()
{
	setMinutes(1);
	setName("Default song");
}

Song::Song(const char * name, int minutes, int seconds)
{
	setName(name);
	setMinutes(minutes);
	setSeconds(seconds);
}

Song::Song(const Song & in)
{
	name = in.name; // tva se kopira ok
	minutes = in.minutes;
	seconds = in.seconds;
}


void Song::parceString(string in)
{
	size_t pos = in.rfind(":");
	string mstr = in.substr(pos - 2, 2);
	int min = stoi(mstr);
	string s = in.substr(pos);//http://www.cplusplus.com/reference/string/string/substr/
	int sec = stoi(s);
	string name = in.substr(0, pos);
	setName(name.c_str());
	setMinutes(min);
	setSeconds(sec);
}

int Song::getMinutes()
{
	return minutes;
}

int Song::getSeconds()
{
	return seconds;
}

const char * Song::getName()
{
	return name.c_str();
}

void Song::setMinutes(int in)
{
	if (in < 0) { in = 0; }
	minutes = in;
}

void Song::setSeconds(int in)
{
	if (in < 0)in = 0;
	seconds = 0;
	seconds = in % 60;
}

void Song::setName(const char * in)
{
	name = in;
}

bool Song::operator!=(Song & in)
{
	return name.compare(in.name)!=0 || seconds != in.seconds || minutes != in.minutes;
}

bool Song::operator>(Song & in)
{
	if (minutes == in.minutes) 
		return seconds > in.seconds;
	return minutes > minutes;
}

Song& Song::operator=(const char * in)
{
	parceString(in);
	return *this;
}

Song& Song::operator=(Song & in)
{
	name = in.name; // tva se kopira ok
	minutes = in.minutes;
	seconds = in.seconds;
	return *this;
}
