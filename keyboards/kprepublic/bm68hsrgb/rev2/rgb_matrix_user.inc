RGB_MATRIX_EFFECT(Functions)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool Functions(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }

    for (uint8_t i = 1; i < 13; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, 0xE8, 0xBE, 0x3C);
    }

    for (uint8_t i = 16; i < 24; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, 0x12, 0xC2, 0x00);
    }

    rgb_matrix_set_color(14,  0xFF, 0xFF, 0xFF);
    rgb_matrix_set_color(29, 0xB8, 0x00, 0x00);
    rgb_matrix_set_color(43, 0xFF, 0xD2, 0x00);
    rgb_matrix_set_color(58, 0x00, 0x8A, 0xFF);
    rgb_matrix_set_color(67, 0x5A, 0x00, 0xB6);

    rgb_matrix_set_color(59, 0xA1, 0x19, 0x19);
    rgb_matrix_set_color(57, 0xA1, 0x19, 0x19);
    rgb_matrix_set_color(66, 0xA1, 0x19, 0x19);
    rgb_matrix_set_color(25, 0x00, 0x97, 0xC2);
    rgb_matrix_set_color(31, 0x00, 0x97, 0xC2);
    rgb_matrix_set_color(32, 0x00, 0x97, 0xC2);
    rgb_matrix_set_color(60, 0x00, 0x97, 0xC2);
    rgb_matrix_set_color(48, 0x00, 0x97, 0xC2);
    rgb_matrix_set_color(50, 0x00, 0x97, 0xC2);
    rgb_matrix_set_color(52, 0x00, 0x97, 0xC2);

    //return led_max < DRIVER_LED_TOTAL;
    return true;
}

#endif  // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
