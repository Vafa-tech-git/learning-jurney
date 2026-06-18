# Binary Search - Recursive Approach

## Overview
This implementation uses **recursion** to perform binary search on a sorted array.

## How It Works

1. **Base case**: If `min > max`, the target isn't in this range → return `-1`
2. **Find midpoint**: Calculate the middle index using `std::midpoint(min, max)`
3. **Compare and recurse**:
   - If `array[midpoint] == target`: Found! Return the index
   - If `array[midpoint] > target`: Recursively search the left half → `binarySearch(array, target, min, midpoint - 1)`
   - If `array[midpoint] < target`: Recursively search the right half → `binarySearch(array, target, midpoint + 1, max)`
4. **Important**: Always **return** the result of the recursive call!

## Key Points
- **Time Complexity**: O(log n) - halves the search space each call
- **Space Complexity**: O(log n) - call stack depth is log n
- **Advantage**: Elegant, more intuitive logic
- **Disadvantage**: Uses stack memory, slightly slower than iterative due to function call overhead
- **Critical**: Don't forget `return` statements for recursive calls!
- **Requires**: Array must be sorted

## Example
```
Array: [3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48]
Search for: 26

Call 1: midpoint=20 (index 6), 20 < 26 → recurse right
Call 2: midpoint=32 (index 9), 32 > 26 → recurse left
Call 3: midpoint=26 (index 8), 26 == 26 → FOUND! Return 8
```

## Common Mistake
Forgetting `return` on recursive calls:
```cpp
// ❌ WRONG - result is lost
binarySearch(array, target, midpoint + 1, max);

// ✅ CORRECT - result is returned
return binarySearch(array, target, midpoint + 1, max);
```
