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

# Non-Linear Data Structures

Non-linear data structures are those in which elements are not arranged sequentially.

Each element can connect to multiple other elements, forming a hierarchy or network-like structure instead of a simple line.

**Examples:**

- Trees
- Heaps
- Tries
- Graphs

**Characteristics:**

- Elements have multiple relationships, not just predecessor and successor.
- Data is organized hierarchically (like in trees) or interconnected (like in graphs).
- Traversal is more complex and can occur in multiple directions (e.g., depth-first, breadth-first).

**Use Cases:**  
Non-linear data structures are ideal for representing hierarchical relationships (like file systems, organizational charts) and network connections (like social networks, maps, or web links).

## 1. Trees

A **tree** is a **non-linear data structure** that represents data in a **hierarchical form**.  
It consists of **nodes** connected by **edges**, forming a structure similar to an inverted tree in nature.

Each node contains:

- **Data:** The value stored in the node.
- **Links (edges):** References to its **child nodes**.

```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
};
```

---

### Basic Terminology

- **Root:**  
  The topmost node of the tree. It has no parent.

- **Child:**  
  A node that descends from another node (its parent).

- **Parent:**  
  A node that has one or more children.

- **Leaf Node:**  
  A node with no children.

- **Edge:**  
  A link connecting a parent to a child node.

- **Level:**  
  The distance from the root node. The root is at level 0.

- **Height:**  
  The longest path from the root to a leaf node.

### Pictorial Representation:

```css
                             [Root]
                               │
                 ┌─────────────┴─────────────┐
                 │                           │
              [Child A]                   [Child B]
                 │                           │
        ┌────────┴───────┐             ┌─────┴───────┐
        │                │             │             │
    [Child A1]       [Child A2]    [Child B1]     [Child B2]
        │                              │             │
      [Leaf]                         [Leaf]        [Leaf]
```

---

### Characteristics of Trees

- One node is designated as the **root**.
- Each child node can have **zero or more children**.
- There are **no cycles** (unlike graphs).
- If there are `n` nodes, there will always be `n - 1` edges.

---

### Types of Trees (Broad Overview)

- **General Tree:**  
  Each node can have any number of children.

- **Binary Tree:**  
  Each node has **at most two children** — a left and a right child.

- **Binary Search Tree (BST):**  
  A binary tree where:

  - Left child < Parent
  - Right child > Parent

- **Balanced Trees:**  
  Trees like AVL or Red-Black Trees maintain height balance for efficient operations.

- **Heaps:**  
  Trees used for priority-based operations (e.g., Min Heap, Max Heap).

---

### Key Operations on Trees

- **Traversal:**

  - **Preorder (Root → Left → Right)**
  - **Inorder (Left → Root → Right)**
  - **Postorder (Left → Right → Root)**
  - **Level Order (Breadth-first traversal)**

- **Insertion:** Add a node at the correct position.
- **Deletion:** Remove a node while maintaining tree properties.
- **Searching:** Find a node with a given value.

---

### Advantages

- **Hierarchical representation:** Ideal for modeling parent-child relationships.
- **Efficient searching and sorting** (especially in BSTs).
- **Dynamic structure:** Nodes can be easily added or removed.

### Disadvantages

- **Complex implementation** compared to linear structures.
- **Traversal is slower** than arrays for sequential access.
- **Memory overhead:** Each node requires multiple pointers.

---

### Real-World Applications

- File system hierarchy
- XML/HTML document parsing
- Database indexing (B-trees)
- Artificial Intelligence (decision trees)
- Expression parsing and evaluation

---

## **Types of Trees**:

## Binary Trees

A **Binary Tree** is a **a type of tree** in which each node can have **at most two children** — referred to as the **left child** and the **right child**.

Each node represents a data element and its connections to subtrees.

### Structure of a Binary Tree

Each node in a binary tree has:

- **Data:** The value stored in the node.
- **Left pointer:** Points to the left child node.
- **Right pointer:** Points to the right child node.

---

```cpp
template <typename T>
struct BinaryNode {
    T data;
    BinaryNode* left;
    BinaryNode* right;

    BinaryNode(T data) : data(data), left(nullptr), right(nullptr) {}
};
```

---

### Properties of Binary Trees

1. Each node can have **0, 1, or 2 children**.
2. A binary tree of height `h` has at most `2^(h+1) - 1` nodes.

---

### Declaring & Using a Binary Tree (C++ Example)

```cpp
#include <iostream>
using namespace std;

struct Node {
int data;
Node* left;
Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}

};

int main() {
Node\* root = new Node(10);
root->left = new Node(5);
root->right = new Node(20);

    cout << "Root: " << root->data << endl;       // 10
    cout << "Left Child: " << root->left->data << endl; // 5
    cout << "Right Child: " << root->right->data << endl; // 20

}
```

### Types of Binary Trees

- **Full Binary Tree:**  
  Every node has either **0 or 2 children**.

- **Perfect Binary Tree:**  
  All internal nodes have **two children**, and all leaf nodes are at the **same level**.

- **Complete Binary Tree:**  
  All levels are completely filled except possibly the last, which is filled from **left to right**.

- **Skewed Binary Tree:**  
  All nodes have only **one child**, either left or right — forming a chain-like structure.

- **Balanced Binary Tree:**  
  The height difference between the left and right subtree of every node is **at most 1**.

---

### Basic Operations and Their Complexity

| Operation | Description                       | Time Complexity |
| --------- | --------------------------------- | --------------- |
| Insertion | Add a new node to the tree        | O(n)            |
| Deletion  | Remove a node from the tree       | O(n)            |
| Searching | Find a node with given value      | O(n)            |
| Traversal | Visit each node in specific order | O(n)            |

---

💡 Notes & Best Practices

- Always check for nullptr before accessing child nodes.
- Use recursive functions for easy tree traversal.
- For balanced operations, prefer AVL or Red-Black Trees.
- Avoid excessive dynamic allocations to prevent memory leaks.

## Binary Search Tree (BST)

A **Binary Search Tree** is a binary tree where:

- The **left subtree** of a node contains only nodes with values **less than** the node’s value.
- The **right subtree** of a node contains only nodes with values **greater than** the node’s value.
- Both left and right subtrees must also be **binary search trees**.

---

**TLDR**: Binary tree with a rule that add a child node to left of the node if its value is less, else add a child node to right;

### Structure of the BST

```cpp
struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value) : data(value), left(nullptr), right(nullptr) {}
};
```

---

### Key Operations in BST

| Operation     | Description                                    | Time Complexity (Average) | Time Complexity (Worst) |
| ------------- | ---------------------------------------------- | ------------------------- | ----------------------- |
| **Insert**    | Add a new node maintaining BST property        | O(log n)                  | O(n)                    |
| **Search**    | Find a node by value                           | O(log n)                  | O(n)                    |
| **Delete**    | Remove a node and rearrange tree               | O(log n)                  | O(n)                    |
| **Traversal** | Visit all nodes (Inorder, Preorder, Postorder) | O(n)                      | O(n)                    |

---

### How BST Works

- **Insertion:**  
  Compare the new value with the root.

  - If smaller → go left.
  - If larger → go right.
  - Repeat until the correct position is found.

- **Searching:**  
  Similar to insertion, compare with current node and traverse left or right until found or NULL.

- **Deletion Cases:**
  1. **Leaf Node:** Remove directly.
  2. **One Child:** Replace the node with its child.
  3. **Two Children:** Replace with inorder successor (smallest in right subtree).

---

### Example

**BST for elements:** 50, 30, 70, 20, 40, 60, 80

```cpp
        50
       /  \
      30   70
     / \   / \
    20 40 60  80

```

---

### Advantages

- Efficient for **searching, insertion, and deletion**.
- Provides sorted order traversal.
- Easy to implement recursively.

### Disadvantages

- Performance degrades to O(n) if the tree becomes **unbalanced** (e.g., inserting sorted data).
- Requires balancing (like AVL or Red-Black Trees) for guaranteed efficiency.

---

### 💡 **Notes & Best Practices**

- Always ensure the tree remains **balanced** for optimal performance.
- **Inorder traversal** gives elements in **ascending order**.
- Avoid inserting duplicate values unless handling duplicates explicitly.
- Use **recursive or iterative** approaches depending on problem requirements.

---

## Types of Tree Traversal

Traversal means **visiting every node** in the tree exactly once in a specific order.

Broadly, there are two kinds of tree traversal algorithms:

## 1. Depth First Search (DFS)

We explore as far as possible along each branch before backtracking.  
This means visiting deeper nodes first, then moving upward.

1. **Pre-Order Traversal (Root → Left → Right)**

- Visit the root first.
- Then traverse the left subtree.
- Finally traverse the right subtree.
- Use: Used to create a copy of a tree or prefix expression (in expression trees).

```cpp
void preorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
```

2. **In-Order Traversal (Left → Root → Right)**

- Traverse the left subtree.
- Visit the root node.
- Then traverse the right subtree.
- Use: In a Binary Search Tree, in-order traversal gives elements in sorted order.

```cpp
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
```

3. **Post-Order Traversal (Left → Right → Root)**

- Traverse the left subtree.
- Then traverse the right subtree.
- Finally, visit the root.
- Use: Useful for deleting or freeing nodes (bottom-up), or postfix expression evaluation.

```cpp
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
```

### Example (DFS):

For the following tree:

```
      10
     /  \
    5    15
   / \     \
  2   7     20
```

- **Preorder:** 10, 5, 2, 7, 15, 20
- **Inorder:** 2, 5, 7, 10, 15, 20
- **Postorder:** 2, 7, 5, 20, 15, 10

---

## 2. Breadth First Search (BFS)

Also called Level-Order Traversal.  
We visit all nodes level by level — i.e., all nodes at depth 1, then depth 2, and so on.

Use: Used when processing elements level-wise — e.g., finding shortest path in unweighted trees or printing tree level by level.

```cpp
#include <queue>
void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->val << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}
```

### Example (BFS):

For the same tree:

```
      10
     /  \
    5    15
   / \     \
  2   7     20
```

**Level Order Traversal:** 10, 5, 15, 2, 7, 20

## Complete Binary Tree:

For a **binary tree** to be said a **complete**, if it satisfies two conditions:

i. Each level of the BST has maximum possible nodes.  
The formula: `Maximum Nodes = 2^d` where d is depth of the particular level.

ii. If the last level doesn't have maximum number of nodes, the available nodes must be as far left as possible.

## Depth and Height of a Node:

A **node** in a tree has two important characteristics: **Depth** and **Height**.

### 1. Depth

The **depth** of a node means how far (level-wise) a node is from the **root** of the tree.

```css
    8
   / \
  5   10
 / \    \
2   7    12
```

For example:  
Depth of node **7** in the tree below is **2**.

### _Explanation_:

- At root: **Depth = 0**
- Next row `[5, 10]`: **Depth = 1**
- Next row `[2, 7, 12]`: **Depth = 2**

Since **7** is in the last row, its **depth = 2**.

---

### 2. Height

The **height** of a node is the number of rows (or edges) from that node down to the **leaves** of the tree.

For example:  
Height of node **10** is **2**, since it is **two rows above the leaves**.

```css
    8
   / \
  5   10
 / \    \
2   7    12
```

- Height of **12** = 0 (leaf node)
- Height of **10** = 1 + max(height of left, right) = 1 + 1 = **2**

---

## AVL Trees

**AVL tree** — self-balancing binary search tree (BST) that maintains O(log n) height by keeping the heights of left/right subtrees of every node within 1.

## Key properties

- Binary Search Tree property: left < node < right
- Balance Factor (BF) = height(left) - height(right)
  - BF ∈ { -1, 0, 1 } for every node
- Height is guaranteed O(log n)

## Rotations (to restore balance)

- Right Rotation (RR) — fixes left-left case
- Left Rotation (LL) — fixes right-right case
- Left-Right (LR) — left child needs left rotation then current node right rotation
- Right-Left (RL) — right child needs right rotation then current node left rotation

Diagrams (informal):

```
- LL (right rotate at y) — before and after:

Before:
      y
     / \
    x   C
   / \
  A   B

Right rotate at y -> After:
      x
     / \
    A   y
       / \
      B   C

- RR (left rotate at x) — before and after:

Before:
      x
     / \
    A   y
       / \
      B   C

Left rotate at x -> After:
      y
     / \
    x   C
   / \
  A   B
```

## Insertion (high level)

1. Insert like BST.
2. Walk back up and update heights.
3. If node becomes unbalanced (|BF| > 1), identify case:
   - BF > 1 and key < left->key → Right rotate (LL)
   - BF < -1 and key > right->key → Left rotate (RR)
   - BF > 1 and key > left->key → Left rotate(left), then Right rotate (LR)
   - BF < -1 and key < right->key → Right rotate(right), then Left rotate (RL)
4. After rotation heights updated; tree balanced.

## Deletion (high level)

1. Delete like BST (0/1/2 child cases).
2. On the path back to root update heights and check BF.
3. Apply same 4 rotation cases as needed (case detection uses children BFs).

## Complexity

- Search: O(log n)
- Insertion: O(log n)
- Deletion: O(log n)
- Space: O(n) (nodes)

## When to use

- When balanced BST operations are required with guaranteed logarithmic time.
- When frequent inserts/deletes require strict height bounds (better worst-case than plain BST).

## C++ minimal node + helper functions (reference)

```cpp
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k): key(k), left(nullptr), right(nullptr), height(1) {}
};

int height(Node* n){ return n ? n->height : 0; }
int balance(Node* n){ return n ? height(n->left) - height(n->right) : 0; }

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}
```

## Tips & pitfalls

- Always update node heights after changes.
- When deciding LR/RL, check child’s balance to choose correct double-rotation.
- Beware single-node trees (height logic and edge cases).
- For simplicity, implement recursive insert/delete that returns new subtree root.

---

## Heap

A **Heap** is a binary tree with two rules:

- Always a **complete binary tree** (all levels filled except possibly last, filled left to right).
- In a **Min-Heap**, every parent node has a value **less than or equal to** its children.
- In a **Max-Heap**, every parent node has a value **greater than or equal to** its children.

---

**TLDR:** Complete binary tree with a rule:

- **Min-Heap:** parent ≤ children → smallest at root
- **Max-Heap:** parent ≥ children → largest at root

---

### Structure of the Heap

Heaps are usually stored in an **array**:

- For index `i`:
  - Left child → `2*i + 1`
  - Right child → `2*i + 2`
  - Parent → `(i-1) / 2`

---

### Key Operations in Heap

| Operation       | Description                             | Time Complexity (Average) | Time Complexity (Worst) |
| --------------- | --------------------------------------- | ------------------------- | ----------------------- |
| **Insert**      | Add new value and restore heap property | O(log n)                  | O(log n)                |
| **Get Root**    | Return min (min-heap) or max (max-heap) | O(1)                      | O(1)                    |
| **Delete Root** | Remove root and restore heap structure  | O(log n)                  | O(log n)                |
| **Traversal**   | No sorted order traversal               | O(n)                      | O(n)                    |

---

### How Heap Works

- **Insertion:**

  - Insert element at the end
  - Compare with parent
  - Swap upward until heap property is valid (**heapify up**)

- **Deleting Root:**
  - Remove root (min/max)
  - Move last element to root
  - Push it down until property holds (**heapify down**)

---

### Example

**Max-Heap for elements:** 50, 40, 30, 20, 10

```css
      50
     /  \
    40   30
    / \
    20 10
```

---

### Advantages

- Efficient for getting smallest or largest element quickly.
- Good for priority queues.
- Insertion and deletion are fast.

### Disadvantages

- Not useful for searching arbitrary values.
- Only root is guaranteed min/max — not sorted order.
- Traversing in sorted order is not direct.

---

### Notes & Best Practices

- Always forms a **complete binary tree**.
- Root gives **min** (min-heap) or **max** (max-heap).
- Usually implemented using **arrays**.
- Avoid using heap when you frequently need sorted traversal.

---

## Trie (Prefix Tree)

A **Trie** is a specialized tree data structure used to store strings
efficiently, especially when working with prefixes, autocomplete, and
dictionary operations.

## Structure of a Trie

Each TrieNode typically stores: - **Children** (array/map) - **isEnd
flag** → marks the end of a complete word

### Index Rules (for lowercase a--z)

- Children array size: **26**

- Child index for a character `c`:

  ```text
  index = c - 'a'
  ```

### Root Node

- Represents an empty string
- Has no character itself

## Properties

- Always a **prefix tree**
- Each edge represents a **character**
- Path from root → node forms a **prefix**
- Words that share prefixes share nodes → memory efficient
- Depth of Trie = length of longest word

## Key Operations and Complexity

Operation Description Time Complexity

1. **Insert(word)** Insert characters one by one O(length)

2. **Search(word)** Check if the full word exists O(length)

3. **StartsWith(prefix)** Check if any word begins with prefix O(length)

4. **Delete(word)** Remove a word safely (optional) O(length)

## How a Trie Works

### Insert Word

1.  Start at root
2.  For each character in the word:
    - If child doesn't exist → create it
    - Move to that child
3.  Mark last node with `isEnd = true`

---

### Search Word

- Traverse character-by-character
- If any link is missing → word doesn't exist
- After finishing traversal → check `isEnd == true`

---

### Search Prefix

- Traverse nodes using prefix characters
- If traversal succeeds, prefix exists
- No need to check `isEnd`

## Example Trie for Words

Words: `cat`, `can`, `bat`

            (root)
            /     \
           c       b
          /         \
         a           a
        / \           \
       t   n           t

## Advantages

- Extremely fast prefix lookups
- Insert/Search cost depends only on **word length**, not number of
  words
- Great for autocomplete and dictionary-type problems

## Disadvantages

- Can consume a lot of memory (large alphabets → more children)
- Not efficient for storing a few very long strings
- Deletion logic is slightly more complex

## Best Practices

- For lowercase English letters → use `children[26]` array
- For general alphabets → use `unordered_map<char, TrieNode*>`
- Always implement these three methods for interviews:
  - `insert(word)`
  - `search(word)`
  - `startsWith(prefix)`

## Common Interview Problems Using Trie

- Autocomplete System
- Word Dictionary
- Word Break problems
- Replace Words (prefix dictionary)
- Search Suggestions System
- Count words starting with a prefix
- Longest prefix match (like routers)

## Sample TrieNode Structure (C++)

```cpp
struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isEnd = false;
    }
};
```

## 2. Graphs

A **graph** is a non-linear data structure consisting of a set of
**vertices (nodes)** and **edges** that connect pairs of vertices.\
Graphs are used to represent relationships between objects.

## Basic Terminology

- **Vertex (Node):**\
  A fundamental unit of the graph where data is stored.

- **Edge:**\
  A connection between two vertices.

- **Adjacent Vertices:**\
  Two vertices connected directly by an edge.

- **Degree:**\
  Number of edges connected to a vertex.

  - **In-degree:** Incoming edges (directed graphs)
  - **Out-degree:** Outgoing edges (directed graphs)

- **Path:**\
  A sequence of vertices connected by edges.

- **Cycle:**\
  A path where the starting and ending vertex is the same.

- **Connected Graph:**\
  Every vertex is reachable from every other vertex.

- **Weighted Graph:**\
  Each edge has a weight (cost, distance, etc.).

## Visual Example (Conceptual)

       A ----- B
       | \     |
       |    \  |
       C ----- D

This represents an undirected graph with edges between A-B, A-C, A-D,
C-D, and B-D.

## Types of Graphs

### **1. Undirected Graph**

Edges do not have a direction.\
Example:\
A --- B means A is connected to B **both ways**.

### **2. Directed Graph (Digraph)**

Edges have directions.\
A → B means the connection is **from A to B**.

### **3. Weighted Graph**

Edges carry weights.\
Useful for shortest path algorithms (Dijkstra, Bellman-Ford).

### **4. Unweighted Graph**

All edges are considered equal.

### **5. Cyclic Graph**

Contains at least one cycle.

### **6. Acyclic Graph**

Contains **no cycles**.\
Example: **Directed Acyclic Graph (DAG)** used in task scheduling.

### **7. Connected Graph**

All nodes are reachable from any starting node.

### **8. Disconnected Graph**

Some nodes cannot be reached from others.

## Graph Representation

### **1. Adjacency Matrix**

A 2D matrix where: - `matrix[i][j] = 1` if an edge exists\

- Space complexity: O(V²)

### **2. Adjacency List**

Each vertex stores a list of adjacent nodes.\

- Space efficient\
- Space complexity: O(V + E)

Example:

```cpp
vector<vector<int>> graph(n);
graph[u].push_back(v);
graph[v].push_back(u);
```

## Graph Traversals

### **1. Depth-First Search (DFS)**

- Explores as far as possible before backtracking.
- Implemented using recursion or a stack.

### **2. Breadth-First Search (BFS)**

- Explores all neighbors level by level.
- Implemented using a queue.

## Real-World Applications

- Social networks (friend connections)
- Google Maps (shortest paths)
- Web crawlers (graph traversal)
- Recommendation systems
- Network routing
- Dependency resolution (DAGs)

## Advantages

- Represents complex relationships
- Useful for modeling real-world networks
- Supports many powerful algorithms

## Disadvantages

- More complex to implement
- Memory usage depends on representation
- Some graph algorithms are expensive (e.g., O(V³))
