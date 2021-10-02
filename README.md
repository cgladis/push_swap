# push_swap
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

The Push_swap project is a very simple and highly effective algorithm project: data will
need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of
instructions to manipulate both stacks.

# Game rules

- The game is composed of 2 stacks named a and b.
- To start with:
  - a contains a random number of either positive or negative numbers without
  any duplicates.
  - b is empty
- The goal is to sort in ascending order numbers into stack a.
- To do this you have the following operations at your disposal:
  - `sa` : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
  is only one or no elements).
  - `sb` : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
  is only one or no elements).
  - `ss` : sa and sb at the same time.
  - `pa` : push a - take the first element at the top of b and put it at the top of a. Do
  nothing if b is empty.
  - `pb` : push b - take the first element at the top of a and put it at the top of b. Do
  nothing if a is empty.
  - `ra` : rotate a - shift up all elements of stack a by 1. The first element becomes
  the last one.
  - `rb` : rotate b - shift up all elements of stack b by 1. The first element becomes
  the last one.
  - `rr` : ra and rb at the same time.
  - `rra` : reverse rotate a - shift down all elements of stack a by 1. The last element
  becomes the first one.
  - `rrb` : reverse rotate b - shift down all elements of stack b by 1. The last element
  becomes the first one.
  - `rrr` : rra and rrb at the same time.
- The program must display the smallest list of instructions possible to sort the stack
  a, the smallest number being at the top.
- Instructions must be separaed by a ’\n’ and nothing else.
- The goal is to sort the stack with the minimum possible number of operations.
- In case of error, you must display Error followed by a ’\n’ on the standard error.
  Errors include for example: some arguments aren’t integers, some arguments are
  bigger than an integer, and/or there are duplicates.

# Installation
Clone repository and then go into the created directory and run the following command:
```
make bonus
```
# How to run program?
for example:
```
./push_swap 1 3 5 4 2
```
or
```
make run TEST_STACK="1 3 5 4 2"
```
###result:

![image](https://user-images.githubusercontent.com/69306932/135731419-0a0df9c1-eef3-485c-bb19-a7f6fb913375.png)

# How to check program result?
for example:
```
./push_swap 1 3 5 4 2 | ./checker 1 3 5 4 2
```
or
```
make test TEST_STACK="1 3 5 4 2"
```
###result:

![image](https://user-images.githubusercontent.com/69306932/135731444-afb399a8-72d1-4026-8a82-44d5f101cdc2.png)

# How to run python checker?
```
make check
```
###result:

![image](https://user-images.githubusercontent.com/69306932/135731466-e9397750-0466-4580-be58-0802cebc0b7f.png)

# also try
```
make re run PRINT_CHECK=1 PRINT_ALL=1 TEST_STACK="1 3 5 4 2"
```

###result:

![image](https://user-images.githubusercontent.com/69306932/135731691-e2c1a137-88f8-41ff-a9eb-bc634662678b.png)

# Project evaluation

![image](https://user-images.githubusercontent.com/69306932/135732013-2fe020fd-dcef-4629-ad2d-25e504201331.png)

