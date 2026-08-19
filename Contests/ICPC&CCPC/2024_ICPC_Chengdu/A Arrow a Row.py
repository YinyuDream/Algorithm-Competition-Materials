def is_arrow(s, p, l):
    if s[p - 1] != '>':
        return False
    if l < 5:
        return False
    if p + l - 1 > len(s):
        return False
    if s[p + l - 4 - 1] != '>' or s[p + l - 3 - 1] != '>' or s[p + l - 2 - 1] != '>':
        return False
    for i in range(p, p + l - 3):
        if s[i - 1] != '-':
            return False
    return True

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    index = 0
    T = int(data[index])
    index += 1
    results = []
    for _ in range(T):
        s = data[index]
        index += 1
        n = len(s)
        operations = []
        pointer = 0
        while pointer < n:
            if s[pointer] != '>':
                results.append("No")
                break
            max_l = 0
            for l in range(5, n - pointer + 1):
                if is_arrow(s, pointer + 1, l):
                    max_l = l
            if max_l == 0:
                results.append("No")
                break
            operations.append((pointer + 1, max_l))
            pointer += max_l
            if pointer > n:
                results.append("No")
                break
        else:
            if len(operations) > n:
                results.append("No")
            else:
                results.append("Yes")
                results.append(str(len(operations)))
                for op in operations:
                    results.append(f"{op[0]} {op[1]}")
    print('\n'.join(results))

if __name__ == "__main__":
    solve()
