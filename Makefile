all: BigInt.o Rational.o Complex.o
	g++ -Wall -o project BigInt.o Rational.o Complex.o main.cpp

BigInt.o: BigInt.cpp
	g++ -c BigInt.cpp
Rational.o: Rational.cpp
	g++ -c Rational.cpp
Complex.o: Complex.cpp
	g++ -c Complex.cpp
clean:
	rm -f *.o
