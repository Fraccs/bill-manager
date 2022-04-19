CC=gcc 
OBJ=build/main.o build/app.o build/bill.o build/cli.o build/date.o build/help.o build/logs.o build/utils.o

output: $(OBJ)
	$(CC) -o bin/billman $(OBJ)

build/main.o: main.c
	$(CC) -c main.c -o build/main.o

build/%.o: src/%.c src/%.h
	$(CC) -c $< -o $@

clean:
	rm build/* bin/*