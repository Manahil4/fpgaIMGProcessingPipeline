# Simple Makefile (Windows)

all: pipeline.exe

pipeline.exe: main.o frame_reader.o grayscale.o out.o pixel_buffer.o
	g++ main.o frame_reader.o grayscale.o out.o pixel_buffer.o -o pipeline.exe

main.o: main.cpp
	g++ -c main.cpp

frame_reader.o: frame_reader.cpp
	g++ -c frame_reader.cpp

grayscale.o: grayscale.cpp
	g++ -c grayscale.cpp

out.o: out.cpp
	g++ -c out.cpp

pixel_buffer.o: pixel_buffer.cpp
	g++ -c pixel_buffer.cpp

clean:
	del *.o pipeline.exe
