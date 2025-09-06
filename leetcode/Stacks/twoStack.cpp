#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class TwoStack {
    private: 
        int top1, top2;
        vector<T> arr;
        int size;

    public:
        TwoStack(int n) {
            size = n - (n % 2); // making sure even size, discard the odd portion
            cout << "Size: " << size << endl;
            arr = vector<T>(size); // default-initialize elements
            top1 = -1;
            top2 = size / 2 - 1;
        }

        bool full1() const {
            return top1 >= (size / 2 - 1); 
        }

        bool full2() const  {
            return top2 >= ( size - 1 ); 
        }

        bool empty1() const {
            return top1 == -1; 
        }

        bool empty2()  const {
            return top2 == (size / 2 - 1); 
        }

        void push1(T val) {
            if (full1()) {
                cout <<"Stack Overflow." << endl;
                return;
            }

            arr[++top1] = val;
        }

        void push2(T val) {
            if (full2()) {
                cout <<"Stack Overflow." << endl;
                return;
            }

            arr[++top2] = val;
        }

        T pop1() {
            if (empty1()) {
                cout << "Stack Underflow." << endl;
                return T{};
            }
            T val = arr[top1];
            arr[top1--] = T{};
            return val;
        }

        T pop2() {
            if (empty2()) {
                cout << "Stack Underflow." << endl;
                return T{};
            }
            T val = arr[top2];
            arr[top2--] = T{};
            return val;
        }

        T peek1()  const {
            return (empty1())? T{} : arr[top1];
        }

        T peek2() const  {
            return (empty2())? T{} : arr[top2];
        }

};


int main() {
    TwoStack<string> ts(10);

    // Push elements to Stack 1
    ts.push1("Hamza");
    ts.push1("Uzair Nigga");
    ts.push1("Mahad Khan Niazi");

    // Push elements to Stack 2
    ts.push2("Saad");
    ts.push2("Amad");
    ts.push2("Waqas");

    // Peek top elements
    cout << "Top of Stack 1: " << ts.peek1() << endl; // Should print 3
    cout << "Top of Stack 2: " << ts.peek2() << endl; // Should print 13

    // Pop elements from Stack 1
    cout << "Pop from Stack 1: " << ts.pop1() << endl; // Should print 3
    cout << "Pop from Stack 1: " << ts.pop1() << endl; // Should print 2

    // Pop elements from Stack 2
    cout << "Pop from Stack 2: " << ts.pop2() << endl; // Should print 13
    cout << "Pop from Stack 2: " << ts.pop2() << endl; // Should print 12

    // Try popping from empty stack
    ts.pop1();
    ts.pop1(); // Should print "Stack Underflow."

    ts.pop2();
    ts.pop2(); // Should print "Stack Underflow."

    return 0;
}
