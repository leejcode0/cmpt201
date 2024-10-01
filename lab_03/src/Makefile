CC := gcc
CFLAGS = -Wall -g -std=c11

SRC_FILES := cdatatypesfile.c ascii.c gravity.c gravity2.c

OBJ_FILES := $(SRC_FILES:.c=.o)

all: cftypes ascii gravity gravity2

cftypes: cdatatypesfile.o
	$(CC) $(CFLAGS) -o $@ $^

ascii: ascii.o
	$(CC) $(CFLAGS) -o $@ $^

gravity: gravity.o
	$(CC) $(CFLAGS) -o $@ $^

gravity2: gravity2.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean package all
clean:
	rm -f *.o cftypes ascii gravity gravity2 planetInformation.txt

package:
	tar -cvzf cmpt201_lab03_JL.tar.gz *.c *.h Makefile
