
#include "ngx_config.h"
#include "ngx_core.h"
#include "ngx_http.h"

// step 4
static char *ngx_http_demo_set(ngx_conf_t *cf, ngx_command_t *cmd, void *conf);

// step 5
static ngx_int_t ngx_http_demo_handler(ngx_http_request_t *r);


// step 2
static ngx_http_module_t ngx_http_demo_module_ctx = {
    NULL,   // preconfiguration
    NULL,   // postconfiguration

    NULL,   // create_main_conf
    NULL,   // init_main_conf

    NULL,   // create_srv_conf
    NULL,   // merge_srv_conf

    NULL,   // create_loc_conf
    NULL,   // merge_loc_conf
};

// step 3
static ngx_command_t ngx_http_demo_commands[] = {
    {
        ngx_string("demo_cmd"),
        NGX_HTTP_MAIN_CONF | NGX_HTTP_SRV_CONF | NGX_HTTP_LOC_CONF | NGX_CONF_NOARGS,
        ngx_http_demo_set,      // goto step 4
		NGX_HTTP_LOC_CONF_OFFSET,   // todo
        0,
        NULL
    },
    ngx_null_command   // 固定, 类似C字符串'\0'
};


// step 1
ngx_module_t ngx_http_demo_module = {
    NGX_MODULE_V1,
    &ngx_http_demo_module_ctx,      // goto step 2
    ngx_http_demo_commands,         // goto step 3
    NGX_HTTP_MODULE,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NGX_MODULE_V1_PADDING
};



static char *ngx_http_demo_set(ngx_conf_t *cf, ngx_command_t *cmd, void *conf) {

    // code ...
    ngx_http_core_loc_conf_t *clcf;
    clcf = ngx_http_conf_get_module_loc_conf(cf, ngx_http_core_module);

    clcf->handler = ngx_http_demo_handler;  // goto step 5

    return NGX_OK;
}


static ngx_int_t ngx_http_demo_handler(ngx_http_request_t *r) {
    // code ...

    return NGX_OK;
}