#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)

//reverse the bits
unsigned int rev(unsigned int x)
{
	x = (x & 0x55555555) << 1 | (x >> 1 & 0x55555555);
	x = (x & 0x33333333) << 2 | (x >> 2 & 0x33333333);
	x = (x & 0x0F0F0F0F) << 4 | (x >> 4 & 0x0F0F0F0F);
	x = (x & 0x00FF00FF) << 8 | (x >> 8 & 0x00FF00FF);
	x = (x & 0x0000FFFF) << 16 | (x >> 16 & 0x0000FFFF);
	return x;
}

//how many true?
int count(unsigned int x)
{
	x = (x & 0x55555555) + (x >> 1 & 0x55555555);
	x = (x & 0x33333333) + (x >> 2 & 0x33333333);
	x = (x & 0x0F0F0F0F) + (x >> 4 & 0x0F0F0F0F);
	x = (x & 0x00FF00FF) + (x >> 8 & 0x00FF00FF);
	x = (x & 0x0000FFFF) + (x >> 16 & 0x0000FFFF);
	return x;
}

//absolute value
int abs(int x)
{
	int y = x >> 31;
	return (x + y) ^ y;
}

//get max
int max(int x, int y)
{
	int m = (x - y) >> 31;
	return y & m | x & ~m;
}

//swap two value without extra space
void swap(int& x, int& y)
{
	x ^= y; y ^= x; x ^= y;
};

//average , will not overflow
int ave(int x, int y)
{
	return (x&y) + ((x^y) >> 1);
};

int main() {
	//freopen("output.txt", "w", stdout);
	//pack a set of bool variables into a single int variable 
	unsigned int a,b,k,k1,k2,x;

	a >> k & 1;//读取第k 位：
	~a >> k & 1;//	读取第k 位并取反：
	a &= ~(1 << k);//	将第k 位清0：
	a |= 1 << k;//	将第k 位置1：
	a ^= 1 << k;//	将第k 位取反：
	a ^= ((1 << (k2 - k1 + 1)) - 1) << k2;//	将第k1~k2 位反转：
	!(x&(x - 1)) && x;//	是否恰好只有一个true：
	x >> 1 & x;//	判断是否有两个相邻的true：
	x >> 1 & x >> 2 & x;//	是否有三个相邻的true：

	//x is equal a or b, now switch to another 
	x ^= a ^ b;
	return 0;
}





