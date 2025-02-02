all: comp
	./app 
val: comp
	valgrind -s ./app
san: 
	gcc ./src/main.c -Wall -g -o app -fsanitize=address
	./app
comp:
	gcc ./src/main.c -Wall -g -o app
	gcc ./src/test.c -Wall -g -o test
	gcc ./src/maintest.c -Wall -g -o apptest
test: comp
	./test 1000 | ./apptest
testval: comp
	./test 1000 | valgrind -s ./apptest