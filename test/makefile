SHELL =  /usr/bin/bash
CC := gcc
obj := data_storage_drink.o data_storage_food.o sort.o user.o
exe := main

all: $(obj)
	$(CC) $(obj) -o $(exe)

%.o: %.c
	$(CC) -c $^ -o $@

.PHONY: clean
clean:
	rm -rf $(obj) $(exe)