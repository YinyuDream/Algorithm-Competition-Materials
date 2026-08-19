def main():
    data = input().split()
    
    index = 0
    T = int(data[index])
    index += 1
    results = []
    
    for _ in range(T):
        a = int(data[index])
        index += 1
        b = int(data[index])
        index += 1
        c = int(data[index])
        index += 1
        
        n = 100
        dataset = ([a] * 50) + ([b] * 45) + ([c] * 4) + [c + 1]
        
        results.append(str(n))
        results.append(' '.join(map(str, dataset)))
    
    print('\n'.join(results))

if __name__ == "__main__":
    main()
