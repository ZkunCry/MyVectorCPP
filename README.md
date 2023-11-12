# Custom implementation of a vector and comparison with a vector from the standard library C++

Course project for "Algorithms and Data Structures". SurSU 2023.

## Comparison with std::vector

To study the performance of the algorithm, as well as compare it with ready-made STL implementations, operations were performed to add elements using push_Bask, Insert, delete and search for elements, erase, find algorithms.
A total of 100 measurements were made with a step of 10,000 elements, from 100,000 to 1,000,000.

## Push_Back method

As you can see, the asymptotic complexity of inserting an element using push_back in this implementation matches the theoretical asymptotic complexity and is equal to O(1).
The graph also shows sharp jumps in some values. This means that at these moments the size of the array of values increases, and memory redistribution is caused accordingly.

<p align="center">
  <img style="text-align:center;" src="https://github.com/ZkunCry/MyVectorCPP/raw/master/assets/vectorcompare.jpg" alt="drawing" width="500"/>
</p>

## Insert method

But the insertion method already has an asymptotic complexity equal to O(n). Of course, it depends on the case; in the case of insertion at the end, the asymptotic complexity will not differ from push_bask and is equal to O(1).

<p align="center">
  <img style="text-align:center;" src="https://github.com/ZkunCry/MyVectorCPP/raw/master/assets/vectorinsert.png" alt="drawing" width="500"/>
</p>

## Erase method

The graph shows that the asymptotic complexity of this method is O(n), while the speed of the vector from the standard library is much higher and is almost O(1).

<p align="center">
  <img src="https://github.com/ZkunCry/MyVectorCPP/raw/master/assets/erase.png" alt="drawing" width="500"/>
</p>
