Big O Notation is a way to measure an algorithm’s efficiency. It measures the time it takes to run your function as the input grows. Or in other words, how well does the function scale.

There are two parts to measuring efficiency — time complexity and space complexity. Time complexity is a measure of how long the function takes to run in terms of its computational steps. Space complexity has to do with the amount of memory used by the function. This blog will illustrate time complexity with two search algorithms.

Big O is sometimes referred to as the algorithm’s upper bound, meaning that it deals with the worst-case scenario. The best-case scenario doesn’t really tell us anything — it will be finding our item in the first pass. We use worst-case to remove uncertainty — the algorithm will never perform worse than we expect.