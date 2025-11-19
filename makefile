CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic
TARGET = vector_program
TEST_TARGET = tests

SOURCES = main.c func.c
TEST_SOURCES = tests.c func.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

$(TEST_TARGET): $(TEST_SOURCES)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_SOURCES)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)

.PHONY: all test clean