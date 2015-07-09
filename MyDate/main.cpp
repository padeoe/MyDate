#include <time.h>
#include <iostream>
#include "mydate.h"
#include<time.h>
#include<Windows.h>
using namespace std;
int main() {
	DWORD start = GetTickCount();
	for (int i = 2015; i < 1000000;i++) {
		MyDate d1(i, 7, 9);
		MyDate d2(1995, 9, 11);
	//	d1 - d2;
		d1.sub(d2);
	}
	DWORD end = GetTickCount();
	printf("%d\n", end - start);
}