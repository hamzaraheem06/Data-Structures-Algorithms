#include<iostream>
#include<stack>

using namespace std;

class Queue {
    private: 
        int* arr;
        int front;
        int back;
        int capacity;
        int count;

    public: 
        Queue(int n) {
            capacity = n;
            arr = new int[capacity];
            front = -1;
            back = 0;
            count = 0;
        }

        void enqueue(int val) {
            if (count == capacity) return;

            *(arr + back) = val;
            back = (back + 1) % capacity;
            count ++;
        }

        int size() {
            return capacity;
        }


        bool empty() {
            return count == 0;
        }

        int dequeue() {
            if (empty())  throw runtime_error("Empty queue. \n");
            
            front = (front + 1) % capacity;
            int val = *(arr + front);
            *(arr + front) = -1;
            count --;
            return val;
        }

        void display() {
            string res = "[ ";
            for (int i = 0; i < capacity; i++) {
                res.append(std::to_string(arr[i])); 
                if (i != capacity - 1) res.append(", ");
            }
            res.append(" ]");
            cout<<res<<endl; 
        }
};

#include<stack>

// Approach:
// push: push at bottom
// pop: return the top

class StackQueue {
    private:
        stack<int> st;

        stack<int> pushAtBottom(stack<int> st, int val) {
            if (st.empty()) {
                st.push(val);
                return st;
            }

            int top = st.top();
            st.pop();

            stack<int> rest = pushAtBottom(st, val);
            rest.push(top);

            return rest;
        }
    public: 

        StackQueue() {

        }

        void enqueue(int val) {
            st = pushAtBottom(st, val);
        }

        int dequeue() {
            int front = st.top();
            st.pop();
            return front;
        }

        void display() {
            string s = "[ ";

            stack<int> iter(st); // copy constructor

            while(!iter.empty()) {
                s.append(to_string(iter.top()));
                iter.pop();
                if (!iter.empty()) s.append(", ");
            }

            s.append(" ]");
            
            cout << s << endl;
        }

};

// Another approach: use two stacks : st1 and st2

// always push in st1

// for removing check if the st2 is empty or not, if yes, pop all the elements from st1 to st2 in reverse order (i.e. they are returned in reverse order by default) and then return the top of the st2

class TwoStackQueue {
    private: 
        stack<int> st1, st2;

    public:
        void enqueue(int val) {
            st1.push(val);
        }

        int dequeue() {
            if(st2.empty()) {
                while(!st1.empty()) {
                    int top = st1.top();
                    st1.pop();
                    st2.push(top);
                }
            }

            int front = st2.top();
            st2.pop();

            return front;
        }
};

class PriorityQueue  {
    private: 
        int* arr;
        int front;
        int back;
        int capacity;
        int count;

    public: 
        PriorityQueue(int n) {
            capacity = n;
            arr = new int[capacity];
            front = -1;
            back = 0;
            count = 0;
        }

        void enqueue(int val) {
            if (count == capacity) return;

            int i = 0; 

            for (i = back; i > 0; i--) {
                if(arr[i - 1] <= val) break;
                else {
                    arr[i] = arr[i - 1];
                }
            }

            *(arr + i) = val;
            back = (back + 1) % capacity;
            count ++;
        }

        int size() {
            return capacity;
        }


        bool empty() {
            return count == 0;
        }

        int dequeue() {
            if (empty())  throw runtime_error("Empty queue. \n");
            
            front = (front + 1) % capacity;
            int val = *(arr + front);
            *(arr + front) = -1;
            count --;
            return val;
        }

        void display() {
            string res = "[ ";
            for (int i = 0; i < capacity; i++) {
                res.append(std::to_string(arr[i])); 
                if (i != capacity - 1) res.append(", ");
            }
            res.append(" ]");
            cout<<res<<endl; 
        }
};


int main() {
    PriorityQueue q(10);

    q.enqueue(10);
    q.enqueue(12);
    q.enqueue(2);
    q.enqueue(1);

    q.enqueue(3);

    q.enqueue(-23);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl; 

    // q.display();
    return 0;
}