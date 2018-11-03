.PHONY: all clean
all: view_image
clean:
	rm -f *.o view_image

view_image.o: view_image.cpp
	g++ -Wall -g -c view_image.cpp -o view_image.o

view_image: view_image.o
	g++ view_image.o -o view_image -L/usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs