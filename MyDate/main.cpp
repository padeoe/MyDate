#include <time.h>
#include <iostream>
#include "mydate.h"
#include<time.h>
using namespace std;
int main() {
	MyDate d1(2015,7,9);
	MyDate d2(1995,9,11);
	cout << d1.day_t() << endl;
	cout << d2.day_t()<< endl;
	cout << d2 - d1<<endl;
}