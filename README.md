# cs260_project7

## Hash Table

### ▼ Implemente Hash Table
- Hash table has hash values, and a linked list attatched based on one hash value (chaining method).
- Each hash in a linked list has a unique key and a nonunique value.
- We have to add a new hashtable element assigning a hash value, a key, and a value.
- A new hashtable element is added to the end of a linked list.
- In adding, if a given key already exists, its value is replaced with a new value.
- We have to search a hashtable element from a hash value and a key.

### ▼ Tests
Whether it's possible to...
1. **Addition of elements**
    - insert a new element expectedly in a chaining way
    - override a value of an already existing key
2. **Checking if a target element is contained**
    - search for a specific element based on its key and a hash value it belongs to

### ▼ Complexity (Big-O notation)
|Insert|Search|
|:--:|:--:|
| O(1) | O(1) |
