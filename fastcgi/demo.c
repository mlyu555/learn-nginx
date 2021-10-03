
#include <stdlib.h>
#include "fcgi_stdio.h"

int main(void)
{
    int count = 0;
    while (FCGI_Accept() >= 0)
        printf("Content-type: text/html\r\n"
        "\r\n"
        "<title>FastCGI Hello!</title>"
        "<h1>FastCGI Hello!</h1>"
        "<div>Request number %d running on host : %s </div>\n"
        "<div>QUERY_STRING : %s\n</div>"
        "<div>REMOTE_ADDR : %s\n</div>"
        "<div>REMOTE_PORT : %s\n</div>"
        "<div>REQUEST_METHOD : %s\n</div>"
        "<div>CONTENT_TYPE : %s\n</div>"
        "<div>CONTENT_LENGTH : %s\n</div>"
        "<div>SERVER_PROTOCOL : %s\n</div>"
        "<div>REQUEST_URI : %s\n</div>"
        "<div>SERVER_SOFTWARE : %s\n</div>",
        ++count, getenv("SERVER_NAME"),getenv("QUERY_STRING"),
        getenv("REMOTE_ADDR"), getenv("REMOTE_PORT"), getenv("REQUEST_METHOD"),
        getenv("CONTENT_TYPE"),getenv("CONTENT_LENGTH"),getenv("REQUEST_URI"),
        getenv("SERVER_PROTOCOL"), getenv("SERVER_SOFTWARE"));
    return 0;
}