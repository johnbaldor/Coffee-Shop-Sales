all: coffee_shop.o register.o
	gcc coffee_shop.c register.c -o register

register.o: register.c register.h 
	gcc -c register.c -o register.o

coffee_shop.o: register.c 
	gcc -c coffee_shop.c -o coffee_shop.o

clean:
	rm *.o register