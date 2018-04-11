//This program uses a recursive function to compute the nth fibonnaci number
using namespace std;
 unsigned int Fibonacci(unsigned int n) {
	 if (n == 0) {
		 return 0;
	 }
	 else if(n == 1) {
		return 1;
	}
	else {
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

int main()
{
	unsigned int n, answer;

	cout << "Input a positive integer, n, and the program will calculate the nth Fibonacci number, F_n" << endl;
	cin >> n;
	answer = Fibonacci(n);
	cout << "The " << n << "th Fibonacci number is " << answer << endl;

	char dummy;

	cin >> dummy;
	return 0;
}
