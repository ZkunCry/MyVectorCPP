# Custom implementation of a vector and comparison with a vector from the standard library C++

Course project for "Algorithms and Data Structures". SurSU 2023.

## Comparison with std::map and std::unordered_map

To study the performance of the algorithm, as well as compare it with ready-made STL implementations,
operations were performed to add elements using the push_Bask operation.
A total of 100 measurements were made in increments of 10000 elements, from 100,000 to 1,000,000.

<img src="https://github.com/ZkunCry/MyVectorCPP/raw/master/assets/vectorcompare.jpg" alt="drawing" width="400"/>

As you can see, the asymptotic complexity of inserting an element into this implementation and the unordered STL map matches the theoretical asymptotic complexity and is equal to O(1).

The graph also shows sharp jumps in some values. This means that at these moments the size of the array of values increases, and memory redistribution is caused accordingly.
