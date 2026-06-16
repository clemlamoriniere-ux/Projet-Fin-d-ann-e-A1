CC = gcc
CFLAGS = -Wall -lm
SRC = main.c planete.c trajectoire.c euler.c vector.c fichier.c point.c energie.c
OBJ = $(SRC:.c=.o)
TARGET = bin/prog

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(CFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ) bin/$(TARGET)