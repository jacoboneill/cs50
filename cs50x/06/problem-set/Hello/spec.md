# Hello, Again

## Problem to Solve

In a file called `hello.py` in a folder called `sentimental-hello`, implement a program that prompts a user for their name, and then prints `hello, so-and-so`, where `so-and-so` is their provided name, exactly as you did in Problem Set 1. Except that your program this time should be written in Python!

Hints

-   Recall that you can get a `str` from a user with `get_string`, which is declared in the `cs50` library.
-   Recall that you can print a `str` with `print`.
-   Recall that you can create formatted strings in Python by prepending `f` to a string itself. For example, `f""` will substitute ("interpolate") the value of the variable `name` where you've written ``.

## Demo

```
$ python hello.py
What is your name? David
hello, David
$ python hello.py
What is your name? Inno
hello, Inno
$ python hello.py
What is your name? Kamryn
hello, Kamryn
$
```

## How to Test

While `check50` is available for this problem, you're encouraged to first test your code on your own for each of the following.

-   Run your program as `python hello.py`, and wait for a prompt for input. Type in `David` and press enter. Your program should output `hello, David`.
-   Run your program as `python hello.py`, and wait for a prompt for input. Type in `Inno` and press enter. Your program should output `hello, Inno`.
-   Run your program as `python hello.py`, and wait for a prompt for input. Type in `Kamryn` and press enter. Your program should output `hello, Kamryn`.
