#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>
#include <unordered_map>
#include <set>
#include <algorithm>
//template <typename T>
//class Iterator;
//
//template <typename T>
//class List
//{
//	template <typename T>
//	struct Node
//	{
//		Node* next;
//		Node* prev;
//		T data;
//	};
//	Node<T> head;
//public:
//	List()
//	{
//		head.next = &head;
//		head.prev = &head;
//	}
//	List(const List<T>& rhs)
//	{
//		head.next = &head;
//		head.prev = &head;
//		Node<T> temp = rhs.head;
//		while (temp.next != &(rhs.head))
//		{
//			PushBack(temp.next->data);
//			temp.next = temp.next->next;
//		}
//	}
//	~List()
//	{
//		while (head.next != &head)
//		{
//			Node<T>* temp = head.next;
//			head.next = head.next->next;
//			delete temp;
//		}
//		head.prev = &head;
//	}
//	void PopFront()
//	{
//		if (head.next == &head) throw "List is empty";
//		Node<T>* temp = head.next;
//		temp->next->prev = temp->prev;
//		temp->prev->next = temp->next;
//		delete temp;
//	}
//	void PushFront(const T& new_data)
//	{
//		Node<T>* new_elem = new Node<T>();
//		new_elem->data = new_data;
//		new_elem->next = head.next;
//		new_elem->prev = &head;
//		new_elem->next->prev = new_elem;
//		new_elem->prev->next = new_elem;
//	}
//	void PushBack(const T& new_data)
//	{
//		Node<T>* new_elem = new Node<T>();
//		new_elem->data = new_data;
//		new_elem->next = &head;
//		new_elem->prev = head.prev;
//		new_elem->next->prev = new_elem;
//		new_elem->prev->next = new_elem;
//	}
//	friend class Iterator<T>;
//
//	Iterator<T> Begin()
//	{
//		return Iterator<T>(this, head.next);
//	}
//	Iterator<T> End()
//	{
//		return Iterator<T>(this, &head);
//	}
//};
//
//template <typename T>
//class Iterator
//{
//private:
//	List<T>* container;
//	List<T>::Node<T>* current;
//public:
//	Iterator(List<T>* new_container, List<T>::Node<T>* new_current)
//	{
//		container = new_container;
//		current = new_current;
//	}
//	Iterator<T>& operator++()
//	{
//		current = current->next;
//		return *this;
//	}
//	Iterator<T>& operator--()
//	{
//		current = current->prev;
//		return *this;
//	}
//	Iterator<T> operator++(int)
//	{
//		auto tmp = *this;
//		++(*this);
//		return tmp;
//	}
//	Iterator<T> operator--(int)
//	{
//		auto tmp = *this;
//		--(*this);
//		return tmp;
//	}
//	bool operator==(const Iterator<T>& rhs) const
//	{
//		return (current == rhs.current);
//	}
//	bool operator!= (const Iterator<T>& rhs) const
//	{
//		return !(current == rhs.current);
//	}
//	T& operator*()
//	{
//		return current->data;
//	}
//	T operator*() const
//	{
//		return current->data;
//	}
//};

auto FillVector(size_t count=10)
{
	std::vector<int> vec;
	for (size_t i = 0; i < count; i++)
	{
		vec.push_back(rand() % 101);
	}
	return vec;
}
auto FillVector(int)
{
	std::vector<int> vec;
	for (size_t i = 0; i < 10; i++)
	{
		vec.push_back(rand() % 21 - 10);
	}
	return vec;
}
auto FillList0to100()
{
	std::list<int> list;
	for (size_t i = 0; i < 10; i++)
	{
		list.push_back(rand() % 101);
	}
	return list;
}


auto FilterVectorEvenNumbers(std::vector<int> vec)
{
	std::vector<int> result;
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		if (*it % 2 == 0)
		{
			result.push_back(*it);
		}
	}
	return result;
}

auto FilterList(std::vector<int> vec)
{
	std::list<int> result;
	for (auto it = vec.begin(); it != vec.end(); ++it)
	{
		if (*it >= 0)
		{
			result.push_back(*it);
		}
		else 
		{
			result.push_front(*it);
		}
	}
	return result;
}


template<typename T>
void PrintVector(std::vector<T> vec)
{
	if (vec.size() == 0)
	{
		std::cout << "[]" << std::endl;
		return;
	}
	std::cout << "[";
	auto end_ = vec.end();
	auto end_minus_one = std::prev(end_);
	for (auto it = vec.begin(); it!= end_minus_one;++it)
	{
		std::cout << *it << " , ";
	}
	auto prev = std::prev(vec.end());
	std::cout << *prev;
	std::cout << "]" << std::endl;
}

template<typename T>
void PrintList(std::list<T> list)
{
	if (list.size() == 0)
	{
		std::cout << "[]" << std::endl;
		return;
	}
	std::cout << "[";
	auto end_ = list.end();
	auto end_minus_one = std::prev(end_);
	for (auto it = list.begin(); it != end_minus_one; ++it)
	{
		std::cout << *it << " , ";
	}
	auto prev = std::prev(list.end());
	std::cout << *prev;
	std::cout << "]" << std::endl;
}

template<typename T>
void PrintVectorReverse(std::vector<T> vec)
{
	if (vec.size() == 0)
	{
		std::cout << "[]" << std::endl;
		return;
	}
	std::cout << "[";
	auto end_ = vec.rend();
	auto end_minus_one = std::prev(end_);
	for (auto it = vec.rbegin(); it != end_minus_one; ++it)
	{
		std::cout << *it << " , ";
	}
	std::cout << *vec.begin();
	std::cout << "]" << std::endl;
}


int main()
{
	//------ FIRST TASK -----------
	//std::cout << "FIRST TASK" <<  std::endl;
	//List<int> list;
	//list.PushFront(1);
	//list.PushFront(2);
	//list.PushFront(3);
	//list.PushFront(4);
	//list.PushFront(5);
	//for (auto it = list.Begin(); it != list.End(); it++)
	//{
	//	std::cout << *it << " ";
	//}
	//std::cout << std::endl;
	//List<int> copy(list);
	//for (auto it = copy.Begin(); it != copy.End(); it++)
	//{
	//	std::cout << *it << " ";
	//}
	//std::cout << std::endl << std::endl;

	//------ SECOND AND THIRD TASK -----------
	std::cout << "SECOND AND THIRD TASK" << std::endl;
	std::vector<int> vector = FillVector();
	PrintVector(vector);
	PrintVectorReverse(vector);
	
	std::vector<int> even_vector = FilterVectorEvenNumbers(vector);
	PrintVector(even_vector);
	PrintVectorReverse(even_vector);
	std::cout << std::endl << std::endl;
	//------ FOURTH TASK -----------
	std::cout << "FOURTH TASK" << std::endl;
	std::vector<int> fourth_vector = FillVector(3);
	PrintVector(fourth_vector);
	PrintVectorReverse(fourth_vector);

	std::list<int> some_list = FilterList(fourth_vector);
	for (auto it = some_list.begin(); it != some_list.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	//--- FIFTH TASK -----
	std::cout << "FIFTH TASK" << std::endl;
	std::list<int> list = FillList0to100();
	PrintList(list);
	for (auto it = list.begin(); it != list.end();)
	{
		if (*it % 2 == 0)
		{
			it = list.erase(it);
		}
		else
		{
			++it;
		}
	}
	PrintList(list);
	std::cout << std::endl;
	//--- SIXTH TASK -----
	std::cout << "SIXTH TASK" << std::endl;
	std::vector<int> six_vector = FillVector((size_t)100);
	std::unordered_map<int, size_t> map_sixth_task;
	for (auto it = six_vector.begin(); it != six_vector.end(); ++it)
	{
		if (map_sixth_task.find(*it) != map_sixth_task.end())
		{
			map_sixth_task[*it] += 1;
		}
		else
		{
			map_sixth_task[*it] = 1;
		}
	}
	PrintVector(six_vector);
	for (auto it : map_sixth_task)
	{
		std::cout << it.first << " - " << it.second << std::endl;
	}
	std::cout << std::endl;
	//--- SEVENTH TASK -----
	std::cout << "SEVENTH TASK" << std::endl;
	std::set<int> first_set;
	std::set<int> second_set;
	for (size_t i = 0; i < 5; ++i)
	{
		first_set.insert(rand() % 11);
		second_set.insert(rand() % 11);
	}
	std::set<int> union_of_sets;
	for (auto it : first_set)
	{
		union_of_sets.insert(it);
	}
	for (auto it : second_set)
	{
		union_of_sets.insert(it);
	}
	std::set<int> intersection_of_sets;
	for (auto it : first_set)
	{
		if (second_set.find(it) != second_set.end()) 
		{
			intersection_of_sets.insert(it);
		}
	}



	std::cout << "First set" << std::endl;
	for (auto it : first_set)
	{
		std::cout << it << std::endl;
	}
	std::cout << "Second set" << std::endl;
	for (auto it : second_set)
	{
		std::cout << it << std::endl;
	}
	std::cout << "UNION set" << std::endl;
	for (auto it : union_of_sets)
	{
		std::cout << it << std::endl;
	}
	std::cout << "INTERSECTION set" << std::endl;
	for (auto it : intersection_of_sets)
	{
		std::cout << it << std::endl;
	}
	std::cout << std::endl;
	//--- EIGHTH TASK -----
	std::cout << "EIGHTH TASK" << std::endl;
	std::list<int> eight_list_task;
	std::cout << "List" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		eight_list_task.push_back(rand() % 21);
	}
	PrintList(eight_list_task);
	std::vector<int> eight_vector_task;
	for (auto it : eight_list_task)
	{
		if (std::find(eight_vector_task.begin(), eight_vector_task.end(), it) == eight_vector_task.end())
		{
			eight_vector_task.push_back(it);
		}
	}
	std::cout << "Vector" << std::endl;
	PrintVector(eight_vector_task);
}