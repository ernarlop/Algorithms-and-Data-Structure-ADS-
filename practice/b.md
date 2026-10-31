### Problem B: Lower bound

Time limit: 3 s · Memory limit: 256 MB

**Algorithm:** binary search (lower bound).

You are given a sorted array of n integers and q queries. For each query x find the smallest index i such that a[i] ≥ x. Indices are numbered from 1.

A linear scan for every query is too slow: use binary search.

### Input format

The first line contains an integer n.

The second line contains n integers — the array sorted in non-decreasing order.

The third line contains an integer q — the number of queries.

The fourth line contains q integers — the queries.

### Output format

For each query print the index i, or −1 if every element of the array is less than x. Print each answer on a separate line.

### Examples

#### Input

```
5
1 3 3 7 10
4
3 4 11 1
```

#### Output

```
2
4
-1
1
```

#### Input

```
3
2 2 2
2
2 1
```

#### Output

```
1
1
```
