import sys

def solution():
    n, q = map(int, sys.stdin.readline().split())
    
    a = [0] * (n + 1)
    sum_value = 0
    for i in range(1, n + 1):
        a[i] = int(sys.stdin.readline())
        sum_value += a[i] * (n - 2 * i + 1)

    for _ in range(q):
        ty = int(sys.stdin.readline())
        if ty == 1:
            print(sum_value)
        else:
            x, v = map(int, sys.stdin.readline().split())
            x += 1
            sum_value -= a[x] * (n - 2 * x + 1)
            a[x] = v
            sum_value += a[x] * (n - 2 * x + 1)

if __name__ == "__main__":
    t = int(sys.stdin.readline())
    for c in range(1, t + 1):
        print(f"Case {c}:")
        solution()

