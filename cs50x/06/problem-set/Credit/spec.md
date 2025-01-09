# Credit

## Problem to Solve

In a filed called `credit.py` in a folder called `sentimental-credit`, write a program that prompts the user for a credit card number and then reports (via `print`) whether it is a valid American Express, MasterCard, or Visa card number, exactly as you did in Problem Set 1. Your program this time should be written in Python!

## Demo

```
$ python credit.py
Number: 378282246310005
AMEX
$ python credit.py
Number: 5555555555554444
MASTERCARD
$ python credit.py
Number: 1234567890
INVALID
$
```

## Specification

-   So that we can automate some tests of your code, we ask that your program's last line of output be `AMEX\n` or `MASTERCARD\n` or `VISA\n` or `INVALID\n`, nothing more, nothing less.
-   For simplicity, you may assume that the user's input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card).
-   Best to use `get_int` or `get_string` from CS50's library to get users' input, depending on how you to decide to implement this one.

## Hints

-   It's possible to use regular expressions to validate user input. You might use Python's [`re`](https://docs.python.org/3/library/re.html) module, for example, to check whether the user's input is indeed a sequence of digits of the correct length.
