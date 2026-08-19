import math

def get_divisors(n):
    divisors = set()
    for i in range(2, int(math.isqrt(n)) + 1):
        if n % i == 0:
            divisors.add(i)
            divisors.add(n // i)
    if n >= 2:
        divisors.add(n)
    return sorted(divisors)

def compute_sum(n, divisors):
    if n == 1:
        return 1
    if not divisors:
        return n
    d = divisors
    sum_total = n * (d[0] - 1)
    k = len(d)
    for i in range(k):
        di = d[i]
        if i < k - 1:
            di_plus = d[i + 1]
        else:
            di_plus = n + 1
        sum_total += (n // di) * (di_plus - di)
    return sum_total

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
        index += 1
        divisors = get_divisors(n)
        s = compute_sum(n, divisors)
        results.append(str(s))
    
    print('\n'.join(results))

if __name__ == "__main__":
    main()
