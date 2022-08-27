# Algorithms and Data Structures 

This repository is an implementation of data structures written in C.

I do not attempt to make a canonical list of all different code variations or 
implementations. This repo provides the basic requirements to understand and implement these data structures using the C programming language.

The inspiration for this repo was acquired through my 2nd year University courses in "Algorithms and data structures" which were more theorical:

Because of this, I decided to re-implement the data structures using a low level language: C with Code::Blocks IDE.

Basic outline of the different data structure and algorithms

All other information acquired and code implemented is my own.

- [LinkedList](#linkedlist)
- [Stack](#stack)
- [Queue](#queue)
- [Hash Table](#hash-table)
- [Set](#set)
- [Tree](#tree)

## LinkedList

> A Linked-list is a linear collection of "nodes" of elements,  
where the elements are accessed via looping through the entire list searching for the element of interest as opposed to Array where elements can be accessed by indices,  
which are usually integers used to compute offsets

[Code](Structures.h#l31)

A List is a simple collection of elements, which is different from an Array in 
that the elements within the List can only be accessed by looping through the 
entire list searching for the element of interest.

Different types of list are implemented there :

- [simple linked-list](Structures.h#L31)
- [circular simple linked-list](Structures.h#L55)
- [double linked-list](Structures.h#L110)
- [circular double linked-list](Structures.h#L111)


> Note: the following API is based on the "singly" Linked List

When inserting items, for performance, new items are inserted before the node at the head

### API

- `insert` (prepend new element or insert new element at specified index)
- `remove` (remove element at specified index)
- `clear` (remove all elements from the list, leaving an empty list)
- `next` (move to next item in the list)
- `move_to` (move to specified index)
- `position` (returns the current index position)
- `get` (returns the element at the specified index)
- `front` (change index position to be the starting position)
- `end` (change index position to be the ending position)
- `next?` (returns Boolean value checking if a next index exists)

### Properties

- Sequential/Ordered (i.e. consistent element ordering based on collection population)
- Duplicates allowed

#### Pros

- Inserting/deleting elements at the beginning of the Array (due to sequential iteration access)
- Better at inserting/deleting elements in the middle of the Array (although still requires search time)
- Useful if the order of your data doesn't matter (if it does then a Stack might be preferrable)
- Useful if you don't need to search your data in a performant manner

#### Cons

- Slower lookups (due to sequential iteration access, rather than having direct index access)
- Inserting/deleting elements at the end of the Array (due to sequential iteration access)
- Long searches or complex sorting can be a performance concern

---

## Stack

> A stack is a list of elements that are accessible only  
from one end of the list, which is called the `top`  
For example, the stack of trays at a cafeteria.  
Trays are always removed from the top,  
and when trays are put back on the stack after being washed,  
they are placed on the top of the stack

[Code](Structures.h#L69)

Because this data structure is LIFO (Last In, First Out) it means that you can 
only ever access the element that is on the top of the stack. If you want to 
access an element further down the stack then you'll need to remove the elements 
that currently sit above it.

### API

- `pop` (remove top element)
- `push` (append new element)
- `peek` (return the top element but don't `pop` it from the Stack)
- `clear` (remove all elements from the Stack, leaving an empty Stack)

### Properties

- Sequential/Ordered (i.e. consistent element ordering based on collection population)
- LIFO (Last In, First Out)

### Usefulness

- Useful when the order of your data matters
- Useful for searching the collection for specific data
- Fast (as Stacks only allows `push` and `pop` functionality)
- Used a lot in underlying language implementations (e.g. expression evaluation and handling function calls)

---

## Queue

> A queue is a type of list where data is  
inserted at the end and is removed from the front.  
Queues are used to store data in  
the order in which they occur, as opposed to a stack,  
in which the last piece of data entered  
is the first element used for processing

> Think of a queue like the line at your bank,  
where the first person into the line  
is the first person served,  
and as more customers enter a line,  
they wait in the back until it is their turn to be served

[Code](Structures.h#L90)

### API

- `enqueue` (append new element)
- `dequeue` (remove first element)
- `peek` (return the first element but don't `dequeue` it from the Queue)
- `clear` (remove all elements from the Queue, leaving an empty Queue)

### Properties

- Sequential/Ordered (i.e. consistent element ordering based on collection population)
- FIFO (First In, First Out)

### Usefulness

- Processing data that needs to be handled in a sequential order
- Can be useful for sorting data (depending on the sort)

### Notes

There are some situations where a Queue needs to be processed not in a FIFO 
sequence. This scenario is known as a "Priority Queue" and it works like this: 
elements are removed from the the Queue based on a priority *constraint*.

The way this would be implemented is by instead of storing raw data inside the 
Queue you would store Objects that contain the data along with a priority field. 
We would then redefined our `dequeue` method to loop through the Queue looking 
for the element with the highest priority and to process that. By nature of the 
basic implementation if we have multiple objects with the same priority then we
still continue to process elements on a FIFO basis (as we start looping from the 
start of the Queue).

---

## Hash Table

[Code](Structures.h#L112)

A Hash Table is fundamentally an Dictionary data structure. The keys for the 
Dictionary are determined by a function that creates a hash of the key's 
associated data.

> Note: the hash algorithm can be anything you like  
the [hachage](Structures.c#L459) function defined below I just made up  
as it created a seemingly varied index based on each  
character byte from my data

Data | Hash Algorithm    | Hash Value
---- | ----------------- | ----------
Mark | `hachage("Mark")` | 395
John | `hachage("John")` | 399
Katy | `hachage("Katy")` | 409
kraM | `hachage("kraM")` | 395

```C
int hachage(TableH t, char *ch)
{
    return ((Xor(ch) + Or(ch) + strlen(ch)) % t.taille);
}
```
### What data structure *should* I use?

For the purposes of the implementation code in this repo I've decided to use an 
Array and to make sure that, regardless of the data, my hashing algorithm generates 
a numerical value.

The reason for this is simply because the work around for collisions are centered 
around the data structure being an Array.

### Hashing algorithm

It's probably easier if I just quote from the book here:

> The choice of a hash function depends on the data type of the key.  
If your key is an integer, then the simplest hash function is  
to return the key modulo the size of the array.  
There are circumstances when this function is not recommended,  
such as when the keys all end in 0 and the array size is 10.  
This is one reason the array size should always be a prime number,  
such as 137

> Also, if the keys are random integers,  
then the hash function should more evenly distribute the keys.  
This type of hashing is known as modular hashing

> To avoid collisions, you first need to make sure the array  
you are using for the hash table is sized to a prime number.  
This is necessary due to the use of modular arithmetic in  
computing the key.  
The size of the array needs to be greater than 100 in order  
to more evenly disperse the keys in the table.  

In the above quote, they state they're using "modular arithmetic" for their 
algorithm. This means that the size of your Array data structure  will depend 
slightly on the hashing algorithm results and can only be decided upon after 
some experimentation.

### Hashing collisions

There are two popular techniques for resolving hashing collisions:

1. Separate Chaining
2. Linear Probing

#### Separate Chaining

Effectively our keys will hold a sub data structure and we use need a technique 
for storing our data into the sub array, allowing us to store the same hashed 
value key in the top level Dictionary.

The sub data structure you use could be another Dictionary or an Array, it depends 
on the technique you plan on using for storing the data within the sub data structure.

#### Linear Probing

This technique dictates that when a collision is found, the Hash Table will check 
to see if the next available index is empty and if so it'll place the data into 
that next index.

The idea behind this technique is that because Hash Table keys are generally quite 
distributed (e.g. they're rarely sequential 0, 1, 2, 3, 4) it's likely that you'll 
have many empty empty elements and you can use that empty space to store your 
colliding data. 

> Note: Linear Probing is suggested over Separate Chaining  
if your data structure is expected to be quite large

Personally I don't like the idea of the Linear Probing technique as it feels like 
it'll introduce more complexity and bugs. Also, there is a problem with this 
technique which is that it relies on the top level data structure being an Array. 
Which is fine if the key we're constructing is numerical, but if you want to have 
Strings for your keys then that wont work very well and so you'll need to be clever 
with how you implement this using a Dictionary.

### API

- `creerTableH` (allocates memory for a Hashtable)
- `put` (takes "data" and passes it to our hashing function, then assigns the result to the Dictionary, returning the generated key)
- `get` (takes the hash value our data was assigned to and retrieves the data from the Dictionary)
- `print` (returns a custom display of our Hashtable

---

## Tree

>A Tree data structure is used to store hierarchical data (it is non-linear), 
such as an Operating System file system.

>A Tree contains "nodes" (a node has a value associated with it) and each node is connected by a line called an "edge". These lines represent the relationship 
between the nodes.

>The top level node is known as the "root" and a node with no children is a "leaf".

>If a node is connected to other nodes, then the preceeding node is referred to 
as the "parent" and nodes following it are "child" nodes.

### Binary Trees
[Code](Structures.h#L150)

There is a specific type of tree referred to as a "Binary Tree", which restricts 
its child nodes to no more than two.

The children of a node are referred to as the "left" node and the "right" node.

When creating a Binary Tree object you'll pass in the first node to become the 
root node and each node is itself an object with an associated value, along with 
a left and right node linked to.

### Binary Search Trees
[Code](Structures.h#L165)

There is another type of tree called a "Binary Search Tree" and this is an 
extension of the Binary Tree, with the addition that the child nodes are stored 
in a specific order depending on a custom calculation.

The calculation is very simple: if a node has a lesser value than its parent it 
is placed in the "left" node position. If on the other hand it has a greater value 
than its parent it is placed in the "right" node position.

### Binary HEAPs
[Code](Structures.h#L179)

Heap data structure is a complete binary tree that satisfies the heap property, where any given node is

- always greater than its child node/s and the key of the root node is the largest among all other nodes. This property is also called max heap property.

- always smaller than the child node/s and the key of the root node is the smallest among all other nodes. This property is also called min heap property.

### API

- `pushNode` (adds new node to the tree; which can require traversal of the tree)
- `estDeRecherche` (traversal method: to recursively check if the tree is a search one),
- `affichePrefixe` (traversal method: same as `estDeRecherche` but prints the current node *after* checking the left/right child nodes)
- `show` (display the current node's value)
- `clearTree` (free the memory allocated for a tree)

> Note: traversal methods rely on recursion  
and need to be carefully implemented to ensure  
they do not cause a Stack Overflow error

#### * `estDeRecherche` *

The `estDeRecherche` function would theorectically look something like [Code](Structures.c#L622):

```C
int estDeRecherche(Arbre a)
{
    if (a == NULL)
        return 1;
    if (a->fg != NULL)
        return (a->value > a->fg->value) ? 1 : 0;
    if (a->fd != NULL)
        return (a->value < a->fd->value) ? 1 : 0;
    return (estDeRecherche(a->fg)) && (estDeRecherche(a->fd));
}
```
Now imagine we have the following Binary Search Tree structure:

```
     23     <-- tree (the head pointer)
     |
   -------
   |     |
  16     45
  |      |
 ----   ----
 |  |   |  |
03  22  37 99
```

If we executed `estDeRecherche(tree)` we would see the following output:

`1` which stand for `TRUE`: it means the tree is a binary search tree.

If we replace 22 with 24, it will return `0`.


### Properties
- No direct access to nodes (start from the head/root and navigate down)

### Usefulness
- Quick to search
- Quick insertion/deletion