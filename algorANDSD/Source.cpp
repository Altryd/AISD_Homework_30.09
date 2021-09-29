#include <stddef.h>
#include <string>
class Vector
{

private:
	double* data;
	size_t size;

public:
	Vector()
	{
		size = 2;
		data = new double[size];
		for (size_t i = 0; i < size; i++)
		{
			data[i] = 0;
		}
	}

	Vector(const size_t size, const double value = 0)
	{
		this->size = size;
		data = new double[size];
		for (size_t i = 0; i < size; i++)
		{
			data[i] = value;
		}
	}

	Vector(const Vector& rhs)
	{
		size = rhs.size;
		data = new double[size];
		for (size_t i = 0; i < size; i++)
		{
			data[i] = rhs.data[i];
		}
	}

	~Vector()
	{
		delete[] data;
		size = 0;
	}
	
	double& GetElem(const size_t index)
	{
		if (index >= size) throw "Bad index";
		return data[index];
	}
	double GetElem(const size_t index) const
	{
		if (index >= size) throw "Bad index";
		return data[index];
	}

	Vector& SumVectors(const Vector& rhs) const
	{
		if (size != rhs.size) throw "Bad dimensions";
		Vector res(rhs.size);
		for (size_t i = 0; i < size; i++)
		{
			res.data[i] = data[i] + rhs.data[i];
		}
		return res;
	}

	void AddVector(const Vector& rhs)
	{
		if (size != rhs.size) throw "Bad dimensions";
		for (size_t i = 0; i < size; i++)
		{
			data[i] += rhs.data[i];
		}
	}

	void MultiplyBy(const double value)
	{
		for (size_t i = 0; i < size; i++)
		{
			data[i] *= value;
		}
	}

	bool CompareVectors(const Vector& rhs) const
	{
		if (size != rhs.size) return false;
		for (size_t i = 0; i < size; i++)
		{
			if (data[i] != rhs.data[i])
			{
				return false;
			}
		}
		return true;
	}
};




class List
{
private:
	struct Node {
		int key;//Число (данные)
		char str[10];
		Node* next;//Следующий элемент
	};
	Node* head;
public:
	List()
	{
		head = NULL;
	}
	~List()
	{
		while (head)
		{
			Node* next = head->next;
			delete head;
			head = next;
		}
	}
	void PushFront(const char* string, const int key)
	{
		Node* new_elem = new Node();
		new_elem->key = key;
		size_t length = strlen(string);
		if (length >= 10) throw "Bad string";
		strcpy_s(new_elem->str, string);
		
		new_elem->next = head;
		head = new_elem;

	}

	void DeleteFront()
	{
		if (!head) {
			return;
		}

		Node* new_head = head->next;
		delete head;
		head = new_head;
	}
	size_t Size() const
	{
		size_t size = 0;
		Node* counting_head = head;
		while (counting_head)
		{
			size++;
			counting_head = counting_head->next;
			//head = next;
		}
		return size;
	}

	Node* GetElem(const size_t index)
	{
		size_t count = 0;
		Node* counting_head = head;
		if (index >= this->Size()) throw "Bad index";
		while (count != index)
		{
			count++;
			counting_head = counting_head->next;
		}
		return counting_head;
	}

	Node* GetElemWithStr(const char* str)
	{
		Node* seeking_head = head;
		while (seeking_head)
		{
			if (!strcmp(seeking_head->str, str)) return seeking_head;
			else
			{
				seeking_head = seeking_head->next;
			}
		}
		return NULL;
	}
};


struct Pair
{
private:
	int key;
	char str[10];
public:
	void Print() const
	{
		printf("%d - %s\n", key, str);
	}
	friend class List2;
};
class List2
{
private:
	struct Node2 {
		Pair pair;
		Node2* next;//Следующий элемент
	};
	Node2* head;
public:

	List2()
	{
		head = NULL;
	}
	~List2()
	{
		while (head)
		{
			Node2* next = head->next;
			delete head;
			head = next;
		}
	}
	void PushFront(const char* string, const int key)
	{
		Node2* new_elem = new Node2();
		new_elem->pair.key = key;
		size_t length = strlen(string);
		if (length >= 10) throw "Bad string";
		strcpy_s(new_elem->pair.str, string);

		new_elem->next = head;
		head = new_elem;

	}

	void DeleteFront()
	{
		if (!head) {
			return;
		}

		Node2* new_head = head->next;
		delete head;
		head = new_head;
	}
	size_t Size() const
	{
		size_t size = 0;
		Node2* counting_head = head;
		while (counting_head)
		{
			size++;
			counting_head = counting_head->next;
			//head = next;
		}
		return size;
	}

	Pair* GetElem(const size_t index)
	{
		size_t count = 0;
		Node2* counting_head = head;
		if (index >= this->Size()) throw "Bad index";
		while (count != index)
		{
			count++;
			counting_head = counting_head->next;
		}
		return &(counting_head->pair);
	}

	Pair* GetElemWithStr(const char* str)
	{
		Node2* seeking_head = head;
		while (seeking_head)
		{
			if (!strcmp(seeking_head->pair.str, str)) return &(seeking_head->pair);
			else
			{
				seeking_head = seeking_head->next;
			}
		}
		return NULL;
	}
};