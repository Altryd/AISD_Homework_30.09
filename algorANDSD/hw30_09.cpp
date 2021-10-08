#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <typeinfo>
#include <complex>
#include "List.h"

int main()
{
	List<double, int> list;
	list.PushBack(5.5, 3);
	list.PushFront(11.1, 55);
	list.Print();
	List<double, int> list_copy(list);
	list.Clear();
	list.PopBack();
	list.PopFront();
	list_copy.Print();
	list_copy.PopBack();
	list_copy.PopFront();
	list_copy.Print();
	list.PushBack(5.5, 3);
	list.PushFront(11.1, 55);
	list.PushBack(3.3, 88);
	list.PushFront(99.9, 99);
	list.Print();
	List<double, int> list_assigment;
	list_assigment = list;
	list.Clear();
	list.Print();
	list_assigment.Print();
	Pair<double,int> para_assig = list_assigment[3.3];
	para_assig.Print();
	std::cout << std::endl;
	list += para_assig;
	list.Print();
	list_assigment += list;
	list_assigment.Print();
	List<double, int> sum;
	sum = list_assigment + list_assigment + list;
	sum.Print();
}