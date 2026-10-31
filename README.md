<p align="center">
  <img src="assets/KBTU.png" alt="Kazakh-British Technical University" width="440">
</p>

<h1 align="center">Algorithms and Data Structures</h1>

<p align="center">
  <b>Kazakh-British Technical University</b> · Fall 2026<br>
  Laboratory works solved in <b>C++</b> and <b>Python</b>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/labs-12-1f3a93" alt="12 labs">
  <img src="https://img.shields.io/badge/tasks-97-1f3a93" alt="97 tasks">
  <img src="https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus" alt="C++17">
  <img src="https://img.shields.io/badge/Python-3-3776AB?logo=python&logoColor=white" alt="Python 3">
</p>

---

## About

This repository collects my solutions to the laboratory works of the **Algorithms and Data Structures (ADS)** course at KBTU.

Every lab folder contains the **task statements** and the **solutions in both C++ and Python**. The solutions use the same algorithms as the course lectures and are written to be easy to read: plain loops, one idea per function and short comments that explain the key step.

## Labs

| Lab | Topic | Main algorithms | Tasks |
|:---:|---|---|:---:|
| [01](lab01) | Complexity and Memory | GCD, binary exponentiation, sieve of Eratosthenes, factorization, stack, queue | 10 |
| [02](lab02) | Linear Data Structures | singly and doubly linked lists, stack, queue | 10 |
| [03](lab03) | Search Algorithms | binary search, binary search on the answer | 11 |
| [04](lab04) | Tree Structures | binary search tree | 10 |
| [05](lab05) | Priority Structures | heap, priority queue | 5 |
| [06](lab06) | Sorting Algorithms I | counting sort, quick sort, comparators | 9 |
| [07](lab07) | Sorting Algorithms II | merge sort, counting inversions | 5 |
| [08](lab08) | Hash Tables | polynomial hashing, Rabin-Karp | 6 |
| [09](lab09) | String Algorithms | prefix function, KMP | 8 |
| [10](lab10) | Graphs and BFS | BFS, DFS, topological sort | 10 |
| [11](lab11) | Spanning Trees | Kruskal, Prim, DSU | 5 |
| [12](lab12) | Shortest Paths | Floyd-Warshall, Dijkstra, Bellman-Ford | 5 |
| [practice](practice) | Practice | linked list, lower bound, Lomuto partition | 3 |

## Repository structure

```
labXX/
├── README.md      list of the tasks with links
├── a.md, b.md …   task statements
├── cpp/           C++ solutions:    a.cpp, b.cpp, …
└── python/        Python solutions: a.py,  b.py,  …
```

## How to run

**C++**

```bash
g++ -std=c++17 lab01/cpp/a.cpp -o a
./a < input.txt
```

**Python**

```bash
python3 lab01/python/a.py < input.txt
```

Without `< input.txt` the program waits for you to type the input.

## Sources

- Lecture notes: [askarakshabayev/ADS2025FALL](https://github.com/askarakshabayev/ADS2025FALL)
- Task statements: the course e-judge (contests 201–212)

## Note

These solutions are shared for learning and exam preparation. Read them, understand the idea, and then write the code yourself — that is the part that actually helps on the exam.
