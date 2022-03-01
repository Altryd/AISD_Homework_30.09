#include <iostream>
#include <vector>
class Node
{
private:
	int val;
	Node* left;
	Node* right;
public:
	bool find_iterative(Node* node, int key)
	{
		while (node != nullptr)
		{
			if (key < node->val)
			{
				node = node->left;
			}
			else if (key > node->val)
			{
				node = node->right;
			}
			else
			{
				return 1;
			}
		}
		return 0;
	}

	static Node* create_balanced_tree(int* arr, int size)
	{
		if (size <= 0) return nullptr;
		Node* root = new Node();
		root->val = arr[size / 2];
		root->left = create_balanced_tree(arr, size / 2);
		root->right = create_balanced_tree(arr + (size / 2)+1, size - (size / 2) - 1);
		return root;
	}

	static void PrintTree(Node* root, int offset = 2)
	{
		std::string offset_string(offset, ' ');
		if (!root)
		{
			std::cout << offset_string << "NULL" << std::endl;
			return;
		}
		std::cout << offset_string << root->val << std::endl;
		std::cout << offset_string << "LEFT: ";
		PrintTree(root->left, offset + 2);
		std::cout << offset_string << "RIGHT: ";
		PrintTree(root->right, offset + 2);
	}

};



int main()
{
	int arr[] = { 1, 3 ,5,8, 228 , 1337, 2022, 133228, 555454543 };
	Node* tree = Node::create_balanced_tree(arr, 9);
	tree->PrintTree(tree);
	return 0;
}