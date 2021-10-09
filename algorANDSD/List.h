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
	Pair(const Pair<TKey,TVal>& rhs)
	{
		this->value = rhs.value;
		this->key = rhs.key;
	}
	void Print() const
	{
		std::cout << "key: "<<key << " value - " << value;
	}
	Pair<TKey, TVal>& operator=(const Pair<TKey, TVal>& rhs) = default;
	bool operator==(const Pair<TKey, TVal>& rhs) const
	{
		return (key == rhs.key);// && (value == rhs.value);
	}
	template <typename T> friend class List;
	template <typename T> friend struct NodeTest;
	friend std::ostream& operator<< (std::ostream& out, const Pair<TKey,TVal>& pair)
	{
		std::cout << "'" << pair.key << "': '" << pair.value << "' ";
		return out;
	}
};


template<typename TVal>
struct Pair<char*, TVal>
{
private:
	char* key;
	TVal value;
public:
	Pair(const char* key = nullptr, const TVal value = 0)
	{
		this->key = _strdup(key);
		this->value = value;
	}
	~Pair()
	{
		if (key != nullptr) free(key);
		key = nullptr;
	}
	Pair(const Pair<char*, TVal>& rhs)
	{
		this->key = _strdup(rhs.key);
		this->value = rhs.value;
	}
	void Print() const
	{
		std::cout << "key: " << key << " value - " << value;
	}
	template <typename T> friend class List;
	template <typename T> friend struct NodeTest;
	Pair<char*, TVal>& operator=(const Pair<char*, TVal>& rhs)
	{
		if (this == &(rhs)) return *this;
		if (rhs.key == nullptr)
		{
			if (key != nullptr) free(key);
			key = nullptr;
		}
		else if (key!=nullptr && strcmp(key,rhs.key) != 0)
		{
			char* temp_key = _strdup(rhs.key);
			if (key != nullptr) free(key);
			key = temp_key;
		}
		else if (key == nullptr)
		{
			key = _strdup(rhs.key);
		}
		if (value != rhs.value)
		{
			value = rhs.value;
		}
		return *this;
	}
	friend std::ostream& operator<< (std::ostream& out, const Pair<char*,TVal>& pair)
	{
		std::cout << "'" << pair.key << "': '" << pair.value << "' ";
		return out;
	}
	bool operator==(const Pair<char*, TVal>& rhs) const
	{
		return (!strcmp(key, rhs.key));// && (value == rhs.value);
	}
};


template<typename TKey>
struct Pair<TKey, char*>
{
private:
	TKey key;
	char* value;
public:
	Pair(const TKey key = 0, const char* value = nullptr)
	{
		this->key = key;
		this->value = _strdup(value);
	}
	~Pair()
	{
		if (value != nullptr) free(value);
		value = nullptr;
	}
	Pair(const Pair<TKey, char*>& rhs)
	{
		this->key = rhs.key;
		this->value = _strdup(rhs.value);
	}
	void Print() const
	{
		std::cout << "key: " << key << " value - " << value;
	}
	template <typename T> friend class List;
	template <typename T> friend struct NodeTest;
	Pair<TKey, char*>& operator=(const Pair<TKey, char*>& rhs)
	{
		if (this == &(rhs)) return *this;
		if (rhs.value == nullptr)
		{
			if (value != nullptr) free(value);
			value = nullptr;
		}
		else if (value != nullptr && strcmp(value, rhs.value) != 0)
		{
			char* temp_value = _strdup(rhs.value);
			if (value != nullptr) free(value);
			value = temp_value;
		}
		else if (value == nullptr)
		{
			value = _strdup(rhs.value);
		}
		if (key != rhs.key)
		{
			key = rhs.key;
		}
		return *this;
	}
	friend std::ostream& operator<< (std::ostream& out, const Pair<TKey,char*>& pair)
	{
		std::cout << "'" << pair.key << "': '" << pair.value << "' ";
		return out;
	}
	bool operator==(const Pair<TKey, char*>& rhs) const
	{
		return (key == rhs.key);//&& (!strcmp(value, rhs.value));
	}
};


template<>
struct Pair<char*, char*>
{
private:
	char* key;
	char* value;
public:
	Pair(const char* key = nullptr, const char* value = nullptr)
	{
		this->key = _strdup(key);
		this->value = _strdup(value);
	}
	~Pair()
	{
		if (key != nullptr) free(key);
		key = nullptr;
		if (value != nullptr) free(value);
		value = nullptr;
	}
	Pair(const Pair<char*, char*>& rhs)
	{
		this->key = _strdup(rhs.key);
		this->value = _strdup(rhs.value);
	}
	void Print() const
	{
		std::cout << "key: " << key << " value - " << value;
	}
	template <typename T> friend class List;
	template <typename T> friend struct NodeTest;
	Pair<char*, char*>& operator=(const Pair<char*, char*>& rhs)
	{
		if (this == &(rhs)) return *this;
		if (rhs.value == nullptr)
		{
			if (value != nullptr) free(value);
			value = nullptr;
		}
		else if (value != nullptr && strcmp(value, rhs.value) != 0)
		{
			char* temp_value = _strdup(rhs.value);
			free(value);
			value = temp_value;
		}
		else if (value == nullptr)
		{
			value = _strdup(rhs.value);
		}

		if (rhs.key == nullptr)
		{
			if (key != nullptr) free(key);
			key = nullptr;
		}
		else if (key != nullptr && strcmp(key, rhs.key) != 0)
		{
			char* temp_key = _strdup(rhs.key);
			free(key);
			key = temp_key;
		}
		else if (key == nullptr)
		{
			key = _strdup(rhs.key);
		}
		return *this;
	}
	friend std::ostream& operator<< (std::ostream& out, const Pair<char*,char*>& pair)
	{
		std::cout << "'" << pair.key << "': '" << pair.value << "' ";
		return out;
	}
	bool operator==(const Pair<char*, char*>& rhs) const
	{
		return (!strcmp(key, rhs.key));// && (!strcmp(value, rhs.value));
	}
};


template <typename T>
struct NodeTest
{
private:
	T value;
	NodeTest* next;
public:
	template <typename T> friend class List;

	NodeTest(const T& value, NodeTest* next)
	{
		this->value = value;
		this->next = next;
	}
	NodeTest(const NodeTest& node) = delete;
	NodeTest& operator=(const NodeTest& node) = delete;
	void Print() const
	{
		std::cout << "[" << this << "] ";
	}
	friend std::ostream& operator<< (std::ostream& out, const NodeTest<T>& node_test)
	{
		std::cout << "[" << node_test.value << "] ";
		return out;
	}
};


template <typename T>
class List
{
private:
	NodeTest<T>* head;
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
	List(const List<T>& list) //OK
	{
		head = nullptr;
		size = 0;
		NodeTest<T>* moving_head = list.head;
		if (moving_head == nullptr) head = nullptr;
		while (moving_head != nullptr)
		{
			this->PushBack(moving_head->value);
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
		NodeTest<T>* next = head;
		for (size_t i = 0; i < size; i++)
		{
			std::cout << "[" << next->value<< "] -> ";
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
	void PushFront(const T value)
	{
		head = new NodeTest<T>(value, head);
		size++;
	}
	void PushBack(const T value)
	{
		if (!size) head = new NodeTest<T>(value, nullptr);
		else
		{
			NodeTest<T>* next = head;
			while (next->next != nullptr)
			{
				next = next->next;
			}
			next->next = new NodeTest<T>(value, nullptr);
		}
		size++;
	}
	void PopBack()
	{
		if (!size)
		{
			return;
		}
		NodeTest<T>* temp = head;
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
		NodeTest<T>* temp = head;
		head = head->next;
		delete temp;
		size--;
	}
	List<T>& operator=(const List<T>& list)
	{
		if (this == &(list)) return *this;
		this->Clear();
		for (size_t i = 0; i < list.Size(); i++)
		{
			this->PushBack(list[i]);
		}
		return *this;
	}
	T& operator[](const size_t index)
	{
		size_t count = 0;
		NodeTest<T>* counting_head = head;
		if (index >= size) throw std::exception("Bad index");
		while (count != index)
		{
			count++;
			counting_head = counting_head->next;
		}
		return counting_head->value;
	}
	T operator[](const size_t index) const
	{
		size_t count = 0;
		NodeTest<T>* counting_head = head;
		if (index >= size) throw std::exception("Bad index");
		while (count != index)
		{
			count++;
			counting_head = counting_head->next;
		}
		return counting_head->value;
	}
	T operator[](const T key) const
	{
		NodeTest<T>* seeking_head = head;
		while (seeking_head)
		{
			if (seeking_head->value == key) return seeking_head->pair;
			else
			{
				seeking_head = seeking_head->next;
			}
		}
		throw std::exception("An element with the string does not exist");
	}
	T& operator[](const T& key)
	{
		NodeTest<T>* seeking_head = head;
		while (seeking_head)
		{
			if (seeking_head->value == key) return seeking_head->value;
			else
			{
				seeking_head = seeking_head->next;
			}
		}
		throw std::exception("An element with the string does not exist");
	}
	List<T>& operator+=(const T& value)
	{
		this->PushBack(value);
		return *this;
	}
	List<T>& operator+=(const List<T>& rhs)
	{
		size_t new_size = rhs.Size();
		for (size_t i = 0; i < new_size; i++)
		{
			PushBack(rhs[i]);
		}
		return *this;
	}
	List<T> operator+(const List<T>& rhs) const
	{
		List a(*this);
		a += rhs;
		return a;
	}
};