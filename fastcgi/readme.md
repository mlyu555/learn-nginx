# 关于FastCGI程序的编写和部署

## 步骤

### 1. 准备环境

1. fcgi
2. spawn-fcgi
3. nginx

### 2. 编写demo

```c

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
```

编译
g++ demo.c -o democgi -lfcgi

如果提示找不到动态库，请在LD_LIBRARY_PATH或/etc/ld.so.conf中添加fcgi的安装路径

$export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/../fcgi/lib/