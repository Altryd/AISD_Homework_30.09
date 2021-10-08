#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <typeinfo>
#include <iostream>
template <typename TKey, typename TVal>
struct Pair
{
private:
	TKey key;
	TVal value;
public:
	Pair(const TKey key = 0, const TVal value = 0)
	{
		this->key = key;
		this->value = value;
	}
	~Pair() = default;
	Pair(const Pair& rhs)
	{
		this->value = rhs.value;
		this->key = rhs.key;
	}
	void Print() const
	{
		std::cout << "key: "<<key << " value - " << value;
	}
	template <typename TKey, typename TVal> friend class List;
	template <typename TKey, typename TVal> friend struct Node;
};

template <typename TKey, typename TVal>
struct Node
{
private:
	Pair<TKey, TVal> pair;
	Node* next;//��������� �������
public:
	template <typename TKey, typename TVal> friend class List;
	Node(const Pair<TKey, TVal>& pair, Node* next)
	{
		this->pair.key = pair.key;
		this->pair.value = pair.value;
		this->next = next;
	}
	Node(const TKey key, const TVal value, Node* next)
	{
		this->pair.key = key;
		this->pair.value = value;
		this->next = next;
	}
	Node(const Node& node) = delete;
	Node& operator=(const Node& node) = delete;
	/*{
		if (this == &(node)) return *this;
		if (strcmp(this->pair.key, node.pair.key))
		{
			if (this->pair.key != nullptr)
			{
				free(this->pair.key);
				this->pair.key = nullptr;
			}
			if (pair.key != nullptr)
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
	}*/
	void Print() const
	{
		std::cout << "[";
		pair.Print();
		std::cout << "]";
	}
};
template <typename TKey, typename TVal>
class List
{
private:
	Node<TKey, TVal>* head;
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
	List(const List<TKey, TVal>& list) //OK
	{
		head = nullptr;
		size = 0;
		Node<TKey, TVal>* moving_head = list.head;
		if (moving_head == nullptr) head = nullptr;
		while (moving_head != nullptr)
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
		Node<TKey, TVal>* next = head;
		for (size_t i = 0; i < size; i++)
		{
			std::cout << "[" << next->pair.key << " " << next->pair.value << "] -> ";
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

	void PushFront(const TKey key, const TVal value)
	{
		head = new Node<TKey, TVal>({ key, value }, head);
		size++;
	}
	void PushBack(const TKey key, const TVal value)
	{
		if (head == nullptr) head = new Node<TKey, TVal>({ key, value }, nullptr);
		else
		{
			Node<TKey, TVal>* next = head;
			while (next->next != nullptr)
			{
				next = next->next;
			}
			next->next = new Node<TKey, TVal>({ key, value }, nullptr);
		}
		size++;
	}



	void PopBack()
	{
		if (!size)
		{
			return;
		}
		Node<TKey, TVal>* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		delete temp;
		temp = nullptr;
		size--;
	}
	void PopFront()
	{
		if (!size) return;
		Node<TKey, TVal>* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
	List<TKey, TVal>& operator=(const List<TKey, TVal>& list)
	{
		if (this == &(list)) return *this;
		this->Clear();
		for (size_t i = 0; i < list.Size(); i++)
		{
			this->PushBack(list[i].value, list[i].key);
		}
		return *this;
	}
	Pair<TKey, TVal>& operator[](const size_t index)
	{
		size_t count = 0;
		Node<TKey, TVal>* counting_head = head;
		if (index >= size) throw std::exception("Bad index");
		while (count != index)
		{
			count++;
			counting_head = counting_head->next;
		}
		return counting_head->pair;
	}
	Pair<TKey, TVal> operator[](const size_t index) const
	{
		size_t count = 0;
		Node<TKey, TVal>* counting_head = head;
		if (index >= size) throw std::exception("Bad index");
		while (count != index)
		{
			count++;
			counting_head = counting_head->next;
		}
		return counting_head->pair;
	}
	Pair<TKey, TVal> operator[](const TKey key) const
	{
		Node<TKey, TVal>* seeking_head = head;
		while (seeking_head)
		{
			if (seeking_head->pair.key == key) return seeking_head->pair;
			else
			{
				seeking_head = seeking_head->next;
			}
		}
		throw std::exception("An element with the string does not exist");
	}
	Pair<TKey, TVal>& operator[](const TKey key)
	{
		Node<TKey, TVal>* seeking_head = head;
		while (seeking_head)
		{
			if (seeking_head->pair.key == key) return seeking_head->pair;
			else
			{
				seeking_head = seeking_head->next;
			}
		}
		throw std::exception("An element with the string does not exist");
	}
	List<TKey, TVal>& operator+=(const Pair<TKey, TVal>& pair)
	{
		this->PushBack(pair.value, pair.key);
		return *this;
	}
	List<TKey, TVal>& operator+=(const List<TKey, TVal>& rhs)
	{
		size_t new_size = rhs.Size();
		for (size_t i = 0; i < new_size; i++)
		{
			PushBack(rhs[i].value, rhs[i].key);
		}
		return *this;
	}
	List<TKey, TVal> operator+(const List<TKey, TVal>& rhs) const
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