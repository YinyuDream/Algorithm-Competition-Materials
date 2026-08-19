import sys

def solve():
    """
    Calculates the minimum number of operations to make a circular array nice
    using a dynamic programming approach on rotated versions of the array.
    """
    try:
        # Fast I/O
        input = sys.stdin.readline
        
        n_str = input()
        if not n_str:
            return
        n = int(n_str)
        a = list(map(int, input().split()))

        def get_median_cost(arr):
            """Calculates the cost to make all elements in arr equal to their median."""
            if not arr:
                return 0
            s_arr = sorted(arr)
            # For a block of size 3, the cost is simply max - min.
            return s_arr[-1] - s_arr[0]

        def solve_linear(arr):
            """
            Solves the problem for a linear array using dynamic programming.
            dp[i] = min cost to make the prefix of length i nice.
            """
            m = len(arr)
            if m == 0:
                return 0
            
            dp = [float('inf')] * (m + 1)
            dp[0] = 0
            
            for i in range(1, m + 1):
                # Option 1: The last block is of size 2
                if i >= 2:
                    cost2 = abs(arr[i - 2] - arr[i - 1])
                    if dp[i - 2] != float('inf'):
                        dp[i] = min(dp[i], dp[i - 2] + cost2)
                
                # Option 2: The last block is of size 3
                if i >= 3:
                    cost3 = get_median_cost(arr[i - 3:i])
                    if dp[i - 3] != float('inf'):
                        dp[i] = min(dp[i], dp[i - 3] + cost3)
            
            return dp[m]

        # The problem is circular, so we solve the linear problem on a few rotations
        # to handle all possible wrap-around blocks.
        # Rotating by up to 2 elements is sufficient because we only consider blocks
        # of size 2 and 3.

        # Case 1: No rotation
        min_ops = solve_linear(a)
        
        # Case 2: Rotate by 1
        if n > 2:
            rotated_a_1 = a[1:] + a[:1]
            min_ops = min(min_ops, solve_linear(rotated_a_1))
        
        # Case 3: Rotate by 2
        if n > 2:
            rotated_a_2 = a[2:] + a[:2]
            min_ops = min(min_ops, solve_linear(rotated_a_2))
            
        print(min_ops)

    except (IOError, ValueError):
        return

def main():
    try:
        t_str = sys.stdin.readline()
        if not t_str:
            return
        t = int(t_str)
        for _ in range(t):
            solve()
    except (IOError, ValueError):
        return

if __name__ == "__main__":
    main()