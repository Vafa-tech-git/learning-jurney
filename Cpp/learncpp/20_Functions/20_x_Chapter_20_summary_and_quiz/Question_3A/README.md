# Binary Search - Iterative Approach

## Overview
This implementation uses a **while loop** to perform binary search on a sorted array.

## How It Works

1. **Initialize bounds**: `min` and `max` define the search range
2. **Loop while valid**: Continue while `min <= max`
3. **Find midpoint**: Calculate the middle index using `std::midpoint(min, max)`
4. **Compare and narrow**:
   - If `array[midpoint] == target`: Found! Return the index
   - If `array[midpoint] > target`: Target is in the left half → `max = midpoint - 1`
   - If `array[midpoint] < target`: Target is in the right half → `min = midpoint + 1`
5. **Not found**: Return `-1` when the loop exits

## Key Points
- **Time Complexity**: O(log n) - halves the search space each iteration
- **Space Complexity**: O(1) - only uses a few variables
- **Advantage**: No recursion overhead, iterative is often faster
- **Requires**: Array must be sorted

## Example
```
Array: [3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48]
Search for: 26

Iteration 1: midpoint=20 (index 6), 20 < 26 → search right
Iteration 2: midpoint=32 (index 9), 32 > 26 → search left
Iteration 3: midpoint=26 (index 8), 26 == 26 → FOUND! Return 8
```
