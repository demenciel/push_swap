# Push Swap Project

This is the Push Swap project for the 42 school curriculum. The goal of the project is to create a program that sorts a stack of integers using only two stacks and a limited set of operations.

## How to Run

To have a better experience with the program, there is a visualizer of the program in action. The visualizer will build itself with the make command if you have "cmake" installed on your computer.
To compile the program, run the following command in the root directory of the project:

### Usage
```bash
make
```
To run the program, execute the following command:

```bash
./push_swap nb1 nb2 nb3 ...
```

To run the visualizer, execute the following command:

```bash
cd push_swap_visualizer/build | ./bin/visualizer
```

## Commands
- _pa_ : push top element of stack b -> stack a
- _pb_ : push top element of stack a -> stack b
- _sa_ : swap the first two elements of stack a
- _sb_ : swap the first two elements of stack b
- _ra_ : switch the first element of stack a to the last position
- _rb_ : switch the first element of stack b to the last position
- _rra_ : switch the last element of stack a to the top position
- _rrb_ : switch the last element of stack b to the top position

There are more commands permitted I could have used but I didn't.

## Algorithm Details
The sorting algorithm implemented in this program uses a combination of quicksort, insertion sort, and a custom sorting algorithm designed for sorting a large number of integers efficiently and only using specifics commands.

The program first checks if the input array is already sorted. If it is, the program terminates. Otherwise, the program sorts the array using quicksort until the array is divided into several sub-arrays of 5 or fewer integers. Then, the program sorts each sub-array using insertion sort. Finally, the program uses the custom sorting algorithm to sort the entire array.

The custom sorting algorithm uses a variation of the median of medians algorithm to partition the array into several blocks of roughly equal size. The program then sorts each block using quicksort and combines the blocks using a modified merge sort algorithm.

## Contributors

- [Alexandre Couture](https://github.com/demenciel)