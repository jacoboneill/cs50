FROM ubuntu:latest

RUN apt update && apt -y upgrade && apt install -y build-essential git
RUN apt -y upgrade
RUN apt install -y build-essential git

RUN git clone https://github.com/cs50/libcs50.git
RUN cd libcs50 && make clean && make && make install && cd ..
RUN rm -rf libcs50
RUN apt purge -y git
RUN apt autoremove -y
RUN apt install -y vim

RUN echo "CC = gcc\nCFLAGS = -Wall -Wextra -Werror\nLDLIBS = -lcs50\n%: %.c\n\t\$(CC) \$(CFLAGS) \$< -o \$@ \$(LDLIBS)" > /home/Makefile
