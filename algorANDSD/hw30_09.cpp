#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <typeinfo>
#include <complex>
#include "List.h"

int main()
{
	//Pair<int, double> para(5,1.5);
	//Pair<int, int> para2(5, 111);
	//para.Print();
	//std::cout << std::endl;
	//para2.Print();
	//std::cout << std::endl;
	//Node<int, double> noda(para, NULL);
	//noda.Print();
	//std::cout << std::endl;
	//Node<double, double> noda2({2,3}, NULL);
	//noda2.Print();
	//std::cout << std::endl;
	//
	//List<int, double> a;
	//a.PushBack(100, 101.33);
	//a.PushBack(500, 502.21);
	//a.PushFront(4107, 9.9);
	//a.Print();

	//List<double, double> b;
	//b.PushBack(100.2, 101.33);
	//b.PushBack(500.55, 502.21);
	//b.PushFront(4107.99, 9.9);
	//b.Print();

	List<std::complex<int>, double> complex;
	complex.PushBack({ 100, 5 }, 101.33);
	complex.PushBack({ 500, 3 }, 502.21);
	complex.PushFront({55, 4107}, 9.9);
	complex.Print();
	complex.PopBack();
	complex.Print();
	complex.PopFront();
	complex.Print();
	complex.PopFront();
	complex.Print();
	complex.PopFront();
	complex.Print();
}