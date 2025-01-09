# Memory

# Memory Types

Memory Type | Size in Bytes
------------|--------------
`bool`      | 1
`int`       | 4
`long`      | 8
`float`     | 4
`double`    | 8
`char`      | 1
`string`    | ?

## String
A string is a dynamicly lengthed type, because it is a series of `char`'s

# Memory Addresses
Each byte in memory has an address to store the bytes in physical memory. For example, you could argue a chip on a RAM stick has 4 bytes. Each byte will have an address so, as a developer, you can say "I want to store `0x4F` at address `address_1`". You can then go on to say "What is the value stored at address `address_1`?" and the computer will reply with `0x4F`.

# scores.c
> See ./assets/scores.c for source code

## version_1

```c
void version_1(){
  int score1 = 72;
  int score2 = 73;
  int score3 = 33;

  printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
}
```
The problem with version 1, is that it has a lot of repeated variable names with numbers next to them. This can easily be solved with an array

## version_2
```c
void version_2(){
  int scores[] = {72, 73, 33};

  printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}
```
The array has now been harcoded to have values `{72, 73, 33}`. The average gets made by adding all the values at their indices and divided by `3.0`. It would be nicer though to be able to choose how many scores to add and for it to be dynamic...

## version_3
```c
void version_3(){
  // Get number of scores
  const int SIZE = get_int("How many scores do you want to save? ");

  // Get Scores
  int scores[SIZE];
  for(int i = 0; i < SIZE; i++){
    scores[i] = get_int("Score %i: ", i + 1);
  }

  // Calculate Average
  float average = 0;
  for(int i = 0; i < SIZE; i++){
    average += scores[i];
  }
  average /= (float) SIZE;

  printf("Average: %f\n", average);
}
```
The user first gets asked how many values they want to add in `const int SIZE` (caps for convention of const).
An array is then initialised and then looped over to add the values. After this, an averaging algorithm allows for the calculation of the average dynamically, and finally the average is `printf`d to the console.

If I was to improve on this, I would remove the `// Get Scores` and `// Calculate Average` blocks of code to their own functions to seperate concerns. However, nested functions aren't possible in C.
