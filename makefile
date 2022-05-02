all: driver.o testInputGenerator.o

input: testInputGenerator.o

driver.o: driver.cpp
		g++ -o driver driver.cpp

testInputGenerator.o: testInputGenerator.cpp
		g++ -o testInputGenerator testInputGenerator.cpp

clean:
	rm -f *.o *.exe 1to10Testing.txt 1to100Testing.txt output.txt performanceDiff.txt driver testInputGenerator


