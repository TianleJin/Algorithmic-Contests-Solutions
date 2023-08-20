from math import sqrt
read_line = lambda: list(map(int, input().strip().split()))
INF = float('inf')

def print_grid(grid):
    for i in range(len(grid)):
        print(" ".join(map(str, grid[i])))

def set_pixel_to_black(grid, R, r, c):
    grid[r + R][c + R] = 1

def draw_circle_perimeter(grid, rad, R):
    for x in range(-rad, rad + 1):
        y = round(sqrt(rad * rad - x * x))
        set_pixel_to_black(grid, R, x, y)
        set_pixel_to_black(grid, R, x, -y)
        set_pixel_to_black(grid, R, y, x)
        set_pixel_to_black(grid, R, -y, x)

def draw_circle_filled(grid, R):
    for x in range(-R, R + 1):
        for y in range(-R, R + 1):
            if round(sqrt(x * x + y * y)) <= R:
                set_pixel_to_black(grid, R, x, y)

def draw_circle_filled_wrong(grid, R):
    for rad in range(R + 1):
        draw_circle_perimeter(grid, rad, R)


def solve(tt):
    R = int(input())
    grid1 = [[0] * (2 * R + 1) for _ in range(2 * R + 1)]
    grid2 = [[0] * (2 * R + 1) for _ in range(2 * R + 1)]
    draw_circle_filled(grid1, R)
    draw_circle_filled_wrong(grid2, R)
    
    ans = 0
    for x in range(2 * R + 1):
        for y in range(2 * R + 1):
            if grid1[x][y] != grid2[x][y]:
                ans += 1
    print(f"Case #{tt}: {ans}")


if __name__ == "__main__":
    T = int(input())
    for tt in range(1, T + 1):
        solve(tt)
