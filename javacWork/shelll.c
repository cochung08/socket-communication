#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE * fp;
	char buffer[80];
	fp = popen("/home/cochung/workspaceC++/APClient/poi.sh", "r");
	fgets(buffer, sizeof(buffer), fp);
	printf("%s", buffer);

	pclose(fp);

	exit(0);
	return 0;

}
