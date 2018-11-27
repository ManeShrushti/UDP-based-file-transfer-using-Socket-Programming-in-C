## UDP BASED TEXT FILE TRANSFER ON AN AD HOC NETWORK

**This is a [UDP](https://www.geeksforgeeks.org/computer-network-user-datagram-protocol-udp/) based application program which allows to connect two machines on an [ad hoc network](https://en.wikipedia.org/wiki/Wireless_ad_hoc_network), and transfer text files
using the [Socket Programming in C](https://www.geeksforgeeks.org/socket-programming-cc)**


## Usage

* Create an ad hoc network using the script file as:
	1) Make changes in IP addresses in the script file when using on two different machines on same network.
	2) Make sure the network essid is same for both the machines to be connected in one ad hoc network.
	3) Save the file and run the script file using ./script
* Run Program in an Ad hoc newtwork:
	1) On one machine compile the udpServer.c program using the command:
		>gcc udpServer.c -o server

	2) In another machine compile udpClient.c program using the command:
		>gcc udpCLient.c -o client

 	4) Run the server program on first machine using,
		>./server

	5) Run the client program in second machine using,
		>./client <IP Address>


## Limitations

Can transfer only single line text messages of size upto 5024 characters.

