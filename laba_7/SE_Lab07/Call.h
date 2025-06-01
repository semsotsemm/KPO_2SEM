#pragma once
namespace Call {
	int _cdecl sum1(int a, int b, int c);
	int _stdcall mul(int& a, int b, int c);
	int _fastcall sum2(int a, int b, int c,int d);
}