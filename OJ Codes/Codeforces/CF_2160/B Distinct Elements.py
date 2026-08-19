import sys

def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    index = 1
    output_lines = []
    for _ in range(t):
        n = int(data[index])
        index += 1
        b = list(map(int, data[index:index+n]))
        index += n
        a_list = []
        next_val = 1
        a_list.append(next_val)
        next_val += 1
        for i in range(1, n):
            diff = b[i] - b[i-1]
            L_i = i + 1 - diff
            if L_i == 0:
                a_list.append(next_val)
                next_val += 1
            else:
                a_list.append(a_list[L_i - 1])
        output_lines.append(" ".join(map(str, a_list)))
    print("\n".join(output_lines))

if __name__ == "__main__":
    main()