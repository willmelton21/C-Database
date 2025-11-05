TARGET =  bin/dbview
CFLAGS = -Iinclude
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))


run: clean default
	./$(TARGET) -f ./mynewdb.db -n
	./$(TARGET) -f ./mynewdb.db 
	#./$(TARGET) -f ./mynewdb.db -a "Timmy H.,123 Seshire Lin.,120"


default: $(TARGET)

clean:
	rm -f obj/*.o
	rm -f bin/*
	rm -f *.db

$(TARGET): $(OBJ)
	gcc -o $@ $?


obj/%.o : src/%.c
	mkdir -p obj
	gcc $(CFLAGS) -c $< -o $@

