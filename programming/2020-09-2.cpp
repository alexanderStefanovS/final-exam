
#include <iostream>
#include <queue>
#include <stack>

struct Node 
{ 
	
	char text; 
	Node* left, * right;

	Node(char text, Node* left, Node* right) 
	{
		this->text = text;
		this->left = left;
		this->right = right;
	}

};

int countNodes(Node* node) 
{
	if (node == nullptr) 
	{
		return 0;
	}

	return countNodes(node->left) + countNodes(node->right) + 1;
}

void bfs(Node* node) 
{
	std::queue<Node*> queue;
	std::stack<char> intervals;

	int count = countNodes(node);

	queue.push(node);

	while (!queue.empty() && count) 
	{
		int size = queue.size();
		while (size) {

			Node* curr = queue.front();

			if (curr) {
				queue.push(curr->left);
				queue.push(curr->right);

				std::cout << curr->text;

				--count;

				if (!count)
				{
					break;
				}
			}
			else
			{
				std::cout << '_';
			}

			queue.pop();

			size--;
		}

		std::cout << "\n";
	}
}

//int main() 
//{
//
//	Node* nodes[25] = {
//		new Node('!', nullptr, nullptr), // 0
//		new Node('s', nullptr, nullptr), // 1
//		new Node('m', nullptr, nullptr), // 2
//		new Node('e', nullptr, nullptr), // 3
//		new Node('l', nullptr, nullptr), // 4
//		new Node('b', nullptr, nullptr), // 5
//		new Node('o', nullptr, nullptr), // 6
//		new Node('r', nullptr, nullptr), // 7
//		new Node('p', nullptr, nullptr), // 8
//		new Node('g', nullptr, nodes[0]), // 9
//		new Node('n', nodes[1], nullptr), // 10
//		new Node('i', nullptr, nullptr), // 11
//		new Node('v', nullptr, nullptr), // 12
//		new Node('l', nodes[3], nodes[2]), // 13
//		new Node('o', nodes[5], nodes[4]), // 14
//		new Node('s', nodes[7], nodes[6]), // 15
//		new Node('t', nullptr, nodes[8]), // 16
//		new Node('a', nodes[10], nodes[9]), // 17
//		new Node('d', nodes[12], nodes[11]), // 18
//		new Node('o', nodes[14], nodes[13]), // 19
//		new Node('o', nullptr, nodes[15]), // 20
//		new Node('g', nodes[17], nodes[16]), // 21
//		new Node('m', nodes[19], nodes[18]), // 22
//		new Node('a', nodes[21], nodes[20]), // 23
//		new Node('I', nodes[23], nodes[22]), // 24
//	};
//
//	Node* root = nodes[24];
//
//	bfs(root);
//
//	return 0;
//}

