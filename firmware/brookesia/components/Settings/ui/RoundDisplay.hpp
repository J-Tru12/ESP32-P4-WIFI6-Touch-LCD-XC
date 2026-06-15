#pragma once

#include "bsp/esp-bsp.h"
#include "lvgl.h"

namespace esp_brookesia::apps::round_display {

static inline bool is_round_screen()
{
    return BSP_LCD_H_RES == BSP_LCD_V_RES;
}

static inline int min_side()
{
    if (is_round_screen()) {
        return LV_MIN((int)BSP_LCD_H_RES, (int)BSP_LCD_V_RES);
    }
    return LV_MIN((int)LV_HOR_RES, (int)LV_VER_RES);
}

static inline int safe_width(int rectangular_margin)
{
    if (!is_round_screen()) {
        return LV_MAX(1, (int)LV_HOR_RES - rectangular_margin * 2);
    }
    return LV_MAX(1, min_side() * 70 / 100);
}

static inline int safe_height(int rectangular_margin)
{
    if (!is_round_screen()) {
        return LV_MAX(1, (int)LV_VER_RES - rectangular_margin * 2);
    }
    return LV_MAX(1, min_side() * 72 / 100);
}

static inline int row_height(int base_height)
{
    if (!is_round_screen()) {
        return base_height;
    }
    return LV_MAX(56, min_side() * 9 / 100);
}

static inline int slider_row_height(int base_height)
{
    if (!is_round_screen()) {
        return base_height;
    }
    return LV_MAX(86, min_side() * 14 / 100);
}

static inline int password_y(int base_y)
{
    if (!is_round_screen()) {
        return base_y;
    }
    return min_side() * 16 / 100;
}

static inline int keyboard_height()
{
    if (!is_round_screen()) {
        return LV_MAX(220, (int)LV_VER_RES / 2);
    }
    return min_side() * 36 / 100;
}

static inline int keyboard_bottom_offset()
{
    if (!is_round_screen()) {
        return 24;
    }
    return min_side() * 15 / 100;
}

static inline const lv_font_t *font_30()
{
    return is_round_screen() ? &lv_font_montserrat_24 : &lv_font_montserrat_30;
}

} // namespace esp_brookesia::apps::round_display
