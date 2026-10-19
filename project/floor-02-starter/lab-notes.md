1.) After running the benchmark sort, it has a bunch of N = #'s and mergeSort = #'s ms and std::sort = #'s ms
2.) At an inventory size of 10,000, `std::sort` clearly pulls ahead of the hand-rolled sorts. 
At this size, `std::sort` took 65.214 ms, compared with 91.589 ms for quicksort and 128.047 ms for mergeSort.
