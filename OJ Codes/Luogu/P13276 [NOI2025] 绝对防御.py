import sys

def main():
    data = sys.stdin.read().splitlines()
    c, t_val = map(int, data[0].split())
    index = 1
    out_lines = []
    for _ in range(t_val):
        n, q = map(int, data[index].split())
        index += 1
        s = data[index].strip()
        index += 1
        arr = list(s)
        D = s.count('1')
        floor_half = n // 2
        
        lo, hi = 0, floor_half
        T_max = 0
        while lo <= hi:
            mid = (lo + hi) // 2
            g_val = mid - (mid + 2) // 3
            if g_val <= D:
                T_max = mid
                lo = mid + 1
            else:
                hi = mid - 1
        k0 = n - 2 * T_max
        res = [k0]
        
        for _ in range(q):
            x = int(data[index]) - 1
            index += 1
            if arr[x] == '0':
                arr[x] = '1'
                D += 1
            else:
                arr[x] = '0'
                D -= 1
            lo, hi = 0, floor_half
            T_max = 0
            while lo <= hi:
                mid = (lo + hi) // 2
                g_val = mid - (mid + 2) // 3
                if g_val <= D:
                    T_max = mid
                    lo = mid + 1
                else:
                    hi = mid - 1
            res.append(n - 2 * T_max)
        
        out_lines.append(" ".join(map(str, res)))
    
    print("\n".join(out_lines))

if __name__ == "__main__":
    main()