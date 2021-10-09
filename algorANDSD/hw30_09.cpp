#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <typeinfo>
#include <complex>
#include "List.h"

int main()
{
	//Pair<char*, int> para("Ky", 5);
	//para.Print();
	//Pair<char*, int>copy(para);
	//copy.Print();
	//Pair<char*, int> parochka("privet", 110);
	//para = parochka;
	//std::cout << "\n para:";
	//para.Print();
	//std::cout << "\n parochka:";
	//parochka.Print();
	//parochka = para = copy;
	//std::cout << "\n\n\n";
	//copy.Print();
	//std::cout << "\n";
	//para.Print();
	//std::cout << "\n";
	//parochka.Print();
	//Node<int, double> a({ 4,3.3 }, nullptr);
	//a.Print();
	//Node<char*, double> string({ "kykyk", 5.5 }, nullptr);
	//string.Print();
	//Node<double, char*> string2({ 33.3, "privet" }, nullptr);
	//string2.Print();
	//List<char*, double> a;
	//a.PushBack("kdfdy", 5.5);
	//a.Print();
	//Pair<char*, double> para("privet", 22.3);
	//a += para;
	//a.Print();
	//a = a + a + a;
	//a.Print();

	//List<double, char*> b;
	//b.PushBack(33.4, "yy");
	//b.PushFront(33.3, "kkyk");
	//b.Print();
	//b = b + b + b + b + b;
	//b.Print();
	//b[(size_t)0] = { 22.8, "zamena" };
	//b.Print();


	List<char*, char*> test;
	test.PushBack("ky", "privet");
	test.PushFront("zdarova", "chelik");
	test.Print();
	test = test + test + test + test;
	test.Print();
	test[(size_t)0] = { "eto", "zamena" };
	test.Print();
	//List<double, int> list;
	//list.PushBack(5.5, 3);
	//list.PushFront(11.1, 55);
	//list.Print();
	//List<double, int> list_copy(list);
	//list.Clear();
	//list.PopBack();
	//list.PopFront();
	//list_copy.Print();
	//list_copy.PopBack();
	//list_copy.PopFront();
	//list_copy.Print();
	//list.PushBack(5.5, 3);
	//list.PushFront(11.1, 55);
	//list.PushBack(3.3, 88);
	//list.PushFront(99.9, 99);
	//list.Print();
	//List<double, int> list_assigment;
	//list_assigment = list;
	//list.Clear();
	//list.Print();
	//list_assigment.Print();
	//Pair<double,int> para_assig = list_assigment[3.3];
	//para_assig.Print();
	//std::cout << std::endl;
	//list += para_assig;
	//list.Print();
	//list_assigment += list;
	//list_assigment.Print();
	//List<double, int> sum;
	//sum = list_assigment + list_assigment + list;
	//sum.Print();
}