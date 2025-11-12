#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void rec_print_desc(int n) {
	if (n > 0) {
		printf("%d\n", n);
		rec_print_desc(n - 1);
	}
}

void rec_print_asc(int n) {
	if (n > 0) {
		rec_print_asc(n - 1);
		printf("%d\n", n);
	}
}

int sum_of_natural_numbers(int n) {
	if (n <= 0) {
		return 0;
	}
	return n + sum_of_natural_numbers(n - 1);
}

int factorial(int n) {
	if (n <= 0) {
		return 1;
	}
	return n * factorial(n - 1);
}

long double power_rec(int num, int power) {
	if (power == 0) {
		return 1;
	}
	if (power == 1) {
		return num;
	}
	long double half =  power_rec(num, power/2);
	if (power % 2 == 0) {
		return half * half;
	}
	else {
		return num * half * half;
	}
}

long double taylor_series_of_e_terms(int x, int terms) {	
	if (terms == 1) {
		return 1;
	}
	return (power_rec(x, terms -1) / factorial(terms-1)) + taylor_series_of_e_terms(x, terms-1);
}

long double taylor_series_of_e_terms_horner(int x, int terms) {
	static int counter = 0;
	counter = counter + 1;
	if (counter == terms) {
		return 1;
	}
	return 1 + ((long double)x / (long double)counter) * taylor_series_of_e_terms_horner(x, terms);
}

int fib(int n) {
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

void fibonacci(int seq) {
	if (seq <= 0)
		return;

	cout << "Fibonacci sequence (" << seq << " terms): ";
	for (int i = 0; i < seq; i++) {
		cout << fib(i);
		if (i < seq - 1)
			cout << ", ";
	}
	cout << endl;
}
const int MAXN = 40;
long long memo[MAXN + 1][MAXN + 1];

long long combination_rec(int n, int r) {
	if (r > n) return 0;
	if (r == 0 || r == n) return 1;
	if (memo[n][r] != -1) return memo[n][r];
	return memo[n][r] = combination_rec(n - 1, r) + combination_rec(n - 1, r - 1);
}


int main() {
	for (int i = 0; i <= MAXN; i++)
		for (int j = 0; j <= MAXN; j++)
			memo[i][j] = -1;
	//rec_print_desc(15);
	//rec_print_asc(15);
	cout << "Sum Of Natural number(10): " << sum_of_natural_numbers(10) << endl;
	cout << "Factorial(10): " << factorial(10) << endl;
	cout << "Power(3^100): " << power_rec(3,100) << endl;
	cout << "taylor_series(3,8): " << taylor_series_of_e_terms(5,8) << endl;
	cout << "taylor_series_of_e_terms_horner(3,8): " << taylor_series_of_e_terms_horner(5, 8) << endl;
	cout << "combination_rec(10,5): " << combination_rec(10,5) << endl;
	fibonacci(10);
}