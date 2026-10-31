n, m = map(int, input().split())
a = list(map(int, input().split()))
L = [n] * n; R = [n] * n; st = []  # L[i], R[i] — сыновья i-й вставленной вершины, n — нет сына
for i in sorted(range(n), key=lambda i: (a[i], -i)):  # строим BST: вершины по возрастанию + стек
    j = n
    while st and st[-1] > i: j = st.pop()
    L[i] = j
    if st: R[st[-1]] = i
    st.append(i)
L.append(n); R.append(n)  # из "нет вершины" путь тоже никуда не ведёт
for _ in range(m):
    v = 0
    for c in input(): v = L[v] if c == 'L' else R[v]
    print("YES" if v < n else "NO")
