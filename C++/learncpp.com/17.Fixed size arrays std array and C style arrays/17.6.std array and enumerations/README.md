# Animal Explorer: C++ Data Search Implementation

This program demonstrates how to:
 - Use namespaces and structs to build a structured database of animal traits.
 - Manage fixed-size data collections using `std::array` and the `max_animals` enum pattern.
 - Implement search logic that returns a stateful `std::pair` for found/not-found tracking.
 - Utilize memory-efficient *string* handling for constant data.

## How it works
1.  The `Animal` namespace stores a fixed array of `Data` structs, each containing a name, leg count, and the sound the animal makes.
2.  The program prompts the user for an animal name using the `UserInput` function.
3.  The `FindAnimal` function searches the internal array; if a match is found, it returns the index; otherwise, it returns a "not found" status.
4.  The `Draw` function reveals the specific details of the searched animal and then iterates through the remaining list to display the rest of the database.

## Example Output
```
Enter an animal: Dog
A Dog has 4 and says bark

Here is the data for the rest of the animals:
A Chicken has 2 and says cluck
A Cat has 4 and says meow
A Elephant has 4 and says growl
A Duck has 2 and says quack
A Snake has 0 and says hiss
```

## Concepts Covered
 -**Encapsulation**: Using a `namespace` to protect animal data while providing controlled access via logic functions.
 -**Search Logic**: Implementing an indexed loop to compare user input against a structured array.
 -**Memory Optimization**: Passing data by `const reference` and utilizing `std::string_view` to avoid expensive string copying.
 -**Iterative Processing**: Using range-based `for` loops to traverse the collection and display remaining data points.
 -**Advanced data types**: Using `std::pair` to return indices and bool value.