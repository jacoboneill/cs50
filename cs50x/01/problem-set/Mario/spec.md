# Problem to Solve
Towards the beginning of World 1-1 in Nintendo's Super Mario Brothers, Mario must gop over adjacent blocks of pyramids of blocks, per the below.<br>
![word 1-1](https://cs50.harvard.edu/x/2024/psets/1/mario/more/pyramids.png)

In a file called `mario.c` in a folder called `mario-more`, implement a program in C that recreates that pyramid, using hashes (`#`) for bricks, as in the below:
```
   #  #
  ##  ##
 ###  ###
####  ####
```
And let's allow the user to decide just how tall the pyramids should be by first prompting them for a positive int between, say, 1 and 8, inclusive.

Notice that width of the "gap" between adjacent pyramids is equal to the width of two hashes, irrespective of the pyramid's heights.

