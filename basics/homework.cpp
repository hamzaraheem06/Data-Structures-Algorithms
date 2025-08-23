#include<iostream>

using namespace std;

void print(int n) {
    if (n == 0) return;
    print(n - 1);
    cout<<n;
}

int sum(int n ) {
    if (n == 0) return 0;

    return n + sum(n - 1);
}

int power(int n, int p) {
    if (p == 1) return n;

    return n * power(n, p - 1);
}

int main() {
    cout<< power(5, 3);
    return 0;
}