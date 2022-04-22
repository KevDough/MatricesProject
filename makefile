all: driver.o

driver.o: driver.cpp
		g++ -o driver driver.cpp

clean:
	rm -f *.o *.exe driver


