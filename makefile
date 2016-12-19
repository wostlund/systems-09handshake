compile: client.c server.c pipe_networking.c
	gcc server.c pipe_networking.c -o server.out
	gcc client.c pipe_networking.c -o client.out

clean: *~
	rm *~;
