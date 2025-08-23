#include<iostream>
#include<list>

using namespace std;

void display(list<int> &list) {
    string res = "[ ";
        for (auto it = list.begin(); it != list.end(); it++) {
            res.append(to_string(*it)); 
            if (it != --list.end()) res.append(", ");
        }
        res.append(" ]");
        cout<<res<<endl; 
}

int main() {
    list<int> nums;
    nums.push_back(1);
    nums.insert(nums.begin(), 2, 2);
    nums.insert(nums.end(), {1, 2});

    // delete last 3 elements
    auto it = nums.begin();
    advance(it, (nums.size() - 3));  
    // it moves the iterator to next position, we cannot use +, because we are not working with consecutive memory locations, rather it(list) is an implementation of doubly linked list, so we have pointers connected them.
    display(nums); // [ 2, 2, 1, 1, 2 ]
    // nums.erase(it, nums.end());

    // nums.remove(1);

    // nums.remove_if([](int x) {return x % 2 != 0;});

    // nums.unique(); // [ 2, 1, 2 ]

    nums.sort();

    display(nums);

    return 0;
}

// note: constructors
// default constructor: list() - Constructs an empty list.
// fill constructor: list(size_type n, const T& val) - Constructs a list with n copies of val.
// range constructor: list(InputIt first, InputIt last) - Constructs a list with elements from the range [first, last).
// copy constructor: list(const list& other) - Constructs a list as a copy of other.
// initializer list constructor: list(initializer_list<T> il) - Constructs a list from an initializer list.
// note: destructor
// destructor: ~list() - Destroys the list, deallocating all nodes.
// note: important pointers 
// front: T& front() - Returns a reference to the first element.
// back: T& back() - Returns a reference to the last element.
// begin: iterator begin() - Returns an iterator to the first element.
// end: iterator end() - Returns an iterator to the position past the last element.
// rbegin: reverse_iterator rbegin() - Returns a reverse iterator to the last element.
// rend: reverse_iterator rend() - Returns a reverse iterator to the position before the first element.
// cbegin: const_iterator cbegin() const - Returns a const iterator to the first element.
// cend: const_iterator cend() const - Returns a const iterator to the position past the last element.
// crbegin: const_reverse_iterator crbegin() const - Returns a const reverse iterator to the last element.
// crend: const_reverse_iterator crend() const - Returns a const reverse iterator to the position before the first element.

// note: methods of list
// empty: bool empty() const - Returns true if the list is empty, false otherwise.
// size: size_type size() const - Returns the number of elements in the list.
// max_size: size_type max_size() const - Returns the maximum number of elements the list can hold.
// clear: void clear() - Removes all elements, leaving the list empty.
// insert (single): iterator insert(const_iterator pos, const T& val) - Inserts val before position pos.
// insert (fill): iterator insert(const_iterator pos, size_type n, const T& val) - Inserts n copies of val before pos.
// insert (initializer list): iterator insert(const_iterator pos, initializer_list<T> il) - Inserts elements from an initializer list before pos.
// erase (single): iterator erase(const_iterator pos) - Removes the element at pos.
// erase (range): iterator erase(const_iterator first, const_iterator last) - Removes elements in the range [first, last).
// push_back: void push_back(const T& val) - Appends val to the end of the list.
// pop_back: void pop_back() - Removes the last element.
// push_front: void push_front(const T& val) - Prepends val to the front of the list.
// pop_front: void pop_front() - Removes the first element.
// resize (single): void resize(size_type n) - Resizes the list to n elements, truncating or appending default-constructed elements.
// resize (value): void resize(size_type n, const T& val) - Resizes the list to n elements, truncating or appending copies of val.
// swap: void swap(list& other) - Swaps the contents of the list with other.
// merge: void merge(list& other) - Merges sorted other into the list, assuming both are sorted.
// merge (comparator): void merge(list& other, Compare comp) - Merges sorted other into the list using comparator comp.
// remove: void remove(const T& val) - Removes all elements equal to val.
// remove_if: void remove_if(Predicate pred) - Removes all elements for which pred returns true.
// reverse: void reverse() - Reverses the order of elements in the list.
// sort: void sort() - Sorts the list in ascending order.
// sort (comparator): void sort(Compare comp) - Sorts the list using comparator comp.
// unique: void unique() - Removes consecutive duplicate elements.
// unique (predicate): void unique(Predicate pred) - Removes consecutive elements where pred returns true.