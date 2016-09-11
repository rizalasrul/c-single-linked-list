# Single Linked List, What Is It?
Single linked list or so-called linked list consists of individual elements, which each connected to a single pointer. Each element consists of two parts, the data/information stored and the pointer section called pointer *next*. By using the two-member structure like this, linked list formed by next pointer from one element to follow. Next to the last pointer is NULL, which indicates the end of a list. The element at the beginning of a list called the *head*, and the last element of a list called the *tail*.

This image below is the illustrate of single linked list with relational elements

![Image of Diagram](https://github.com/rizalasrul/c-single-linked-list/blob/master/Images/1.png)

Conceptually, a linked list is a row of adjoining elements. However, because such elements are allocated dynamically (using malloc), it is important to remember that fact, linked list will be scattered like a memory location in image below. Pointer of the element to the mean as a guarantor that all the elements are accessible.

![Image of Diagram](https://github.com/rizalasrul/c-single-linked-list/blob/master/Images/2.png)

In C, this is the representation node syntac for data structure
```c
struct node{
	int data;
	struct node *next;
};

typedef struct node Node;
```
From the syntax above, `node` include:
* `data` information.
* `next` pointer that refer to `node` object.

# How This Code Work
## prog1.c
will be updated soon
## prog2.c
will be updated soon
