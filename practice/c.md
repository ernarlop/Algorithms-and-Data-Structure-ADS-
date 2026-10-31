### Problem C: Lomuto partition

Time limit: 3 s · Memory limit: 256 MB

**Algorithm:** quick sort, partition procedure (Lomuto).

Quick sort is based on the partition procedure. Perform exactly one partition of the array a[1..n] using the following scheme (Lomuto partition), and print the array after it:

1. the pivot is the last element: pivot = a[n]; set i = 0;
2. for j = 1, 2, …, n − 1: if a[j] < pivot, increase i by one and swap a[i] and a[j];
3. finally swap a[i + 1] and a[n].

After this step the pivot stands at position i + 1, all elements to its left are smaller than it, and all elements to its right are not smaller.

### Input format

The first line contains an integer n.

The second line contains n integers.

### Output format

Print the numbers of the array after the partition, separated by spaces.

### Examples

#### Input

```
6
3 8 1 9 2 4
```

#### Output

```
3 1 2 4 8 9
```

#### Input

```
4
5 6 7 1
```

#### Output

```
1 6 7 5
```

### Notes

In the first example the pivot is 4. The elements 3, 1, 2 are smaller than 4 and move to the front in their order; then the pivot is swapped with a[4], which gives 3 1 2 4 8 9.
