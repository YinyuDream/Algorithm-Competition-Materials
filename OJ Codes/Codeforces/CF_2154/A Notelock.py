t = int(input().strip())
for _ in range(t):
    data = input().split()
    n = int(data[0])
    k = int(data[1])
    s = input().strip()
    ones = []
    for i, char in enumerate(s):
        if char == '1':
            ones.append(i)
    if len(ones) == 0:
        print(0)
    else:
        count = 0
        current_coverage = -1
        for pos in ones:
            if pos > current_coverage:
                count += 1
                current_coverage = pos + k - 1
            else:
                current_coverage = max(current_coverage, pos + k - 1)
        print(count)