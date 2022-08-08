# README

Given a certain number of GENERATIONS, inheritance.c creates a family tree for person p where 'person' is a struct with two blood-type alleles (either A, B, or O) and two parents, each of which is a also a person struct (our first instance of recursion) with two alleles and two more parents. This module is a great example of repeatedly using recursion in different helper functions to drive the main code.

Upon execution inheritance.c prompts the user to enter a number of generations. If the user does not enter an integer, an error message appears and exits the program. For simplicity's sake this walkthrough will account for 3 generations, couting person p.

After allocating memory for person p, inheritance.c calls create_family() recursively to create a family tree of persons by running through p's first parent, and then that parent's first parent. When it hits this last generation the base case kicks in: the grandparent's parent properties are pointed to NULL and a random number generator is used to assign blood-type alleles to each grandparent. Then a second random number is generated and modulated by 2 to randomly pass an allele from each grandparent to the first parent.

This entire process is repeated for the second parent and the second parent's parents. The result is that two alleles are ultimately passed to person p which are based on the alleles of p's ancestors but which also account for the real-life randomness of the inheritance.

The module then recursively prints each person's alleles in the family tree before using recursion one last time to free all the memory allocated in this process.

#### EXAMPLE INPUT

- ./inheritance.c
- Number of generations? 3

#### EXAMPLE OUTPUT

- Generation 0, blood type OO
  - Generation 1, blood type BO
    - Generation 2, blood type BB
    - Generation 2, blood type OO
  - Generation 1, blood type BO
    - Generation 2, blood type AB
    - Generation 2, blood type AO
