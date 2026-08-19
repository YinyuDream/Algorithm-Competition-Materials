import sys

def compute_max_perim(sticks):
    n = len(sticks)
    if n < 3:
        return 0
    sticks.sort()
    total = sum(sticks)
    groups = []
    i = 0
    while i < n:
        b = sticks[i]
        f = 0
        while i < n and sticks[i] == b:
            f += 1
            i += 1
        groups.append([b, f])
    odd_l = [g[0] for g in groups if g[1] % 2 == 1]
    odd_l.sort()  # already should be, but ensure
    pp = len(odd_l)
    prefix = [0]
    for x in odd_l:
        prefix.append(prefix[-1] + x)
    current_n = n
    current_total = total
    while True:
        rr = max(0, pp - 2)
        cost = prefix[rr] if rr > 0 else 0
        cand = current_total - cost
        if current_n - rr < 3:
            return 0
        if len(groups) == 0:
            return 0
        mm = groups[-1][0]
        if cand > 2 * mm:
            return cand
        # else
        cc = groups[-1][1]
        if cc >= 2:
            return 0
        # remove
        remove_val = mm
        current_total -= remove_val
        current_n -= 1
        groups.pop()
        odd_l.pop()
        pp -= 1
        # prefix remains valid

input = sys.stdin.read
data = input().split()
index = 0
t = int(data[index])
index += 1
results = []
for _ in range(t):
    n = int(data[index])
    index += 1
    a = []
    for j in range(n):
        a.append(int(data[index]))
        index += 1
    results.append(compute_max_perim(a))
for res in results:
    print(res)