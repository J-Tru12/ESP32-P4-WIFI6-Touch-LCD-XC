#pragma once

#include "lvgl.h"
#include "systems/phone/esp_brookesia_phone_app.hpp"

namespace esp_brookesia::apps {

class RoundPrototype: public systems::phone::App {
public:
    static RoundPrototype *requestInstance(bool use_status_bar = false, bool use_navigation_bar = false);
    ~RoundPrototype() override = default;

protected:
    RoundPrototype(bool use_status_bar, bool use_navigation_bar);

    bool run(void) override;
    bool back(void) override;

private:
    static RoundPrototype *_instance;

    static void addCard(lv_obj_t *parent, const char *title, const char *body, lv_color_t accent);
};

} // namespace esp_brookesia::apps
