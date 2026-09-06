import sys

MAX_BYTES = 250_000  # hard cap requested

def build_test(n):
    """t=1, single test case, n copies of '1' (worst-case shape for the buggy solution)."""
    lines = ["1", str(n), ' '.join(['1'] * n)]
    return '\n'.join(lines) + '\n'

def max_n_for_budget(budget=MAX_BYTES):
    lo, hi = 1, 200000
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if len(build_test(mid).encode()) <= budget:
            lo = mid
        else:
            hi = mid - 1
    return lo

if __name__ == "__main__":
    n = int(sys.argv[1]) if len(sys.argv) > 1 else max_n_for_budget()
    content = build_test(n)
    size = len(content.encode())
    if size > MAX_BYTES:
        raise SystemExit(f"n={n} produces {size} bytes, exceeds {MAX_BYTES} byte budget")
    with open("killer_under_250kb.txt", "w") as f:
        f.write(content)
    print(f"n = {n}")
    print(f"file size = {size} bytes ({size/1024:.1f} KB)")