/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.org/license.html
 */

#include "gdriver.c"

#undef GDISP_DRIVER_LIST

#ifdef CONFIG_VFX_OUTPUT_WS2812
    #define GDISP_DRIVER_LIST GDISPVMT_WS2812
    #include "drivers/gdisp/WS2812/gdisp_lld_WS2812.c"
#elif defined(CONFIG_VFX_OUTPUT_ST7735)
    #define GDISP_DRIVER_LIST GDISPVMT_ST7735
    #include "drivers/gdisp/ST7735/gdisp_lld_ST7735.c"
#elif defined(CONFIG_VFX_OUTPUT_ST7789)
    #define GDISP_DRIVER_LIST GDISPVMT_ST7789
    #include "drivers/gdisp/ST7789/gdisp_lld_ST7789.c"
#else
    #define GDISP_DRIVER_LIST GDISPVMT_CUBE0414
    #include "drivers/gdisp/CUBE0414/gdisp_lld_CUBE0414.c"
#endif
