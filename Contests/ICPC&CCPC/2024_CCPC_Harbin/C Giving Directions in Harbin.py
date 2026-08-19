def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    T = int(data[index])
    index += 1
    results = []
    
    direction_map = {'N':0, 'E':1, 'S':2, 'W':3}
    
    for _ in range(T):
        n = int(data[index])
        index += 1
        instructions = []
        for _ in range(n):
            d = data[index]
            x = int(data[index + 1])
            instructions.append((d, x))
            index += 2
        # Determine initial direction
        f = instructions[0][0]
        # Calculate m
        m = 2 * n - 1
        # Collect output lines
        output_lines = [f"{m} {f}"]
        current_dir = direction_map[f]
        # First instruction is Z x[0]
        output_lines.append(f"Z {instructions[0][1]}")
        for i in range(1, n):
            next_dir = direction_map[instructions[i][0]]
            # Determine turn
            if next_dir == (current_dir + 1) % 4:
                turn = "R"
            elif next_dir == (current_dir - 1 + 4) % 4:
                turn = "L"
            else:
                # This should not happen per problem statement
                turn = "R"  # default, though incorrect
            output_lines.append(turn)
            output_lines.append(f"Z {instructions[i][1]}")
            current_dir = next_dir
        # Add to results
        results.append('\n'.join(output_lines))
    
    print('\n\n'.join(results))

if __name__ == "__main__":
    main()
