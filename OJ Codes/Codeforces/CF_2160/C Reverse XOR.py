import sys

def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    index = 1
    results = []
    for _ in range(t):
        n = int(data[index]); index += 1
        if n == 0:
            results.append("YES")
            continue
            
        L = n.bit_length()
        found = False
        for k in range(L, 61):
            valid = True
            for i in range(0, k // 2):
                left_bit = (n >> (k - 1 - i)) & 1
                right_bit = (n >> i) & 1
                if left_bit != right_bit:
                    valid = False
                    break
            if not valid:
                continue
            if k % 2 == 1:
                mid = k // 2
                if (n >> mid) & 1 == 0:
                    found = True
                    break
            else:
                found = True
                break
                
        results.append("YES" if found else "NO")
        
    print("\n".join(results))

if __name__ == "__main__":
    main()