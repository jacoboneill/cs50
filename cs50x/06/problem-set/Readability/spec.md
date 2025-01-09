# Readability

## Problem to Solve

Write, in a file called `readability.py` in a folder called `sentimental-readability`, a program that first asks the user to type in some text, and then outputs the grade level for the text, according to the Coleman-Liau formula, exactly as you did in Problem Set 2, except that your program this time should be written in Python.

## Demo

```
$ python readability.py
Text: One fish. Two fish. Red fish. Blue fish.
Before Grade 1
$ python readability.py
Text: Would you like them here or there? I would not like them here or there. I would not like them anywhere.
Grade 2
$ python readability.py
Text: There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy.
Grade 9
$
```

## Specification

-   Recall that the Coleman-Liau index is computed as `0.0588 * L - 0.296 * S - 15.8`, where `L` is the average number of letters per 100 words in the text, and `S` is the average number of sentences per 100 words in the text.
-   Use `get_string` from the CS50 Library to get the user's input, and `print` to output your answer.
-   Your program should count the number of letters, words, and sentences in the text. You may assume that a letter is any lowercase character from `a` to `z` or any uppercase character from `A` to `Z`, any sequence of characters separated by spaces should count as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
-   Your program should print as output `"Grade X"` where `X` is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
-   If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output `"Grade 16+"` instead of giving the exact index number. If the index number is less than 1, your program should output `"Before Grade 1"`.
