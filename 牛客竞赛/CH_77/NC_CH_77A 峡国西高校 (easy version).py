def to_base_k(n, k):
    """将十进制数n转换为k进制数"""
    if n == 0:
        return [0]
    digits = []
    while n:
        digits.append(n % k)
        n //= k
    return digits[::-1]

def from_base_k(digits, k):
    """将k进制数的digits转换为十进制数"""
    result = 0
    for digit in digits:
        result = result * k + digit
    return result

def no_carry_add(A, B, k):
    """计算A + B在k进制下的不进位加法，返回其十进制值"""
    # 将A和B转换成k进制
    digits_A = to_base_k(A, k)
    digits_B = to_base_k(B, k)
    
    # 对齐两个数的位数，短的数前面补0
    max_len = max(len(digits_A), len(digits_B))
    digits_A = [0] * (max_len - len(digits_A)) + digits_A
    digits_B = [0] * (max_len - len(digits_B)) + digits_B
    
    # 不进位加法
    result_digits = []
    for a, b in zip(digits_A, digits_B):
        result_digits.append((a + b) % k)
    
    # 将结果转换回十进制
    return from_base_k(result_digits, k)

# 示例
k, A, B = map(int, input().split())
print(no_carry_add(A, B, k))
