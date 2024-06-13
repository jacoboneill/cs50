# FAQ

> What is the libcs50-11.0.2.dylib file?<br><br>
> The libcs50-11.0.2.dylib file is a workaround to get a local copy of the libcs50 working on my computer. For some reason, C doesn't want to see the library in my /usr/lib folder.
> I also created a makefile that can take any number of c files and make a build directory with the binaries. This can be symlinked to by: `[Week #]/dependencies/makefile`.

-

> How can I install the libcs50 library<br>
```
git clone https://github.com/cs50/libcs50.git;
cd libcs50;
sudo make install;
```
