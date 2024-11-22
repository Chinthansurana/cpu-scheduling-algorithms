# Makefile

CC = gcc
CFLAGS = -Wall -g
TARGET = scheduling_simulation

# Source files
SRC = main.c fcfs.c sjf.c srtf.c round_robin.c utils.c

# Object files
OBJ = $(SRC:.c=.o)

# Default target to build the program
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile C files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clean up object and executable files
clean:
	rm -f $(OBJ) $(TARGET)

# Run the program with a default input
run: $(TARGET)
	./$(TARGET)

# Test case command
test: $(TARGET)
	./$(TARGET) < test_input.txt
