CC=gcc

make: ../tokenz.c ex_tokenz.c ex_tokenzc.c ex_tokenzs.c
	$(CC) -o ex_tokenz ../tokenz.c ex_tokenz.c
	$(CC) -o ex_tokenzc ../tokenz.c ex_tokenzc.c
	$(CC) -o ex_tokenzs ../tokenz.c ex_tokenzs.c
	$(CC) -o ex_tokstr ../tokenz.c ex_tokstr.c
	$(CC) -o ex_toknstr ../tokenz.c ex_toknstr.c
	$(CC) -o ex_tokcat ../tokenz.c ex_tokcat.c
	$(CC) -o ex_tokncat ../tokenz.c ex_tokncat.c

clean:
	rm -f ex_tokenz ex_tokenzc ex_tokenzs ex_tokstr ex_toknstr  ex_tokcat ex_tokncat
