import sys
input = sys.stdin.readline

MOD = 10**9 + 7


def digit_hash(s):
    # h = sum of (s[i] - 47) * 11^i, everything modulo 1e9+7
    h = 0
    power = 1
    for c in s:
        h = (h + (ord(c) - 47) * power) % MOD
        power = power * 11 % MOD
    return h


n = int(input())
lines = [input().strip() for _ in range(2 * n)]
present = set(lines)

out = []
for s in lines:
    h = str(digit_hash(s))
    if h in present:  # its hash is also in the input -> s is a string, not a hash
        out.append(f'Hash of string "{s}" is {h}')
        if len(out) == n:
            break
print("\n".join(out))
