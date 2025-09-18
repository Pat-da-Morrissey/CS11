run: main.o OregonTrail.o Player.o
	g++ -o run main.o OregonTrail.o Player.o

main.o: main.cpp
	g++ -c main.cpp

OregonTrail.o: OregonTrail.cpp OregonTrail.h
	g++ -c OregonTrail.cpp

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

clean:
	rm -f run *.o