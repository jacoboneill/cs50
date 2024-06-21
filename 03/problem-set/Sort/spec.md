# Problem to solve
Recall from lecture that we saw a few algorithms for sorting a sequence of numbers: selection sort, bubble sort, and merge sort.
- Selection sort iterates through the unsorted portions of a list, selecting the smallest element each time and moving it to its correct location.
- Bubble sort compares pairs of adjacent values one at a time and swaps them if they are in the incorrect order. This continues until the list is sorted.
- Merge sort recursively divides the list into two repeatedly and then merges the smaller lists back into a larger one in the correct order.

In this problem, you’ll analyze three (compiled!) sorting programs to determine which algorithms they use. In a file called `answers.txt` in a folder called `sort`, record your answers, along with an explanation for each program, by filling in the blanks marked `TODO`

# Distribution Code
For this problem, you’ll need some “distribution code”—that is, code written by CS50’s staff. Provided to you are three already-compiled C programs, `sort1`, `sort2`, and zsort3, as well as several `.txt` fikes for input and another file, `answers.txt`, in which to write your answers. Each of `sort1`, `sort2`, and `sort3`  implements a different sorting algorithm: selection sort, bubble sort, or merge sort (though not necessarily in that order!). Your task is to determine which sorting algorithm is used by each file. Start by downloading these files.

## Download Distribution Code
```
wget https://cdn.cs50.net/2023/fall/psets/3/sort.zip
unzip sort.zip
rm sort.zip
```
