all: BigInt.o Rational.o
	g++ -o project BigInt.o Rational.o main.cpp

BigInt.o: BigInt.cpp
	g++ -c BigInt.cpp
Rational.o: Rational.cpp
	g++ -c Rational.cpp
clean: 
	rm -f *.o 

