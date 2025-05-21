# Push_swap

**Push_swap** is a sorting algorithm project developed as part of the 42 curriculum. The goal of this project is to implement a series of stack operations to sort a list of integers. The project tests your ability to design and implement algorithms efficiently using only basic operations, while working with stacks to manipulate data.

---

## 🧩 Project Description

The **Push_swap** project involves sorting a series of numbers using two stacks, `a` and `b`. The objective is to sort the numbers in ascending order, with the least number of operations possible.

You are required to implement the following stack operations:
- **sa**: Swap the first two elements of stack `a`.
- **sb**: Swap the first two elements of stack `b`.
- **ss**: Perform `sa` and `sb` simultaneously.
- **pa**: Push the first element of stack `b` to stack `a`.
- **pb**: Push the first element of stack `a` to stack `b`.
- **ra**: Rotate stack `a` (move the first element of stack `a` to the bottom).
- **rb**: Rotate stack `b` (move the first element of stack `b` to the bottom).
- **rr**: Perform `ra` and `rb` simultaneously.
- **rra**: Reverse rotate stack `a` (move the last element of stack `a` to the top).
- **rrb**: Reverse rotate stack `b` (move the last element of stack `b` to the top).
- **rrr**: Perform `rra` and `rrb` simultaneously.

The goal is to sort the stack in as few moves as possible while respecting the constraints outlined in the project.

---

## 🚀 Features

- **Efficient Sorting Algorithm**: You will implement a sorting algorithm that minimizes the number of operations to sort the list of integers using the operations mentioned above.
- **Two Stacks**: You will be working with two stacks (`a` and `b`) and performing operations to move the elements between them.
- **Performance**: The solution must be optimized to handle a variety of inputs, from small to large lists, while minimizing the number of operations.

---

## 🔧 Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/srapaila/push_swap.git
    cd push_swap
    ```

2. Compile the project:

    ```bash
    make
    ```

3. Run the program with a list of integers:

    ```bash
    ./push_swap 5 2 1 4 3
    ```

    This will output the series of operations needed to sort the numbers in ascending order.

---

## 🧪 Example

Here’s an example of how to run the program with a series of unsorted numbers:

```bash
./push_swap 3 5 1 4 2
