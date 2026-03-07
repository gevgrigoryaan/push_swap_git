*This project has been created as part of the 42 curriculum by gegrigor, rafhovha.*

# push_swap

## Description

**push_swap** is a program that sorts a list of integers using two stacks and a limited
set of operations. The objective is to produce the **smallest possible number of operations**
to sort the stack in ascending order.

The program receives integers as command-line arguments, validates them, stores them
in a stack structure, and then sorts them using different algorithms depending on
the size of the input and the disorder of the stack.

The project focuses on:
- algorithm design
- complexity analysis
- stack manipulation
- optimization of operations

Two stacks are used:

- **Stack A** – contains the initial numbers
- **Stack B** – used as auxiliary storage during sorting

The allowed operations manipulate these stacks in order to gradually transform
Stack A into a sorted stack.

---

# Instructions

## Compilation

Compile the program using:

```
make
```

This will generate the executable:

```
push_swap
```

---

## Execution

Run the program by providing integers as arguments:

```
./push_swap 3 2 5 1 4
```

The program outputs a sequence of operations such as:

```
pb
sa
ra
pa
```

Each instruction represents an operation applied to the stacks.

---

## Error Handling

The program prints:

```
Error
```

if:

- an argument is not a valid integer
- an integer exceeds the INT range
- duplicate numbers are provided
- invalid formatting is detected

---

# Program Workflow

### 1. Argument Processing

All command-line arguments are first joined into **a single string**.
After that the string is **split** to obtain a `char **` containing all numbers.

### 2. Flag Detection

The first two arguments are checked to determine whether they are **flags**.
Flags can modify the program behavior (for example selecting a sorting strategy).

### 3. Validation

Each argument is validated to ensure:

- it is a valid integer
- it fits within the integer limits
- there are **no duplicate values**

### 4. Stack Initialization

After validation, numbers are converted using `atoi` and inserted into a
custom stack structure (`t_stack`).

During insertion duplicate checks are also performed.

---

# Algorithms

Different algorithms are used depending on the **stack size** and **disorder level**.

## Small Stack Sorting

For very small stacks we implemented **hardcoded solutions** that produce the
minimum number of operations.

### Size 2
If the two numbers are not ordered, a single swap operation is performed.

### Size 3
A small set of conditional checks is used to produce the optimal sequence
of operations.

### Size 5
Elements are temporarily pushed to stack **B**, the remaining elements are
sorted, and then values are pushed back in the correct order.

These approaches guarantee the **minimal operation count** for small inputs.

---

## Radix Binary Sort

For larger stacks we implemented **binary radix sort**.

### Idea

1. Each number is assigned an **index** based on its sorted position.
2. The algorithm processes numbers **bit by bit** starting from the least
   significant bit.
3. Depending on the current bit value:
   - numbers are rotated in stack A
   - or pushed to stack B
4. Elements are then pushed back to stack A.

### Why Radix Sort

Radix sort provides:

- predictable performance
- good scaling with large inputs
- efficient use of stack operations

Its time complexity is approximately:

```
O(n * log n)
```

when considering bit operations.

---

## Bubble Chunk Strategy

Another strategy used is **chunk-based sorting**.

### Idea

1. The stack is divided into **chunks (ranges of numbers)**.
2. Numbers belonging to the current chunk are pushed to stack **B**.
3. Elements are then pushed back to **A** in descending order.

### Advantages

- reduces unnecessary rotations
- improves operation efficiency for medium-sized inputs
- balances stack usage

---

# Stack Operations

The program uses the following operations:

| Operation | Description |
|--------|-------------|
| sa | swap the first two elements of stack A |
| sb | swap the first two elements of stack B |
| ss | sa and sb |
| pa | push the top of B to A |
| pb | push the top of A to B |
| ra | rotate stack A |
| rb | rotate stack B |
| rr | ra and rb |
| rra | reverse rotate A |
| rrb | reverse rotate B |
| rrr | rra and rrb |

---

# Resources

The following resources were used while developing the project:

### Documentation

- The official **42 push_swap subject**
- Stack data structure documentation
- Algorithm complexity references (Big-O notation)

### Algorithm References

- Radix Sort explanation  
  https://en.wikipedia.org/wiki/Radix_sort

- Sorting algorithm complexity comparison  
  https://www.bigocheatsheet.com

### AI Usage

AI tools were used during development for:

- understanding algorithm theory
- reviewing documentation explanations
- improving README formatting and clarity

AI was **not used to generate the core sorting algorithms or program logic**.
All implementation decisions and code were written by the project authors.

---

# Authors

- gegrigor
- rafhovha