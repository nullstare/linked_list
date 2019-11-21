GTEST_DIR = ../googletest/googletest

CFLAGS = -Wall -ggdb
# CFLAGS = 

# CC = gcc
CC = clang

all: release test
	./test
	
test: libgtest.a Gtest_main.c linked_list_test_case.c linked_list.o
	g++ -isystem $(GTEST_DIR)/include -pthread linked_list_test_case.c linked_list.c Gtest_main.c libgtest.a -o test

# release: string.o main.o
release: linked_list.o
	g++ -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) -pthread -c $(GTEST_DIR)/src/gtest-all.cc

linked_list.o: linked_list.c 
	$(CC) -c linked_list.c $(CFLAGS)

libgtest.a: gtest-all.o
	ar -rv libgtest.a gtest-all.o

clean:
	rm *.o test libgtest.a
