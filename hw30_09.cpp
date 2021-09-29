#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
struct Pair
{
private:
	double value;
	char* key;
public:	
	Pair(const double value = 0, const char* key = nullptr)
	{
		this->value = value;
		if (key != nullptr) this->key = _strdup(key);
		else this->key = nullptr;
	}
	~Pair()
	{
		if (key!=nullptr)
		{
			free(key);
			key = nullptr;
		}
		//printf(" PAIR DTOR\n");
	}
	Pair(const Pair& rhs)
	{
		if (&rhs != nullptr)
		{
			this->value = rhs.value;
			this->key = _strdup(rhs.key);
		}
		else
		{
			this->value = 0;
			this->key = nullptr;
		}
	}
	void Print() const
	{
		printf(" %lf - %s\n ", value, key);
	}
	friend class List;
	friend struct Node;
};
struct Node 
{
private:
	Pair pair;
	Node* next;//Следующий элемент
	friend class List;
	Node(const Pair& pair = { 0, nullptr }, Node* next = nullptr)
	{
		if (&pair != nullptr)
		{
			this->pair.value = pair.value;
			if (pair.key != nullptr) this->pair.key = _strdup(pair.key);
			this->next = next;
		}
		else
		{
			this->pair.value = 0;
			this->pair.key = nullptr;
			this->next = nullptr;
		}
	}
	Node(const Node& node)
	{
		this->pair.value = node.pair.value;
		if (pair.key != nullptr) this->pair.key = _strdup(node.pair.key);
		this->next = node.next;
	}
	Node& operator=(const Node& node)
	{
		if (this == &(node)) return *this;
		if (strcmp(this->pair.key,node.pair.key))
		{
			if (this->pair.key !=nullptr)
			{
				free(this->pair.key);
				this->pair.key = nullptr;
			}
			if (pair.key !=nullptr)
			{
				this->pair.key = _strdup(node.pair.key);
			}
		}
		if (this->pair.value != node.pair.value)
		{
			this->pair.value = node.pair.value;
		}
		if (this->next != node.next)
		{
			throw std::exception("What should I do?");
		}
	}
};
class List
{
private:
	Node* head;
	size_t size;
public:

	List() //OK
	{
		head = nullptr;
		size = 0;
	}
	~List() //OK
	{
		Clear();
	}
	List(const List& list) //OK
	{
		head = nullptr;
		size = 0;
		Node* moving_head = list.head;
		if (moving_head == nullptr) head = nullptr;
		while (moving_head !=nullptr)
		{
			this->PushBack(moving_head->pair.value, moving_head->pair.key);
			/*Node* new_elem = new Node();
			new_elem->pair.value = moving_head->pair.value;
			new_elem->pair.key = _strdup(moving_head->pair.key);
			new_elem->next = NULL;
			Node* next = head;
			if (!head) head = new_elem;
			else
			{
				while (next->next)
				{
					next = next->next;
				}
				next->next = new_elem;
			}*/
			moving_head = moving_head->next;
		}
	}
	void Print() const //OK
	{
		Node* next = head;
		for (size_t i=0;i<size;i++)
		{
			printf("[%s %lf] -> ", next->pair.key, next->pair.value);
			next = next->next;
		}
		printf("NULL\n");
	}
	void Clear() //OK
	{
		while (size)
		{
			PopFront();
		}
		size = 0;
	}
	size_t Size() const
	{
		return size;
	}

	void PushFront(const double value, const char* string)
	{
		head = new Node({ value,string }, head);
		size++;
	}
	void PushBack(const double value, const char* string)
	{
		if (head ==nullptr) head = new Node({ value,string }, nullptr);
		else
		{
			Node* next = head;
			while (next->next != nullptr)
			{
				next = next->next;
			}
			next->next = new Node({ value,string }, nullptr);
		}
		size++;
	}



	void PopBack()
	{
		if (!size)
		{
			return;
		}
		Node* temp = head;
		while (temp->next !=nullptr)
		{
			temp = temp->next;
		}
		delete temp;
		temp = nullptr;
		size--;
	}
	void PopFront()
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
	List& operator=(const List& list)
	{
		if (this == &(list)) return *this;
		this->Clear();
		for (size_t i = 0; i < list.Size(); i++)
		{
			this->PushBack(list[i].value, list[i].key);
		}
		return *this;
	}
	Pair& operator[](const size_t index)
	{
		size_t count = 0;
		Node* counting_head = head;
		if (index >= size) throw std::exception("Bad index");
		while (count != index)
		{
			count++;
			counting_head = counting_head->next;
		}
		return counting_head->pair;
	}
	Pair operator[](const size_t index) const
	{
		size_t count = 0;
		Node* counting_head = head;
		if (index >= size) throw std::exception("Bad index");
		while (count != index)
		{
			count++;
			counting_head = counting_head->next;
		}
		return counting_head->pair;
	}
	Pair operator[](const char* key)
	{
		Node* seeking_head = head;
		while (seeking_head)
		{
			if (!strcmp(seeking_head->pair.key, key)) return seeking_head->pair;
			else
			{
				seeking_head = seeking_head->next;
			}
		}
		throw std::exception("An element with the string does not exist");
	}
	List& operator+=(const Pair& pair)
	{
		this->PushBack(pair.value, pair.key);
		return *this;
	}
	List& operator+=(const List& rhs)
	{
		size_t new_size = rhs.Size();
		for (size_t i = 0; i < new_size; i++)
		{
			PushBack(rhs[i].value, rhs[i].key);
		}
		return *this;
	}
	List operator+(const List& rhs) const
	{
		List a(*this);
		a += rhs;
		return a;
		//List result(*this);
		//result += rhs;
		//return result;
		/*Node* moving_head = rhs.head;
		while (moving_head)
		{
			result.PushBack(moving_head->pair.value, moving_head->pair.key);
			moving_head = moving_head->next;
		}
		return result;*/
	}
};
int main()
{
	/*List a;
	a.PushBack(5, "ky");
	List b(a);
	b.PushBack(3, "kdfgsdy");
	//a.Print();
	//b.Print();
	List c;
	c = b;
	c.PushBack(11, "fdsf");
	//b.Print();
	//c.Print();
	Pair para = c[2];
	//para.Print();
	try
	{
		c[3];
	}
	catch (std::exception& ex)
	{
		//std::cout << ex.what() << std::endl;
	}
	Pair with_str = c["kdfgsdy"];
	with_str.Print();
	Pair item_to_add = { 5,"kolobok" };
	c += item_to_add;
	a += item_to_add;
	//c.Print();
	//a.Print();
	a.PopBack();
	//a.Print();
	//c.Print();
	c.Print();
	std::cout << "Vector c^^" << std::endl;
	c= c + b;
	std::cout << "\n\n" << "VECTORS B & C+B: "<< std::endl;
	b.Print();
	c.Print();*/
	List a;
	List b;
	List c;
	a.PushBack(1, "ky");
	b.PushBack(2, "privet");
	c.PushBack(3, "zdarova");
	c = a + b + c;
	c.Print();
}