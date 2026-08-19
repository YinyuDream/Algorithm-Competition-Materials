def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    T = int(data[index])
    index += 1
    results = []
    
    for _ in range(T):
        n = int(data[index])
        m = int(data[index + 1])
        k = int(data[index + 2])
        w = int(data[index + 3])
        index += 4
        
        a = list(map(int, data[index:index + n]))
        index += n
        b = list(map(int, data[index:index + m]))
        index += m
        
        a.sort()
        b.sort()
        
        b = [0] + b + [w + 1]
        
        paper_strips = []
        red_ptr = 0
        num_red = n
        
        for i in range(len(b) - 1):
            left = b[i] + 1
            right = b[i + 1] - 1
            if left > right:
                continue
            while red_ptr < num_red and a[red_ptr] < left:
                red_ptr += 1
            while red_ptr < num_red and a[red_ptr] <= right:
                pos = a[red_ptr]
                start = pos - k + 1
                if start < left:
                    start = left
                if start + k - 1 > right:
                    results.append(-1)
                    break
                paper_strips.append(start)
                cover_end = start + k
                while red_ptr < num_red and a[red_ptr] < cover_end:
                    red_ptr += 1
            else:
                continue
            break
        else:
            if red_ptr == num_red:
                c = len(paper_strips)
                results.append(c)
                results.append(' '.join(map(str, sorted(paper_strips))))
                continue
        results.append(-1)
    
    print('\n'.join(map(str, results)))

if __name__ == "__main__":
    main()
