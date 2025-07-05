// zmq_rep.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <zmq_addon.hpp>

static zmq::context_t ctx;


int main()
{
	zmq::socket_t sock(ctx, zmq::socket_type::rep);
	sock.bind("tcp://127.0.0.1:5555");
	
	while (1)
	{
		zmq::message_t z_in;
		sock.recv(z_in);

		int x = std::stoi(z_in.to_string());
		x = x * x;
		
		std::string msg_out = std::to_string(x);
		zmq::message_t z_out(msg_out);

		sock.send(z_out, zmq::send_flags::none);
		std::cout
			<< "sending: " << msg_out << std::endl;

	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
