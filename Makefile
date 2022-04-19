CC=gcc 
OBJ=build/main.o build/app.o build/bill.o build/cli.o build/date.o build/help.o build/logs.o build/utils.o

output: $(OBJ)
	$(CC) -o bin/billman $(OBJ)

build/main.o: main.c
	$(CC) -c main.c -o build/main.o

build/app.o: src/app.h src/app.c
	$(CC) -c src/app.c -o build/app.o

build/bill.o: src/bill.h src/bill.c
	$(CC) -c src/bill.c -o build/bill.o

build/cli.o: src/cli.h src/cli.c
	$(CC) -c src/cli.c -o build/cli.o

build/date.o: src/date.h src/date.c
	$(CC) -c src/date.c -o build/date.o

build/help.o: src/help.h src/help.c
	$(CC) -c src/help.c -o build/help.o

build/logs.o: src/logs.h src/logs.c
	$(CC) -c src/logs.c -o build/logs.o

build/utils.o: src/utils.h src/utils.c
	$(CC) -c src/utils.c -o build/utils.o

clean:
	rm build/*.o bin/billman