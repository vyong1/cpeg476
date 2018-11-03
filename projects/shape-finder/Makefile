.PHONY: all clean
all: contours
clean:
	rm -f *.o contours

contours.o: contours.cpp
	g++ -Wall -g -c contours.cpp -o contours.o

contours: contours.o
	g++ contours.o -o contours -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs