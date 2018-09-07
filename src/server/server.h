#include <iostream>


class Server{
public:
	
	start();
	stop();



private:
	int listen();
	int accept();
	int makeEvent();
	int routine();


private:
	int socket;
	int worknum;
}

int loadcfg()
{
    return 0;
}

int start()
{
    return 0;
}

int distribute()
{
    return 0;
}


int stop()
{
    return 0;
}