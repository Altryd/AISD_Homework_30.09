#include <iostream>
#include <list>
#include <vector>
#include <string>

std::pair<std::list<int>::const_iterator, std::list<int>::const_iterator> LongestNonDecreasingSequence(const std::list<int>& list)
{
	std::list<int>::const_iterator start_of_result = list.begin();
	std::list<int>::const_iterator end_of_result = list.begin();
	size_t length = 0;
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		auto unmovable_it = it;
		auto moveable_it = unmovable_it;
		moveable_it++;
		size_t temp_length = 1;
		while (moveable_it != list.end() && *moveable_it >= *unmovable_it)
		{
			unmovable_it = moveable_it;
			moveable_it++;
			temp_length++;
		}
		if (temp_length > length)
		{
			length = temp_length;
			start_of_result = it;
			end_of_result = unmovable_it;
		}
	}
	return std::pair<std::list<int>::const_iterator, std::list<int>::const_iterator>(start_of_result, end_of_result);
}

std::string EraseRecurringWords(std::string text)
{
	std::string alphabet = "abcdefghijklmnopqrstuvwxyzабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
	std::string prev, cur;
	size_t index_prev_str = 0;
	for (size_t i = 0; i < text.size(); i++)
	{
		if (alphabet.find(tolower(text[i])) != alphabet.npos)
		{
			cur.push_back(text[i]);
			if (cur.size() == 1) index_prev_str = i;
		}
		else
		{
			if (prev == cur)
			{
				text.erase(index_prev_str, prev.size()+1);
				i -= prev.size()+1;
			}
			if (!cur.empty())
			{
				prev = cur;
				cur.clear();
			}
		}
	}
	if (prev == cur) text.erase(index_prev_str, prev.size());
	return text;
}
enum param
{
	AUTHOR,
	YEAR,
	PAGES,
	TITLE
};
class Book
{
private:
	std::string author;
	size_t year;
	size_t pages_number;
	std::string title;
public:
	friend static std::vector<Book> find_books(const std::vector<Book>& books, int needed_param, std::string compare);
	static std::vector<Book> random_notes();
	friend std::ostream& operator<<(std::ostream& out, const Book& book);
};


std::ostream& operator<<(std::ostream& out, const Book& book)
{
	out << "Author " << book.author << ' ';
	out << "Year " << book.year << ' ';
	out << "Pages " << book.pages_number << ' ';
	out << "Title " << book.title << ' ';
	out << std::endl;
	return out;
}
std::vector<Book> find_books(const std::vector<Book>& books, int needed_param, std::string compare)
{
	std::vector<Book> res;
	switch (needed_param)
	{
	case param::AUTHOR:
	{
		for (auto book : books)
		{
			if (book.author == compare)
			{
				res.push_back(book);
			}
		}
		return res;
		break;
	}
	case param::YEAR:
	{
		for (auto book : books)
		{
			if (std::to_string(book.year) == compare)
			{
				res.push_back(book);
			}
		}
		return res;
		break;
	}
	case param::PAGES:
	{
		for (auto book : books)
		{
			if (std::to_string(book.pages_number) == compare)
			{
				res.push_back(book);
			}
		}
		return res;
		break;
	}
	case param::TITLE:
	{
		for (auto book : books)
		{
			if (book.title == compare)
			{
				res.push_back(book);
			}
		}
		return res;
		break;
	}
	default:
	{
		return res;
		break;
	}
	}
}

std::vector<Book> Book::random_notes()
{
	std::vector<Book> res;
	for (size_t i = 0; i < 1000; i++)
	{
		std::vector<std::string> authors{ "Антон Чехов", "Николай Ахшарумов", "Юля Волкодав", "Сергей Удалин", "Алексей Будищев" };
		std::vector<std::string> titles{ "Тайна секретной двери", "Афганец", "Тайна спирального моста", "Бесы в Париже", "Творец Бога" };
		Book new_book;
		new_book.year = rand() % 2022;
		new_book.pages_number = rand() % 1000 + 10;
		new_book.author = authors[rand() % 5];
		new_book.title = titles[rand() % 5];
		res.push_back(new_book);
	}
	return res;
}
int main()
{
	setlocale(LC_ALL, "ru");
	std::list<int> list;
	for (size_t i = 0; i < 5; i++)
	{
		list.push_front(rand() % 20);
	}
	for (auto it : list)
	{
		std::cout << it << " , ";
	}
	std::cout << std::endl;
	std::pair<std::list<int>::const_iterator, std::list<int>::const_iterator> lis = LongestNonDecreasingSequence(list);
	for (auto it = lis.first; it != std::next(lis.second); ++it)
	{
		std::cout << *it << std::endl;
	}
	
	std::cout << std::endl << "FIFTH TASK" << std::endl;
	std::string text = "Привет друг как у тебя дела? Есть ли изменения, изменения, изменения, если да, то напиши!";
	for (auto char_ : text)
	{
		std::cout << char_;
	}
	std::cout << std::endl;
	text = EraseRecurringWords(text);
	for (auto char_ : text)
	{
		std::cout << char_;
	}
	std::cout << std::endl;
	std::cout << std::endl << "SIXTH TASK" << std::endl;
	std::vector<Book> books = Book::random_notes();
	for (auto book : books)
	{
		std::cout << book;
	}
	std::cout << std::endl << std::endl;
	std::cout << std::endl << "Ищем Николай Ахшарумов" << std::endl;
	std::vector<Book> needed_books = find_books(books, AUTHOR, "Николай Ахшарумов");
	for (auto book : needed_books)
	{
		std::cout << book;
	}
	std::cout << std::endl << "Ищем год 1428" << std::endl;
	std::vector<Book> needed_books_1995 = find_books(books, YEAR, "1428");
	for (auto book : needed_books_1995)
	{
		std::cout << book;
	}
	std::cout << std::endl << "Ищем c 912 страницами" << std::endl;
	std::vector<Book> needed_books_912 = find_books(books, PAGES, "912");
	for (auto book : needed_books_912)
	{
		std::cout << book;
	}
	std::cout << std::endl << "Ищем c названием Бесы в Париже" << std::endl;
	std::vector<Book> needed_books_title = find_books(books, TITLE, "Бесы в Париже");
	for (auto book : needed_books_title)
	{
		std::cout << book;
	}
}