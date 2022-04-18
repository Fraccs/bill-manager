CC=gcc 
OBJ=main.o app.o bill.o cli.o date.o echo.o help.o logs.o utils.o

output: $(OBJ)
	$(CC) -o billman $(OBJ)

main.o: main.c
	$(CC) -c main.c

app.o: src/app.h src/app.c
	$(CC) -c src/app.c

bill.o: src/bill.h src/bill.c
	$(CC) -c src/bill.c

cli.o: src/cli.h src/cli.c
	$(CC) -c src/cli.c

date.o: src/date.h src/date.c
	$(CC) -c src/date.c

echo.o: src/echo.h src/echo.c
	$(CC) -c src/echo.c

help.o: src/help.h src/help.c
	$(CC) -c src/help.c

logs.o: src/logs.h src/logs.c
	$(CC) -c src/logs.c

utils.o: src/utils.h src/utils.c
	$(CC) -c src/utils.c

clean:
	rm *.o billman