#include "lvgl.h"
#include "fbdev.h"
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "src/widgets/label/lv_label.h"
//#include "src/ts_driver/tslib_drv.h"

#include "components.h"

//#define DISP_BUF_SIZE (480 * 800)




int main(void) {
    /*LVGL init*/

    lv_init();

    /*Linux frame buffer device init*/
    fbdev_init();

    // open /dev/console to get the console fd
    int console_fd = open("/dev/console", O_RDWR);

    /*A small buffer for LittlevGL to draw the screen's content*/
    static lv_color_t buf[480 * 800];

    /*Initialize a descriptor for the buffer*/
    static lv_disp_draw_buf_t disp_buf;
    lv_disp_draw_buf_init(&disp_buf, buf, NULL, 480 * 800);

    /*Initialize and register a display driver*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf = &disp_buf;
    disp_drv.flush_cb = fbdev_flush;
    disp_drv.hor_res = 800;
    disp_drv.ver_res = 480;
    lv_disp_drv_register(&disp_drv);

//
//    tslib_init();
//
//    /*Initialize and register a input device driver*/
//    static lv_indev_drv_t indev_drv;
//    lv_indev_drv_init(&indev_drv);
//    indev_drv.type = LV_INDEV_TYPE_POINTER;
//    indev_drv.read_cb = tslib_read;
//    lv_indev_drv_register(&indev_drv);

        create_layout();









    /*Handle LitlevGL tasks (tickless mode)*/
    while (1) {
        lv_tick_inc(5);
        lv_timer_handler();
        usleep(5000);
    }
    // close console fd if CTRL+C is pressed
    close(console_fd);

    return 0;
}