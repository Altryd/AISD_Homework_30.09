#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include "List.h"

int main()
{
	List a;
	List b;
	List c;
	a.PushBack(1, "ky");
	b.PushBack(2, "privet");
	c.PushBack(3, "zdarova");
	c = a + b + c;
	c.Print();
	c += Pair({ 0.5,"kukusik" });
	c.Print();
	c[(size_t)0].Print();
	c["kukusik"].Print();
}