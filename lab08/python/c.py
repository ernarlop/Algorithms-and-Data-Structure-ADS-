import sys
from collections import Counter
input = sys.stdin.readline

out = []
while True:
    line = input().strip()
    if line == "" or line == "0":
        break
    n = int(line)
    patterns = [input().strip() for _ in range(n)]
    text = input().strip()

    freq = {}
    for L in set(len(p) for p in patterns):
        same_len = [p for p in patterns if len(p) == L]
        if not any(p in text for p in same_len):  # none of them occurs at all -> all zero
            for p in same_len:
                freq[p] = 0
            continue
        # hash table: how many times every substring of length L appears in the text
        cnt = Counter(text[i:i + L] for i in range(len(text) - L + 1))
        for p in same_len:
            freq[p] = cnt[p]

    best = max(freq.values())
    out.append(str(best))
    for p in patterns:
        if freq[p] == best:
            out.append(p)
print("\n".join(out))
