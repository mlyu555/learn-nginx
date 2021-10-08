#include <stdio.h>
#include <string.h>

#include "ngx_config.h"
#include "ngx_core.h"

#include "ngx_list.h"
#include "ngx_palloc.h"
#include "ngx_string.h"


#define N 10        // 数组大小

// c/core/ngx_palloc.o ../objs/src/os/unix/ngx_alloc.o
// ../objs/src/core/ngx_string.o: In function `ngx_sort':
// /home/yulm/learn-nginx/nginx-1.21.3/src/core/ngx_string.c:2053: undefined reference to `ngx_cycle'
// collect2: error: ld returned 1 exit status
volatile ngx_cycle_t *ngx_cycle;


// ../objs/src/os/unix/ngx_alloc.o: In function `ngx_memalign':
// /home/yulm/learn-nginx/nginx-1.21.3/src/os/unix/ngx_alloc.c:60: undefined reference to `ngx_log_error_core'
// collect2: error: ld returned 1 exit status
void ngx_log_error_core(ngx_uint_t level, ngx_log_t *log,
			ngx_err_t err, const char *fmt, ...)
{
}


void print_list(ngx_list_t *l) {
	ngx_list_part_t *p = &(l->part);

	while (p) {

		int i = 0;
		for (i = 0;i < p->nelts;i ++) {
			printf("%s\n", (char*)(((ngx_str_t*)p->elts + i)->data));
		}
		p = p->next;
		printf(" -------------------------- \n");
	}

}

int main(int argc, char *argv[]) {

    ngx_pool_t *pool = ngx_create_pool(1024, NULL);

    ngx_list_t *l = ngx_list_create(pool, N, sizeof(ngx_str_t));

    int i = 0;
    char *cstr;
    for (i = 0; i < 24; i++) {
		ngx_str_t *ptr = ngx_list_push(l);

		char *buf = ngx_palloc(pool, 32);
		sprintf(buf, "ngx_list_t item %d", i+1);

		ptr->len = strlen(buf);
		ptr->data = buf;
    }

    print_list(l);

    return 0;
}