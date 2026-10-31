### Problem A: Delete nodes from a linked list

Time limit: 3 s · Memory limit: 256 MB

**Algorithm:** singly linked list, deleting nodes.

You are given a linked list of integers and a number x. Delete from the list all nodes whose value equals x and print the remaining list.

Store the numbers in a linked list (a chain of nodes where each node keeps a value and a pointer to the next node).

### Input format

The first line contains an integer n.

The second line contains n integers — the list from head to tail.

The third line contains an integer x. It is guaranteed that at least one element of the list is not equal to x.

### Output format

Print the remaining numbers in their order, separated by spaces.

### Examples

#### Input

```
6
1 2 3 2 4 2
2
```

#### Output

```
1 3 4
```

#### Input

```
3
5 6 7
9
```

#### Output

```
5 6 7
```

### Notes

In the second example 9 does not occur in the list, so the list does not change.
