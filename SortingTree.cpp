#include <iostream>
#include <fstream>
#include <vector>
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
int Parent(int i) {
	return (i - 1) / 2;
}
int child(int i) {
	return i * 2 + 1;
}
void makevector(std::vector<int>& A, std::ifstream& stream) {
	for (int temp; stream >> temp; A.push_back(temp));
}
void makeTree(std::vector<int>& A) {
	int n = A.size();
	for (int i = 1; i < n; i++) {
		for (int j = i; A[j] > A[Parent(j)]; j = Parent(j)) {
			swap(A[j], A[Parent(j)]);
		}
	}
}
void popTree(std::vector<int>& A) {
	for (int n = A.size() - 1; n > 0; n--) {
		swap(A[n], A[0]);
		for (int j = 0; ; ) {
			int left = child(j);
			int right = left + 1;
			if (left >= n) {
				//no children
				break;
			}
			else if (right == n) {
				//only one child
				if (A[left] > A[j])
					swap(A[left], A[j]);
				break;
			}
			else {
				//both children
				int biggestChild = left;
				if (A[right] > A[left])
					biggestChild = right;
				if (A[biggestChild] > A[j])
					swap(A[biggestChild], A[j]);
				j = biggestChild;
			}
		}
	}
}

void sort(std::vector<int>& A) {
	makeTree(A);
	popTree(A);
}

int main() {
	using namespace std;
	ifstream in_stream;
	ofstream out_stream;

	in_stream.open("input.txt");
	out_stream.open("output.txt");
	vector<int> A;
	makevector(A, in_stream);
	sort(A);

	//print out A;
	for (int i = 0; i < A.size(); i++) {
		out_stream << A[i] << '\n';
	}
}
