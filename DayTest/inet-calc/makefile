.PHONY:all
all: Calc_Client Calc_Server

Calc_Client:Calc_Client.cc
	g++ -o $@ $^ -std=c++11 -ljsoncpp

Calc_Server:Calc_Server.cc
	g++ -o $@ $^ -std=c++11 -lpthread -ljsoncpp

.PHONY:clean
clean:
	rm -f Calc_Client Calc_Server