all:Agenda

Agenda: Agenda.o Data.o Horario.o TestaAgenda.o
	g++ Agenda.o Data.o Horario.o TestaAgenda.o -o Agenda -g

TestaAgenda.o: TestaAgenda.cpp
	g++ -c TestaAgenda.cpp

Agenda.o: Agenda.cpp Agenda.h 
	g++ -c Agenda.cpp

Data.o: Data.cpp Data.h 
	g++ -c Data.cpp

Horario: Horario.cpp Horario.h
	g++ -c Horario.cpp Horario.h

clean:
	rm *.o