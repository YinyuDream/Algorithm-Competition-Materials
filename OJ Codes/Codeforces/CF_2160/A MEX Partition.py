t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    s = set(arr)
    mex = 0
    while mex in s:
        mex += 1
    print(mex)