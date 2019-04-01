CC=g++
LIBS=-C
CFLAGS=-I -w -ggdb
run: test_code/main.cpp game.cpp test_code/fake.cpp
	$(MAKE) main
	./out
debug: test_code/main.cpp game.cpp test_code/fake.cpp
	$(MAKE) main
	gdb ./out
valgrind: main.cpp game.cpp fake.cpp
	$(MAKE) main
	valgrind ./out
main: test_code/main.cpp game.cpp test_code/fake.cpp
	$(CC) -c $(CFLAGS) test_code/main.cpp -o main.o
	$(MAKE) game
	$(MAKE) fake
	$(CC) $(CFLAGS) main.o game.o fake.o -o out $(LIBS)
game: game.cpp
	$(CC) -c $(CFLAGS) game.cpp -o game.o
fake: test_code/fake.cpp
	$(CC) -c $(CFLAGS) test_code/fake.cpp -o fake.o
test_suite:  test_suite/main.cpp game.cpp
	$(CC) -c $(CFLAGS) test_suite/main.cpp -o test_suite/main.o
	$(MAKE) game
	$(CC) $(CFLAGS) game.o test_suite/main.o -o out
	valgrind ./out
	
