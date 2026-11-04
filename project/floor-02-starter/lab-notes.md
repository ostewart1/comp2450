1.) After running the benchmark sort, it has a bunch of N = #'s and mergeSort = #'s ms and std::sort = #'s ms
2.) At an inventory size of 10,000, `std::sort` clearly pulls ahead of the hand-rolled sorts. 
At this size, `std::sort` took 65.214 ms, compared with 91.589 ms for quicksort and 128.047 ms for mergeSort.
3.) Pre-sorted input: all 3 sorting algorithms were faster at smaller inventory sizes, but 
`std::sort` still outperformed the others at larger sizes. For example, at an inventory size of 10,000, `std::sort` took 45.123 ms, 
while quicksort took 70.456 ms and mergeSort took 110.789 ms.
4.) When N doubles, the middle-pivot follows the expected O(N log N) growth pattern, 
while the first-pivot quicksort follows O(n2) growth and increases faster as N increases
Sorted input is the worst case because the first-pivot quicksort will always pick the first element as the pivot, leading to unbalance. The middle-pivot quicksort and mergeSort 
maintain their O(N log N) performance even with sorted input, making them more efficient.
5.) If I could only choose one sorting algorithm for production, I would choose std::sort. It performs well and protects against the worst-case behavior of quicksort. 
MergeSort also has reliable performance, but it can require additional memory. My hand-written quicksort performs well with a middle pivot, but it can become extremely 
slow if the pivot creates unbalanced partitions. Since real-world data can already be sorted or partially sorted, I would choose std::sort because it is reliable, efficient, 
and handles different types of input well.