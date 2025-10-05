# Data Structures & Algorithms

**Data Structures**  
Organize and store data efficiently. The structure can be linear, non-linear, or other forms depending on requirements.

**Algorithms**  
A step-by-step sequence of operations designed to solve a specific problem or perform a task.

---

## Types of Data Structures

- **Linear Data Structures:**  
  Data elements are arranged sequentially, one after another.  
  _Examples:_ Arrays, Linked Lists, Stacks, Queues

- **Non-Linear Data Structures:**  
  Data elements are connected in a hierarchical or networked manner, not sequentially.  
  _Examples:_ Trees, Graphs

---

\*Linear structures are simple and easy to traverse, while non-linear structures are useful for representing

## Time & Space Complexity

Time Complexity: Indicates how the execution time of an algorithm increases as the input size grows.  
Common notations:

- **Big O (O):** Describes the upper bound (worst-case) performance.
- **Theta (Θ):** Describes the tight bound (average-case) performance.
- **Omega (Ω):** Describes the lower bound (best-case) performance.

Space Complexity: Indicates how much extra memory an algorithm requires as the input size grows.  
It measures the total space or memory needed, including input, auxiliary

## Bitwise Operators in C++

Bitwise operators work directly on the binary representation of integers.

- **AND (`&`):**  
  Sets each bit to 1 if both bits are 1.  
  _Example:_ `5 & 3` → `1`

- **OR (`|`):**  
  Sets each bit to 1 if at least one bit is 1.  
  _Example:_ `5 | 3` → `7`

- **XOR (`^`):**  
  Sets each bit to 1 if bits are different.  
  _Example:_ `5 ^ 3` → `6`

  If we use XOR on a list with duplicates it will remove duplicates.

- **NOT (`~`):**  
  Inverts all bits.  
  _Example:_ `~5` → `-6`

---

## Bitwise Shift Operators

- **Left Shift (`<<`):**  
  Shifts bits to the left, adding zeros on the right.  
  Each shift multiplies the number by 2.  
  _Example:_ `3 << 2` → `12` (3 × 4)

- **Right Shift (`>>`):**  
  Shifts bits to the right, discarding rightmost bits.  
  Each shift divides the number by 2 (integer division).  
  _Example:_ `16 >> 3` → `2` (16 ÷ 8)

---

**Tip:**

- use & or ^ operator to check if the number is even or odd.
- use shift operators to traverse bits.
- Use `x & 1` to get the least significant bit (LSB).
- Use bitwise operations for fast multiplication/division by powers of two.

---

# Linear Data Structures

Linear data structures are those in which elements are arranged sequentially, one after another.  
Each element has a unique predecessor and successor (except the first and last elements).

**Examples:**

- Arrays
- Linked Lists
- Stacks
- Queues

**Characteristics:**

- Easy to traverse in a single direction (from start to end).
- Memory is often allocated in a contiguous or linked manner.
- Operations like insertion, deletion, and access depend on the specific type of linear structure.

**Use Cases:**  
Linear data structures are ideal when you need to process data in order, maintain a sequence, or require efficient access to elements.

## 1. Arrays

Arrays store elements of the same type in contiguous memory locations.

- **Static Size:**  
  The size of an array is fixed at the time of creation and cannot be changed.

- **Indexing:**  
  Elements are accessed using an index, starting from `0` up to `n - 1`, where `n` is the size of the array.

---

### Time Complexities for Array Operations

- **Insertion:**

  - At end (if space available): O(1)  
    Direct access to memory allows fast insertion at the end.
  - At specific index: O(n)  
    Inserting at a specific index requires shifting elements to make space.

- **Lookup:**

  - By index: O(1)  
    Direct access to any index.
  - By value (search): depends on algorithm used.
    - O (n) for Linear search.

- **Deletion:**
  - At end: O(1)  
    Removing the last element is fast.
  - At specific index: O(n)  
    Removing an element requires shifting subsequent elements.
  - At start: O(n)  
    All elements must be shifted left by one position.

## Vectors

- A **vector** is a dynamic array that can **grow or shrink** automatically.
- Declared in the `<vector>` header.
- Stores elements **contiguously** in memory (like arrays) but resizes dynamically.

---

### How Vectors Work Internally

- Uses a **dynamically allocated array** internally.
- Keeps track of:
  - **Size** → number of elements currently stored.
  - **Capacity** → allocated memory size before reallocation is needed.
- When capacity is exceeded:
  1. Allocates **new, larger memory** (usually 2× old capacity).
  2. Copies old elements into new space.
  3. Frees old memory.

---

### Declaring & Initializing a Vector

```cpp
#include <vector>
using namespace std;

vector<int> v1;                 // empty vector
vector<int> v2 = {1, 2, 4, 6, 6}; // initializer list
vector<int> v3(5, 10);          // size=5, all values=10
vector<int> v4(v2);             // copy constructor
vector<int> v5(v2.begin(), v2.end()); // from iterators
```

### Adding Elements

```cpp
v.push_back(5);  // append at end
v.emplace_back(5); // append (in-place, faster for objects)
v.insert(v.begin() + 2, 99); // insert at position (iterator)

    Note: insert can also insert ranges:
    v.insert(pos, count, value);
    v.insert(pos, other.begin(), other.end());
```

### Size & Capacity

```cpp
v.size();      // number of elements
v.capacity();  // allocated storage
v.max_size();  // max possible elements
v.reserve(100); // pre-allocate space
v.shrink_to_fit(); // free unused capacity
```

### Accessing Elements

```cpp
v.at(2);     // safe access (throws exception if out-of-range)
v[2];        // direct access (no bounds check)
v.front();   // first element
v.back();    // last element
v.data();    // pointer to internal array
```

### Removing Elements

```cpp
v.pop_back();              // remove last
v.erase(v.begin() + 3);    // remove at position
v.erase(v.begin() + 2, v.begin() + 5); // remove range
v.clear();                 // remove all
```

Checking Status

```cpp
v.empty(); // true if vector is empty
```

### Common Algorithms with Vectors

```cpp
#include <algorithm>

// Reverse
reverse(v.begin(), v.end());

// Sort ascending
sort(v.begin(), v.end());

// Sort descending
sort(v.begin(), v.end(), greater<int>());

// Remove duplicates
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
```

💡 Notes & Best Practices

    Pass by reference (const vector<int>& v) to avoid expensive copies.

    Use reserve() when size is known to avoid multiple reallocations.

    Prefer emplace_back() for constructing objects directly in place.

    Remember: Insertions/removals at the end are O(1) amortized,
    but in the middle or front are O(n).

---

## 2. Linked Lists

A **linked list** is a linear data structure where elements (nodes) are connected together in sequence.

Linked lists nodes are not stored at a contiguous location, rather they are linked using pointers to the different memory locations.

Each node contains:

- **Data:** The value stored in the node.
- **Pointer (next):** Reference to the next node in the list.

```cpp
struct Node {
    int value;
    Node* next;
};
```

---

### Types of Linked Lists

- **Singly Linked List:**  
  Each node points to the next node. Traversal is possible in one direction only.

- **Doubly Linked List:**  
  Each node has pointers to both the next and previous nodes. Traversal is possible in both directions.

- **Circular Linked List:**  
  The last node points back to the first node, forming a circle.

---

### Key Operations

- **Insertion:**

  - At beginning: O(1)
  - At end: O(n) (unless tail pointer is maintained)
  - At specific position: O(n)

- **Deletion:**

  - At beginning: O(1)
  - At end or specific position: O(n)

- **Traversal:**
  - Visit each node from head to end: O(n)

---

### Memory Allocation in Linked Lists

- **Dynamic Allocation:**  
  Linked lists use dynamic memory allocation for each node.  
  When a new node is inserted, memory is allocated on the heap using `new` (in C++).

- **Node Structure:**  
  Each node contains:

  - Data (the value)
  - Pointer(s) to the next (and/or previous) node(s)

- **Insertion:**

  - When inserting a node, a new block of memory is allocated for the node.
  - The pointer in the previous node is updated to reference the new node.
  - No need to shift other elements (unlike arrays).

- **Deletion:**

  - When deleting a node, the pointer in the previous node is updated to skip the deleted node.
  - The memory occupied by the deleted node is freed (`delete` in C++).

- **Traversal:**
  - Traversal does not allocate or free memory; it simply follows pointers from node to node.

---

### Advantages

- **Dynamic size:** Can grow or shrink during runtime.
- **Efficient insertion/deletion** at the beginning.

### Disadvantages

- **No random access:** Must traverse from head to access a specific element.
- **Extra memory:** Each node stores a pointer.

---

## 3. Stacks

A **stack** is a linear data structure that follows the Last-In, First-Out (LIFO) principle.  
The last element added is the first one to be removed.

---

### How Stacks Work

- Elements are added and removed from only one end, called the **top**.
- Common operations:
  - **Push:** Add an element to the top.
  - **Pop:** Remove the top element.
  - **Peek/Top:** View the top element without removing it.

---

### Declaring & Using a Stack (C++ Example)

```cpp
#include <stack>
using namespace std;

stack<int> s;      // empty stack
s.push(10);        // push 10
s.push(20);        // push 20
s.pop();           // removes 20
int x = s.top();   // x = 10
bool empty = s.empty(); // true if stack is empty
```

---

### Time Complexities for Stack Operations

- **Push:** O(1)
- **Pop:** O(1)
- **Top/Peek:** O(1)
- **Size:** O(1)
- **Empty:** O(1)

---

### Implementation

- **Array-based stack:** Uses a fixed-size or dynamic array (e.g., `vector`).
- **Linked list-based stack:** Uses nodes with pointers for dynamic size.

---

### Use Cases

- Function call management (call stack)
- Undo operations in editors
- Expression evaluation (infix, postfix)
- Backtracking algorithms

---

### Advantages

- Simple and efficient for LIFO operations.
- Fast insertion and removal.

### Disadvantages

- Limited access: Only the top element can be accessed.
- Fixed size if implemented with arrays (unless using dynamic arrays or linked lists).

---

💡 **Notes & Best Practices**

- Prefer STL `stack` for most use cases in C++.
- Use `vector` or `deque` as underlying containers for flexibility.
- Always check `empty()` before calling `top()` or `pop()` to avoid errors.
- Stacks are not suitable when you need to access elements other than the top.

---

## 4. Queues

A **queue** is a linear data structure that follows the First-In, First-Out (FIFO) principle.  
The first element added is the first one to be removed.

---

### How Queues Work

- Elements are added at the **rear** (back) and removed from the **front**.
- Common operations:
  - **Enqueue:** Add an element to the rear.
  - **Dequeue:** Remove the front element.
  - **Front:** View the front element without removing it.

---

### Declaring & Using a Queue (C++ Example)

```cpp
#include <queue>
using namespace std;

queue<int> q;      // empty queue
q.push(10);        // enqueue 10
q.push(20);        // enqueue 20
q.pop();           // removes 10
int x = q.front(); // x = 20
bool empty = q.empty(); // true if queue is empty
```

---

### Time Complexities for Queue Operations

- **Enqueue (push):** O(1)
- **Dequeue (pop):** O(1)
- **Front:** O(1)
- **Size:** O(1)
- **Empty:** O(1)

---

### Implementation

- **Array-based queue:** Uses a fixed-size or dynamic array (may require circular buffer logic).
- **Linked list-based queue:** Uses nodes with pointers for dynamic size.
- **STL queue:** Uses `deque` or `list` as the underlying container.

---

### Advantages

- Simple and efficient for FIFO operations.
- Fast insertion at rear and removal from front.

### Disadvantages

- Limited access: Only the front and rear elements can be accessed.
- Fixed size if implemented with arrays (unless using dynamic arrays or linked lists).

---

💡 **Notes & Best Practices**

- Prefer STL `queue` for most use cases in C++.
- Use `deque` or `list` for flexible underlying containers.
- Always check `empty()` before calling `front()` or `pop()` to avoid errors.
- Queues are not suitable when you need to access elements other than the front or rear.

### Priority Queue

A **priority queue** is a special type of queue where each element is assigned a **priority**,  
and elements with **higher priority** are served before those with lower priority.  
If two elements have the same priority, they are served according to their order in the queue.

---

### How Priority Queues Work

- Elements are ordered by **priority**, not by insertion order.
- By default in C++:
  - The **largest element** has the highest priority (max-heap).
- Common operations:
  - **Push (enqueue):** Insert an element.
  - **Pop (dequeue):** Remove the element with the highest priority.
  - **Top:** Access the element with the highest priority.

---

### Declaring & Using a Priority Queue (C++ Example)

```cpp
#include <queue>
using namespace std;

priority_queue<int> pq;   // max-heap by default

pq.push(10);   // insert 10
pq.push(5);    // insert 5
pq.push(20);   // insert 20

int x = pq.top(); // x = 20 (highest priority)
pq.pop();         // removes 20
bool empty = pq.empty(); // true if empty

// Min-heap example:
priority_queue<int, vector<int>, greater<int>> min_pq;
min_pq.push(10);
min_pq.push(5);
min_pq.push(20);
int y = min_pq.top(); // y = 5 (smallest element)
```

### Time Complexities for Priority Queue Operations

- **Push (insert):** O(log n)
- **Pop (remove top):** O(log n)
- **Top (peek max/min):** O(1)
- **Size:** O(1)
- **Empty:** O(1)

---

### Implementation

- **Heap-based (common):** Usually implemented with a binary heap.
- **STL priority_queue:** Built on top of a max-heap (`std::make_heap`, `std::push_heap`, `std::pop_heap`).
- **Other options:** Fibonacci heap, binary search tree, etc. (less common in practice).

---

### Advantages

- Efficient for retrieving the highest (or lowest) priority element.
- Automatically keeps elements sorted by priority.

---

### Disadvantages

- No random access to arbitrary elements.
- Insertion and deletion are slower than simple queues (O(log n) vs O(1)).

---

### 💡 Notes & Best Practices

- Use `priority_queue` when order matters more than insertion sequence.
- Use **max-heap** (default) for largest-first behavior.
- Use **min-heap** with `greater<T>` comparator when you need smallest-first.
- Always check `empty()` before `top()` or `pop()`.
