#include<iostream>
#include"Call.h"
using namespace Call;
using namespace std;

void main() {
	int a = 1, b = 2, c = 3, d = 4;
	int first = sum1(a, b, c);
	int second = mul(a, b, c);
	int third = sum2(a, b, c, d);
}