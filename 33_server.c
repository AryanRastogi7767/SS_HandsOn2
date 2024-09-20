#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
int main(void) {

  struct sockaddr_in serv, cli;

  int sd = socket(AF_INET, SOCK_STREAM, 0);

  serv.sin_family = AF_UNIX;
  serv.sin_addr.s_addr = INADDR_ANY;
  serv.sin_port = htons(5055);

  int b = bind(sd, &serv, sizeof(serv));
  if (b == -1) {
    printf("Error in bind\n");
  }
  listen(sd, 1);

  int nsd = accept(sd, &cli, sizeof(cli));
  char *buf = "Hello this is server!!.";
  write(nsd, buf, strlen(buf));

  return 0;
}
