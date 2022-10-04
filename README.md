Generic Doubly Linked List 
=================

\anchor generic-linked-list

A doubly linked list implementation in C. The list stores (void) pointers to the data. The actual data is never copied, modified or deleted in this implementation. This allows for the same data to be stored in multiple different lists.

### Features
* Fast Stack operations (push/pop)
* Fast Queue operations (pushBack/pop)
* Fast Deque operations (push/pushBack and pop/popBack)
* Forward/Backward iteration with function parameter

### Performance

| Function | Running Time |
|---|---|
|gll_get / gll_set | O(1 + min{size-i, i} ) |
|gll_first / gll_last | O(1) |
|gll_add | O(1 + min{size-i, i} ) |
|gll_pop / gll_popBack| O(1) |
|gll_push / gll_pushBack| O(1) |
_ _ _

###### Performance Test

```
Number of Nodes: 10000000

  gll_pushBack() (All):        1016.8580 ms
  gll_popBack() (All):          803.8800 ms
  gll_push() (All):             655.6550 ms
  gll_pop() (All):              793.6100 ms

  gll_pushBack() (All):         660.2480 ms

  1 * gll_get() (middle):        55.3450 ms
  1 * gll_get() (end):            0.0030 ms
  1 * gll_get() (begin):          0.0010 ms

  1 * gll_set() (middle):        56.5100 ms
  1 * gll_set() (end):            0.0010 ms
  1 * gll_set() (begin):          0.0010 ms

  1 * gll_add() (middle):        54.9220 ms
  1 * gll_add() (end):            0.0040 ms
  1 * gll_add() (begin):          0.0020 ms

  1 * gll_remove() (middle):     55.1510 ms
  1 * gll_remove() (end):         0.0030 ms
  1 * gll_remove() (begin):       0.0010 ms

  gll_each():                   122.4990 ms
  gll_eachReverse():            123.8290 ms

```

### Usage
###### Library

```
add_subdirectory(<this_dir>)
```
OR
```
FetchContent_Declare(
    generic-linked-list
    GIT_REPOSITORY https://github.com/BCadet/generic-linked-list.git
    GIT_TAG master
)
FetchContent_MakeAvailable(generic-linked-list)
```

###### Tests
```
make gll-tests
./gll-tests
```

###### Performance Tests
```
make gll-performance-test
./gll-performance-test
./gll-performance-test [number of nodes]
```
