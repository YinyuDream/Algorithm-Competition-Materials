import sys

def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    index = 1
    results = []
    for _ in range(t):
        n = int(data[index])
        index += 1
        b = list(map(int, data[index:index+n]))
        index += n
        distinct_set = set(b)
        results.append(str(len(distinct_set)))
    print("\n".join(results))

if __name__ == "__main__":
    main()