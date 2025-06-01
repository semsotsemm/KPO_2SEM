#include<iostream>
#include"Call.h"

namespace Call {
	int _cdecl sum1(int a, int b, int c) {
		return a + b + c;
	}

	int _stdcall mul(int& a, int b, int c) {
		return a * b * c;
	}

	int _fastcall sum2(int a, int b, int c, int d) {
		return a + b + c + d;
	}
}