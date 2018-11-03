# You are given two grids where each cell of the grids contains either a 0 or a 1.

# If two cells share a side then they are adjacent. 

# Cells that contain 1 form a connected region if any cell of that 
# region can be reached by moving through the adjacent cells that contain 1. 

# Overlay the first grid onto the second and if a region of the 
# first grid completely matches a region of the second grid, the 
# regions are matched. 
# Count total number of such matched regions in the second grid.

# NOTE: Diagonal 1's are NOT considered adjacent 1's

# Input:
# 3
# 001
# 011
# 100  TWO regions 
# 3
# 001
# 011
# 101  TWO regions

# Output:
# 2

# Ex Input: ['0100', '1001', '0011', '0011']

# Algorithm: 
# Part A: Find all connected regions
# 1. Keep a hashset of visited nodes in the format (x, y)
# 2. Start at (0,0) look at the adjacent cell for 1's (ignore cells that are visited)
# 3. Add adjacent cells to a set if contains 1's
# 4. Repeat Step 2-3 for every unvisited node

# Part B: Compare the connected regions for the two image
# 0. Part A should bring us two sets of connect regions
# 1. Compare each connected region iff their sizes are equal
# 2. One connected region = another connected region iff all coor pairs are equal (O(n) complexity)



def countMatches(grid1, grid2):
    r1 = getConnectedRegions(grid1)
    r2 = getConnectedRegions(grid2)
    # print(r1, r2)
    count = 0
    for region1 in r1:
        for region2 in r2:
            if len(region1) == len(region2):
                isEq = True
                for c1 in region1:
                    if c1 in region2:
                        continue
                    else:
                        isEq = False
                        break
                if isEq: count += 1
    return count

def getConnectedRegions(grid):
    grid_size = len(grid)
    visited = set()
    regions = []
    for i in range(grid_size):
        for j in range(grid_size):
            if (i, j) in visited:
                continue
            else:
                visited.add((i, j))
                region = findConnectedCells(grid, i, j, visited)
                if region: # If not empty
                    region = set(region)
                    regions.append(region)
    return regions

def findConnectedCells(grid, i, j, visited):
    if grid[i][j] == '0':
        return []

    n = len(grid) - 1
    adj_cells = [(max(i-1, 0), j), (min(i+1, n), j), 
                (i, max(j-1, 0)), (i, min(j+1, n))]
    connected = [(i, j)]
    for cell in adj_cells:
        if cell not in visited:
            x, y = cell
            if grid[x][y] == '1':
                connected.append(cell)
                visited.add(cell)
                connected += findConnectedCells(grid, x, y, visited)
    return connected     

# grid = ['0100', '1001', '0011', '0011']
# print(set(findConnectedCells(grid, 3, 3, set())))

g1a = ['001', '011', '101']
g1b = ['001', '011', '100']
print(countMatches(g1a, g1b))

g2a = ['0100', '1001', '0011', '0011']
g2b = ['0101', '1001', '0011', '0011']
print(countMatches(g2a, g2b))

