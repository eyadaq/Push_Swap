# ♻️ Push Swap
  ![push-swapm](push_swapm.png)
  
## 📌 Table of Contents
- [Introduction](#introduction)
- [Project Objectives](#project-objectives)
- [Allowed Instructions](#allowed-instructions)
- [Constraints](#constraints)
- [Algorithm Used](#algorithm-used)
- [Compilation](#compilation)
- [Usage](#usage)
- [Examples](#examples)
- [Implementation Overview](#implementation-overview)
- [Resources](#resources)

---

## 🧩 Introduction

**Push Swap** is a project at 42 school that challenges you to sort a stack of integers using **two stacks (A and B)** and a limited set of operations, with the goal of using as few instructions as possible.  
The program outputs the list of instructions that sort the initial stack.

---

## 🎯 Project Objectives

- Parse and validate input arguments.
- Manipulate two stacks using a defined set of operations.
- Implement a sorting algorithm optimized for minimal moves.
- Output the sorting instructions to standard output.

---

## 🔧 Allowed Instructions

| Operation | Description                        |
|----------|------------------------------------|
| `sa`     | Swap the first two elements of A    |
| `sb`     | Swap the first two elements of B    |
| `ss`     | `sa` and `sb` at the same time      |
| `pa`     | Push the first element of B to A    |
| `pb`     | Push the first element of A to B    |
| `ra`     | Rotate A upward                     |
| `rb`     | Rotate B upward                     |
| `rr`     | `ra` and `rb` at the same time      |
| `rra`    | Reverse rotate A                    |
| `rrb`    | Reverse rotate B                    |
| `rrr`    | `rra` and `rrb` at the same time    |

---

## ❗ Constraints

- You may only use the operations listed above.
- You cannot use any standard library sort function.
- Input must be validated (integers, no duplicates, within `int` range).
- The goal is to **minimize the number of operations**.

---

## 🧠 Algorithm Used – Turk’s Greedy Algorithm

The Turk algorithm is a smart greedy method that works in two main phases:

1. **Push to Stack B**:
   - Send all non-extreme values to stack B using `pb`.
   - Keep only 2-3 elements in A.

2. **Greedy Insertion**:
   - For each element in B, calculate the cheapest move to insert it into its correct position in A.
   - Use a combination of `ra`, `rb`, `rra`, `rrb`, and their doubles (`rr`, `rrr`) to minimize rotations.

3. **Final Rotate**:
   - Once B is empty, rotate A until the smallest element is on top using `ra`/`rra`.

This approach is highly efficient and usually produces a low number of operations without needing full brute-force sorting.

---

## 🛠 Compilation

```bash
make
````

Other targets:

```bash
make clean     # Remove object files
make fclean    # Remove object files and executable
make re        # Rebuild everything
```

---

## 🚀 Usage

```bash
./push_swap <list of integers>
```

Example:

```bash
./push_swap 3 2 5 1 4
```

Output:

```
pb
pb
sa
pa
pa
ra
```

You can test your result with the provided checker:

```bash
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker $ARG
```

---

## 💡 Examples

```bash
./push_swap 5 2 3 1 4
./push_swap 2 1 3
./push_swap 8 4 2 6 1 9 0
```

---

## 📚 Resources

* 42 Docs: [https://harm-smits.github.io/42docs/projects/push\_swap](https://harm-smits.github.io/42docs/projects/push_swap)
* [The Turk Algorithm – Explained](https://medium.com/@ilkleyn/push_swap-algorithm-turk-solution-explained-2c9e60a88a5c)
* man pages: `man atoi`, `man write`, `man malloc`, `man free`

---

> 🧠 Project developed as part of the 42 Network. Focuses on algorithmic thinking, data structures, and optimization.

