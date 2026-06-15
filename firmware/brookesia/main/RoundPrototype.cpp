#include "RoundPrototype.hpp"

#ifdef ESP_UTILS_LOG_TAG
#   undef ESP_UTILS_LOG_TAG
#endif
#define ESP_UTILS_LOG_TAG "BS:RoundPrototype"
#include "esp_lib_utils.h"

namespace esp_brookesia::apps {

RoundPrototype *RoundPrototype::_instance = nullptr;

RoundPrototype *RoundPrototype::requestInstance(bool use_status_bar, bool use_navigation_bar)
{
    if (_instance == nullptr) {
        _instance = new RoundPrototype(use_status_bar, use_navigation_bar);
    }
    return _instance;
}

RoundPrototype::RoundPrototype(bool use_status_bar, bool use_navigation_bar):
    systems::phone::App("Round UI", nullptr, true, use_status_bar, use_navigation_bar)
{
}

bool RoundPrototype::run(void)
{
    lv_obj_t *scr = lv_scr_act();
    lv_obj_set_style_bg_color(scr, lv_color_hex(0x05070A), 0);
    lv_obj_set_style_bg_opa(scr, LV_OPA_COVER, 0);
    lv_obj_clear_flag(scr, LV_OBJ_FLAG_SCROLLABLE);

    lv_area_t area = getVisualArea();
    int w = lv_area_get_width(&area);
    int h = lv_area_get_height(&area);
    int side = LV_MIN(w, h);
    int safe_side = side * 70 / 100;

    lv_obj_t *circle = lv_obj_create(scr);
    lv_obj_set_size(circle, side, side);
    lv_obj_center(circle);
    lv_obj_set_style_radius(circle, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_opa(circle, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(circle, 3, 0);
    lv_obj_set_style_border_color(circle, lv_color_hex(0x2DD4BF), 0);
    lv_obj_clear_flag(circle, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_t *panel = lv_obj_create(scr);
    lv_obj_set_size(panel, safe_side, safe_side);
    lv_obj_center(panel);
    lv_obj_set_flex_flow(panel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(panel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_all(panel, 20, 0);
    lv_obj_set_style_pad_row(panel, 10, 0);
    lv_obj_set_style_radius(panel, 26, 0);
    lv_obj_set_style_bg_color(panel, lv_color_hex(0x101820), 0);
    lv_obj_set_style_bg_opa(panel, LV_OPA_90, 0);
    lv_obj_set_style_border_width(panel, 1, 0);
    lv_obj_set_style_border_color(panel, lv_color_hex(0x344256), 0);
    lv_obj_clear_flag(panel, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_t *title = lv_label_create(panel);
    lv_label_set_text(title, "Round UI Prototype");
    lv_obj_set_style_text_font(title, &lv_font_montserrat_24, 0);
    lv_obj_set_style_text_color(title, lv_color_white(), 0);

    lv_obj_t *subtitle = lv_label_create(panel);
    lv_label_set_text(subtitle, "Safe zone, touch targets, and risky apps");
    lv_obj_set_width(subtitle, lv_pct(100));
    lv_label_set_long_mode(subtitle, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_align(subtitle, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_color(subtitle, lv_color_hex(0x9CA3AF), 0);

    addCard(panel, "Settings", "Centered 70% list, smaller font, reachable sliders.", lv_color_hex(0x38BDF8));
    addCard(panel, "Calculator", "Keypad and result area stay inside safe square.", lv_color_hex(0xF97316));
    addCard(panel, "Media demos", "Avoid corner controls; prefer center rail controls.", lv_color_hex(0xA78BFA));
    addCard(panel, "Camera / Video", "Use center crop preview; keep status text centered.", lv_color_hex(0x22C55E));

    return true;
}

bool RoundPrototype::back(void)
{
    ESP_UTILS_CHECK_FALSE_RETURN(notifyCoreClosed(), false, "Notify core closed failed");
    return true;
}

void RoundPrototype::addCard(lv_obj_t *parent, const char *title, const char *body, lv_color_t accent)
{
    lv_obj_t *card = lv_obj_create(parent);
    lv_obj_set_size(card, lv_pct(100), 72);
    lv_obj_set_flex_flow(card, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(card, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_hor(card, 16, 0);
    lv_obj_set_style_pad_ver(card, 8, 0);
    lv_obj_set_style_pad_row(card, 2, 0);
    lv_obj_set_style_radius(card, 16, 0);
    lv_obj_set_style_bg_color(card, lv_color_hex(0x17212F), 0);
    lv_obj_set_style_bg_opa(card, LV_OPA_COVER, 0);
    lv_obj_set_style_border_width(card, 2, 0);
    lv_obj_set_style_border_color(card, accent, 0);
    lv_obj_clear_flag(card, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_t *title_label = lv_label_create(card);
    lv_label_set_text(title_label, title);
    lv_obj_set_width(title_label, lv_pct(100));
    lv_obj_set_style_text_font(title_label, &lv_font_montserrat_20, 0);
    lv_obj_set_style_text_color(title_label, accent, 0);

    lv_obj_t *body_label = lv_label_create(card);
    lv_label_set_text(body_label, body);
    lv_obj_set_width(body_label, lv_pct(100));
    lv_label_set_long_mode(body_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_color(body_label, lv_color_hex(0xE5E7EB), 0);
}

} // namespace esp_brookesia::apps
