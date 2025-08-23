# STL (Standard Template Library) - Quick Guide

## What is STL?
STL is a collection of template classes and functions that provide common data structures and algorithms. It consists of:
- **Containers**: Store data (vector, list, map, etc.)
- **Iterators**: Access container elements
- **Algorithms**: Operate on containers (sort, find, etc.)
- **Function Objects**: Customize algorithm behavior

## 1. Array (C++11)
Fixed-size container that wraps built-in arrays.

```cpp
#include <array>

// Declaration and initialization
array<int, 5> arr = {1, 2, 3, 4, 5};
array<int, 5> arr2{10, 20, 30, 40, 50};

// Access elements
arr[0] = 100;        // Direct access
arr.at(1) = 200;     // Bounds-checked access
int first = arr.front();  // First element
int last = arr.back();    // Last element

// Properties
cout << arr.size();      // Always 5
cout << arr.empty();     // false (never empty if size > 0)

// Iteration
for (int x : arr) cout << x << " ";
for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " ";
```

**Use Case**: When you need a fixed-size container with array performance.

## 2. Vector
Dynamic array that can grow and shrink.

```cpp
#include <vector>

// Declaration and initialization
vector<int> v1;                    // Empty vector
vector<int> v2(5);                 // 5 elements, default value 0
vector<int> v3(5, 10);             // 5 elements, all 10
vector<int> v4{1, 2, 3, 4, 5};     // Initializer list

// Adding elements
v1.push_back(10);        // Add to end
v1.emplace_back(20);     // Construct in place (more efficient)
v1.insert(v1.begin(), 5); // Insert at beginning

// Removing elements
v1.pop_back();           // Remove last element
v1.erase(v1.begin());    // Remove first element
v1.clear();              // Remove all elements

// Access elements
v4[0] = 100;             // Direct access (no bounds check)
v4.at(1) = 200;          // Bounds-checked access
int first = v4.front();   // First element
int last = v4.back();     // Last element

// Properties
cout << v4.size();       // Current number of elements
cout << v4.capacity();   // Current allocated capacity
cout << v4.empty();      // Check if empty

// Resize and reserve
v4.resize(10);           // Change size to 10
v4.reserve(100);         // Reserve capacity for 100 elements
```

**Use Case**: Most commonly used container for dynamic arrays.

## 3. Deque (Double-ended Queue)
Dynamic array with fast insertion/deletion at both ends.

```cpp
#include <deque>

// Declaration and initialization
deque<int> dq{1, 2, 3, 4, 5};

// Adding elements
dq.push_back(6);         // Add to end
dq.push_front(0);        // Add to beginning
dq.emplace_back(7);      // Construct at end
dq.emplace_front(-1);    // Construct at beginning

// Removing elements
dq.pop_back();           // Remove from end
dq.pop_front();          // Remove from beginning

// Access elements
dq[2] = 100;             // Direct access
int first = dq.front();   // First element
int last = dq.back();     // Last element

// Properties
cout << dq.size();       // Number of elements
cout << dq.empty();      // Check if empty
```

**Use Case**: When you need fast insertion/deletion at both ends.

## 4. List (Doubly Linked List)
Doubly linked list with fast insertion/deletion anywhere.

```cpp
#include <list>

// Declaration and initialization
list<int> lst{1, 2, 3, 4, 5};

// Adding elements
lst.push_back(6);        // Add to end
lst.push_front(0);       // Add to beginning
lst.insert(++lst.begin(), 10); // Insert after first element

// Removing elements
lst.pop_back();          // Remove from end
lst.pop_front();         // Remove from beginning
lst.remove(10);          // Remove all occurrences of 10
lst.erase(lst.begin());  // Remove first element

// Access elements (no random access)
int first = lst.front(); // First element
int last = lst.back();   // Last element

// List-specific operations
lst.sort();              // Sort the list
lst.reverse();           // Reverse the list
lst.unique();            // Remove consecutive duplicates

// Merge two sorted lists
list<int> lst2{7, 8, 9};
lst.merge(lst2);         // Merge lst2 into lst (both must be sorted)
```

**Use Case**: When you need frequent insertion/deletion in the middle.

## 5. Stack (LIFO - Last In First Out)
Adapter container implementing stack behavior.

```cpp
#include <stack>

// Declaration (uses deque by default)
stack<int> st;
stack<int, vector<int>> st2; // Using vector as underlying container

// Adding elements
st.push(10);
st.push(20);
st.push(30);
st.emplace(40);          // Construct in place

// Accessing elements
int top_element = st.top(); // Get top element (30)

// Removing elements
st.pop();                // Remove top element (no return value)

// Properties
cout << st.size();       // Number of elements
cout << st.empty();      // Check if empty

// Usage pattern
while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
}
```

**Use Case**: Function calls, expression evaluation, undo operations.

## 6. Queue (FIFO - First In First Out)
Adapter container implementing queue behavior.

```cpp
#include <queue>

// Declaration (uses deque by default)
queue<int> q;
queue<int, list<int>> q2; // Using list as underlying container

// Adding elements
q.push(10);
q.push(20);
q.push(30);
q.emplace(40);           // Construct in place

// Accessing elements
int front_element = q.front(); // Get front element (10)
int back_element = q.back();   // Get back element (40)

// Removing elements
q.pop();                 // Remove front element (no return value)

// Properties
cout << q.size();        // Number of elements
cout << q.empty();       // Check if empty

// Usage pattern
while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
}
```

**Use Case**: BFS traversal, process scheduling, buffer management.

## 7. Priority Queue (Max Heap by default)
Container adapter that provides priority-based ordering.

```cpp
#include <queue>

// Declaration (max heap by default)
priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int>> min_pq; // Min heap

// Adding elements
pq.push(30);
pq.push(10);
pq.push(50);
pq.push(20);
pq.emplace(40);

// Accessing elements
int max_element = pq.top(); // Get highest priority element (50)

// Removing elements
pq.pop();                // Remove highest priority element

// Properties
cout << pq.size();       // Number of elements
cout << pq.empty();      // Check if empty

// Custom comparator for objects
struct Task {
    int priority;
    string name;
    
    bool operator<(const Task& other) const {
        return priority < other.priority; // Lower priority number = higher priority
    }
};

priority_queue<Task> task_pq;
task_pq.push({1, "High Priority"});
task_pq.push({5, "Low Priority"});
```

**Use Case**: Dijkstra's algorithm, task scheduling, finding kth largest element.

## 8. Set (Ordered Unique Elements)
Associative container with unique, sorted elements.

```cpp
#include <set>

// Declaration and initialization
set<int> s{3, 1, 4, 1, 5}; // Result: {1, 3, 4, 5} (duplicates removed)

// Adding elements
s.insert(2);             // Insert single element
s.insert({6, 7, 8});     // Insert multiple elements
s.emplace(9);            // Construct in place

// Removing elements
s.erase(3);              // Remove element 3
s.erase(s.begin());      // Remove first element
s.clear();               // Remove all elements

// Finding elements
auto it = s.find(4);     // Returns iterator to 4, or s.end() if not found
bool exists = s.count(4); // Returns 1 if exists, 0 otherwise

// Range operations
auto lower = s.lower_bound(3); // First element >= 3
auto upper = s.upper_bound(6); // First element > 6

// Properties
cout << s.size();        // Number of elements
cout << s.empty();       // Check if empty

// Iteration (always sorted order)
for (int x : s) cout << x << " ";

// Multiset (allows duplicates)
multiset<int> ms{1, 2, 2, 3, 3, 3};
cout << ms.count(3);     // Returns 3
```

**Use Case**: Maintaining unique sorted elements, fast lookup/insertion.

## 9. Map (Key-Value Pairs)
Associative container with unique keys and associated values.

```cpp
#include <map>

// Declaration and initialization
map<string, int> m;
map<string, int> m2{{"apple", 5}, {"banana", 3}, {"cherry", 8}};

// Adding/Updating elements
m["apple"] = 10;         // Insert or update
m.insert({"orange", 7}); // Insert pair
m.emplace("grape", 12);  // Construct in place

// Accessing elements
int apple_count = m["apple"];     // Returns value, creates key if not exists
int banana_count = m.at("banana"); // Throws exception if key doesn't exist

// Removing elements
m.erase("apple");        // Remove by key
m.erase(m.begin());      // Remove by iterator
m.clear();               // Remove all elements

// Finding elements
auto it = m.find("banana"); // Returns iterator to pair, or m.end() if not found
bool exists = m.count("banana"); // Returns 1 if exists, 0 otherwise

// Properties
cout << m.size();        // Number of key-value pairs
cout << m.empty();       // Check if empty

// Iteration (sorted by key)
for (auto& [key, value] : m) {
    cout << key << ": " << value << "\n";
}

// Alternative iteration
for (auto it = m.begin(); it != m.end(); ++it) {
    cout << it->first << ": " << it->second << "\n";
}

// Multimap (allows duplicate keys)
multimap<string, int> mm;
mm.insert({"fruit", 1});
mm.insert({"fruit", 2}); // Both pairs exist
```

**Use Case**: Dictionary-like operations, counting occurrences, caching.

## Unordered Containers (Hash-based)

### Unordered Set
```cpp
#include <unordered_set>

unordered_set<int> us{1, 2, 3, 4, 5};
us.insert(6);            // Average O(1) insertion
auto it = us.find(3);    // Average O(1) lookup
```

### Unordered Map
```cpp
#include <unordered_map>

unordered_map<string, int> um;
um["key"] = 100;         // Average O(1) insertion/access
auto it = um.find("key"); // Average O(1) lookup
```

## Common STL Algorithms

```cpp
#include <algorithm>
#include <numeric> // For accumulate
#include <vector>
#include <iostream>
using namespace std;

vector<int> v{3, 1, 4, 1, 5, 9, 2, 6};

// Sorting
sort(v.begin(), v.end());              // Ascending order
sort(v.begin(), v.end(), greater<int>()); // Descending order

// Reverse
reverse(v.begin(), v.end());           // Reverse the vector

// Find
auto it = find(v.begin(), v.end(), 5); // Find value 5
if (it != v.end()) cout << "Found 5 at index " << distance(v.begin(), it) << endl;

// Count
int cnt = count(v.begin(), v.end(), 1); // Count occurrences of 1

// Accumulate (sum)
int sum = accumulate(v.begin(), v.end(), 0); // Sum of all elements

// Unique (remove consecutive duplicates)
auto last = unique(v.begin(), v.end());
v.erase(last, v.end());

// Rotate
rotate(v.begin(), v.begin() + 2, v.end()); // Rotate left by 2 positions

// Partition (separate even and odd)
auto part = partition(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
// Now evens are before part, odds after

// Lower/Upper Bound (on sorted vector)
sort(v.begin(), v.end());
auto lb = lower_bound(v.begin(), v.end(), 4); // First >= 4
auto ub = upper_bound(v.begin(), v.end(), 4); // First > 4

// Next/Prev Permutation
next_permutation(v.begin(), v.end()); // Next lexicographical permutation
prev_permutation(v.begin(), v.end()); // Previous permutation

// Min/Max Element
auto min_it = min_element(v.begin(), v.end());
auto max_it = max_element(v.begin(), v.end());

// All_of, any_of, none_of
bool all_pos = all_of(v.begin(), v.end(), [](int x){ return x > 0; });
bool any_even = any_of(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
bool none_neg = none_of(v.begin(), v.end(), [](int x){ return x < 0; });

// For_each
for_each(v.begin(), v.end(), [](int &x){ x *= 2; }); // Double each element

// Copy
vector<int> v2(8);
copy(v.begin(), v.end(), v2.begin());

// Fill
fill(v2.begin(), v2.end(), 7); // Fill all with 7

// Remove (erase-remove idiom)
v.erase(remove(v.begin(), v.end(), 1), v.end()); // Remove all 1s
```

## Time Complexities Summary

| Container | Access | Insert | Delete | Search |
|-----------|--------|--------|--------|--------|
| **Array** | O(1) | N/A | N/A | O(n) |
| **Vector** | O(1) | O(1) amortized | O(n) | O(n) |
| **Deque** | O(1) | O(1) ends | O(n) middle | O(n) |
| **List** | O(n) | O(1) | O(1) | O(n) |
| **Stack** | O(1) top | O(1) | O(1) | N/A |
| **Queue** | O(1) front/back | O(1) | O(1) | N/A |
| **Priority Queue** | O(1) top | O(log n) | O(log n) | N/A |
| **Set** | N/A | O(log n) | O(log n) | O(log n) |
| **Map** | O(log n) | O(log n) | O(log n) | O(log n) |
| **Unordered Set** | N/A | O(1) avg | O(1) avg | O(1) avg |
| **Unordered Map** | O(1) avg | O(1) avg | O(1) avg | O(1) avg |

## Choosing the Right Container

### Use **Vector** when:
- You need dynamic array with random access
- Frequent access to elements by index
- Memory efficiency is important

### Use **Deque** when:
- You need fast insertion/deletion at both ends
- Random access is required

### Use **List** when:
- Frequent insertion/deletion in the middle
- Random access not required

### Use **Stack** when:
- LIFO behavior needed
- Function call management, undo operations

### Use **Queue** when:
- FIFO behavior needed
- BFS, process scheduling

### Use **Priority Queue** when:
- Need elements in priority order
- Dijkstra's algorithm, task scheduling

### Use **Set** when:
- Need unique, sorted elements
- Fast lookup and sorted iteration

### Use **Map** when:
- Need key-value associations
- Keys should be sorted

### Use **Unordered Set/Map** when:
- Fast lookup more important than order
- Hash-based operations preferred

## Memory Tips
- **Vector**: Dynamic array, reallocates when capacity exceeded
- **Deque**: Double-ended queue, fast at both ends
- **List**: Linked list, no random access but fast insertion anywhere
- **Stack**: LIFO - Last In, First Out
- **Queue**: FIFO - First In, First Out
- **Priority Queue**: Always gives highest priority element
- **Set**: Unique + Sorted automatically
- **Map**: Key-Value pairs, sorted by key
- **Unordered**: Hash-based, faster but no order guarantee