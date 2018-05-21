#include <iostream>
#include <fstream>




class Node {
private:
	int value;
	Node* smalchild; //left node
	Node* bigchild; //right node
public:
	Node(int val) {
		value = val;
		smalchild = nullptr;
		bigchild = nullptr;
	}
	void AddNode(int val) {
		Node* current = this;
		while (((val < current->value) && (current->smalchild)) || ((val >= current->value) && (current->bigchild))) {
			if (val < current->value) {
				current = current->smalchild;
			}
			else {
				current = current->bigchild;
			}
		}
		if (val < current->value) {
			current->AddLeft(val);
		}
		else {
			current->AddRight(val);
		}
	}
	void AddLeft(int val) {
		this->smalchild = new Node(val);
	}
	void AddRight(int val) {
		this->bigchild = new Node(val);
	}
	friend Node* MakeTree(std::ifstream& stream); 
	void friend SortNodes(Node* head, std::ofstream& stream);
};
void SortNodes(Node* head, std::ofstream& stream) {
	if (head->smalchild) {
		SortNodes(head->smalchild, stream);
	}
	stream << head->value << std::endl;
	if (head->bigchild) {
		SortNodes(head->bigchild, stream);
	}
}
Node* MakeTree(std::ifstream& stream) {
	int tmp;
	stream >> tmp;
	Node* current = new Node(tmp);
	Node* head = current;
	while (stream >> tmp) {
		current->AddNode(tmp);
	}
	return head;
}


int main() {
	using namespace std;
	ifstream in_stream;
	ofstream out_stream;
	in_stream.open("input.txt");
	out_stream.open("output.txt");
	Node* head = MakeTree(in_stream);
	SortNodes(head, out_stream);
	cout << "sorting complete, press any key to continue" << endl;
	char dummy;
	cin >> dummy;
	in_stream.close();
	out_stream.close();
	return 0;
}
