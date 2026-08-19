import sys

def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    index = 1
    results = []
    for _ in range(t):
        n = int(data[index]); index += 1
        a = list(map(int, data[index:index+n]))
        index += n
        
        P = [0] * n
        P[0] = a[0]
        for i in range(1, n):
            P[i] = max(P[i-1], a[i])
            
        cost = 0
        for i in range(0, n, 2):
            if i == 0:
                if n > 1:
                    cost += max(0, a[i] - (P[1] - 1))
            else:
                cost += max(0, a[i] - (P[i-1] - 1))
                
        results.append(str(cost))
        
    print("\n".join(results))

if __name__ == "__main__":
    main()