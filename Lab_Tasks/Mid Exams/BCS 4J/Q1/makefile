main.exe: main.c worker_1.c worker_2.c
	gcc create_fifo.c -o create_fifo.exe
	gcc worker_1.c -o worker_1.exe
	gcc worker_2.c -o worker_2.exe
	gcc main.c -o main.exe

run:
	./create_fifo.exe
	./main.exe

clean: 
	rm *.exe fifo_pipe