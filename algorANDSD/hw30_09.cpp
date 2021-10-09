#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <typeinfo>
#include <complex>
#include <list>
#include "List.h"

int main()
{
	List<Pair<char*, int>> list;
	Pair<char*, int> add("ky", 5);
	Pair<char*, int> add2("it's fake!!", 3228);
	list += add;
	list.Print();
	list = list + list + list;
	list.Print();

	list.PopFront();
	list.Print();
	list += add2;
	Pair<char*, int> ky = list["it's fake!!"];
	std::cout << ky << std::endl;

	//Pair<char*, int> para("Ky", 5);
	//std::cout << para;
	//Pair<char*, int>copy(para);
	//std::cout <<  copy;
	//Pair<char*, int> parochka("privet", 110);
	//para = parochka;
	//std::cout << "\n para:";
	//std::cout <<  para;
	//std::cout << "\n parochka:";
	//std::cout <<  parochka;
	//parochka = para = copy;
	//std::cout << "\n\n\n";
	//std::cout <<  copy;
	//std::cout << "\n";
	//std::cout <<  para;
	//std::cout << "\n";
	//std::cout <<  parochka;
	//NodeTest<Pair<int, double>> a({ 4,3.3 }, nullptr);
	//std::cout <<  a;
	//NodeTest<Pair<char*, double>> string({ "kykyk", 5.5 }, nullptr);
	//std::cout <<  string;
	//NodeTest<Pair<double, char*>> string2({ 33.3, "privet" }, nullptr);
	//std::cout << string2;
	//List< Pair<char*, double> > a2;
	//a2.PushBack({ "kdfdy", 5.5 });
	//std::cout << std::endl;
	//a2.Print();
	//a.Print();
	//Pair<char*, double> para("privet", 22.3);
	//a += para;
	//a.Print();
	//a = a + a + a;
	//a.Print();

	//List<Pair<double, char*>> b;
	//b.PushBack({ 33.4, "yy" });
	//b.PushFront({ 33.3, "kkyk" });
	//b.Print();
	//b = b + b + b + b + b;
	//b.Print();
	//b[(size_t)0] = { 22.8, "zamena" };
	//b.Print();


	//List<Pair<char*,char*>> test;
	//test.PushBack({ "ky", "privet" });
	//test.PushFront({ "zdarova", "chelik" });
	//test.Print();
	//test = test + test + test + test;
	//test.Print();
	//test[(size_t)0] = { "eto", "zamena" };
	//test.Print();
	//std::list<int> a;





	//List<Pair<double, int>> list;
	//list.PushBack({ 5.5, 3 });
	//list.PushFront({ 11.1, 55 });
	//list.Print();
	//List<Pair<double, int>> list_copy(list);
	//list.Clear();
	//list.PopBack();
	//list.PopFront();
	//list_copy.Print();
	//list_copy.PopBack();
	//list_copy.PopFront();
	//list_copy.Print();
	//list.PushBack({ 5.5, 3 });
	//list.PushFront({11.1, 55});
	//list.PushBack({ 3.3, 88 });
	//list.PushFront({ 99.9, 99 });
	//list.Print();
	//List<Pair<double, int>> list_assigment;
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
	//List<Pair<double, int>> sum;
	//sum = list_assigment + list_assigment + list;
	//sum.Print();
}