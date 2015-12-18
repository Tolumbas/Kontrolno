#include <iostream>
#include <windows.h>
#include "Song.h"
using namespace std;
void main() {
	Song s1;
	Song s2;
	Song s3("Ne sum siguren", 1,90);
	Song s4;

	
	cout << s3.getName() << " " << s3.getMinutes() << " " << s3.getSeconds() << endl;
	//expect Ne sum siguren 1 30

	cout << (s1 != s2) << endl; 
	// expect 0

	s2.setName("Uber guiar solo");
	s2.setMinutes(2);
	s2.setSeconds(-1);
	
	cout << s2.getName() << " " << s2.getMinutes()  << " "<< s2.getSeconds() << endl;
	// expect: Uber guitar solo 2 0

	cout << (s1 > s2) << endl; 
	// expect 0
	
	s3 = "Smells like teen spirit 04:23";
	cout << s3.getName() << " " << s3.getMinutes() << " " << s3.getSeconds() << endl;
	system("pause");
}