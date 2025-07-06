 /* Copyright 2022 bdtc123
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
#    include "is31fl3741.h"
#endif

#ifdef RGB_MATRIX_ENABLE

const is31fl3741_led_t g_is31fl3741_leds[RGB_MATRIX_LED_COUNT] = {
    {0, SW6_CS1, SW5_CS1, SW4_CS1},
    {0, SW6_CS2, SW5_CS2, SW4_CS2},
    {0, SW6_CS3, SW5_CS3, SW4_CS3},
    {0, SW6_CS4, SW5_CS4, SW4_CS4},
    {0, SW6_CS5, SW5_CS5, SW4_CS5},
    {0, SW6_CS6, SW5_CS6, SW4_CS6},
    {0, SW6_CS7, SW5_CS7, SW4_CS7},
    {0, SW6_CS8, SW5_CS8, SW4_CS8},
    {0, SW1_CS18, SW1_CS17, SW1_CS16},
    {0, SW2_CS18, SW2_CS17, SW2_CS16},
    {0, SW3_CS18, SW3_CS17, SW3_CS16},
    {0, SW4_CS18, SW4_CS17, SW4_CS16},
    {0, SW5_CS18, SW5_CS17, SW5_CS16},
    {0, SW6_CS18, SW6_CS17, SW6_CS16},
    {0, SW7_CS18, SW7_CS17, SW7_CS16},

    {0, SW9_CS1, SW8_CS1, SW7_CS1},
    {0, SW9_CS2, SW8_CS2, SW7_CS2},
    {0, SW9_CS3, SW8_CS3, SW7_CS3},
    {0, SW9_CS4, SW8_CS4, SW7_CS4},
    {0, SW9_CS5, SW8_CS5, SW7_CS5},
    {0, SW9_CS6, SW8_CS6, SW7_CS6},
    {0, SW9_CS7, SW8_CS7, SW7_CS7},
    {0, SW9_CS8, SW8_CS8, SW7_CS8},
    {0, SW1_CS21, SW1_CS20, SW1_CS19},
    {0, SW2_CS21, SW2_CS20, SW2_CS19},
    {0, SW3_CS21, SW3_CS20, SW3_CS19},
    {0, SW4_CS21, SW4_CS20, SW4_CS19},
    {0, SW5_CS21, SW5_CS20, SW5_CS19},
    {0, SW6_CS21, SW6_CS20, SW6_CS19},
    {0, SW7_CS21, SW7_CS20, SW7_CS19},

    {0, SW1_CS12, SW1_CS11, SW1_CS10},
    {0, SW2_CS12, SW2_CS11, SW2_CS10},
    {0, SW3_CS12, SW3_CS11, SW3_CS10},
    {0, SW4_CS12, SW4_CS11, SW4_CS10},
    {0, SW5_CS12, SW5_CS11, SW5_CS10},
    {0, SW6_CS12, SW6_CS11, SW6_CS10},
    {0, SW7_CS12, SW7_CS11, SW7_CS10},
    {0, SW8_CS12, SW8_CS11, SW8_CS10},
    {0, SW1_CS24, SW1_CS23, SW1_CS22},
    {0, SW2_CS24, SW2_CS23, SW2_CS22},
    {0, SW3_CS24, SW3_CS23, SW3_CS22},
    {0, SW4_CS24, SW4_CS23, SW4_CS22},
    {0, SW6_CS24, SW6_CS23, SW6_CS22},
    {0, SW7_CS24, SW7_CS23, SW7_CS22},

    {0, SW1_CS15, SW1_CS14, SW1_CS13},
    {0, SW3_CS15, SW3_CS14, SW3_CS13},
    {0, SW4_CS15, SW4_CS14, SW4_CS13},
    {0, SW5_CS15, SW5_CS14, SW5_CS13},
    {0, SW6_CS15, SW6_CS14, SW6_CS13},
    {0, SW7_CS15, SW7_CS14, SW7_CS13},
    {0, SW8_CS15, SW8_CS14, SW8_CS13},
    {0, SW1_CS27, SW1_CS26, SW1_CS25},
    {0, SW2_CS27, SW2_CS26, SW2_CS25},
    {0, SW3_CS27, SW3_CS26, SW3_CS25},
    {0, SW4_CS27, SW4_CS26, SW4_CS25},
    {0, SW5_CS27, SW5_CS26, SW5_CS25},
    {0, SW6_CS27, SW6_CS26, SW6_CS25},
    {0, SW7_CS27, SW7_CS26, SW7_CS25},

    {0, SW3_CS1, SW2_CS1, SW1_CS1},
    {0, SW3_CS2, SW2_CS2, SW1_CS2},
    {0, SW3_CS3, SW2_CS3, SW1_CS3},
    {0, SW3_CS7, SW2_CS7, SW1_CS7},
    {0, SW2_CS30, SW2_CS29, SW2_CS28},
    {0, SW3_CS30, SW3_CS29, SW3_CS28},
    {0, SW4_CS30, SW4_CS29, SW4_CS28},
    {0, SW5_CS30, SW5_CS29, SW5_CS28},
    {0, SW6_CS30, SW6_CS29, SW6_CS28},
    {0, SW7_CS30, SW7_CS29, SW7_CS28}

};
led_config_t g_led_config = { {
    {  0,      1,  2,      3,      4,     5,   6,       7,       8,  9,  10,  11,     12,    13,  14 },
    {  15,    16, 17,     18,     19,    20,  21,      22,      23, 24,  25,  26,     27,    28,  29 },
    {  30,    31, 32,     33,     34,    35,  36,      37,      38, 39,  40,  41, NO_LED,    42,  43 },
    {  44,NO_LED, 45,     46,     47,    48,  49,      50,      51, 52,  53,  54,     55,    56,  57 },
    {  58,    59, 60, NO_LED, NO_LED,NO_LED,  61,  NO_LED,  NO_LED, 62,  63,  64,     65,    66,  67 }
}, {
    {0,0},{15,0},{30,0},{45,0},{60,0},{75,0},{90,0},{105,0},{120,0},{135,0},{150,0},{165,0},{180,0},{203,0},{224,0},
	{4,16},{23,16},{38,16},{53,16},{68,16},{83,16},{98,16},{113,16},{128,16},{143,16},{158,16},{173,16},{188,16},{206,16},{224,16},
	{6,32},{26,32},{41,32},{56,32},{71,32},{86,32},{101,32},{116,32},{131,32},{146,32},{161,32},{176,32},{201,32},{224,32},
	{9,48},{34,48},{49,48},{64,48},{79,48},{94,48},{109,48},{124,48},{139,48},{154,48},{169,48},{189,48},{210,48},{224,48},
        {   2,  64 }, {  21,  64 }, {  39,  64 },                                           {  96,  64 },                             { 150,  64 }, { 165,  64 }, { 180,  64 }, { 195,  64 }, { 210,  64 }, { 224,  64 }
}, {
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 1, 1, 4, 1, 1, 1, 1, 1, 1
} };

bool rgb_matrix_indicators_user(void){
    switch(biton32(layer_state)){
        case 1:
             rgb_matrix_set_color(1, 0x00, 0xFF, 0x00);
             rgb_matrix_set_color(14, 0xDC, 0x14, 0x3C);
             rgb_matrix_set_color(47, 0xFF, 0xD7, 0x0);
             rgb_matrix_set_color(34, 0xFF, 0xD7, 0x0);

            for (uint8_t i = 2; i < 13; i++) {
                //RGB_MATRIX_TEST_LED_FLAGS();
                rgb_matrix_set_color(i, 0x00, 0xFF, 0xFF);
            };

            rgb_matrix_set_color(40, 0xD2, 0x69, 0xE1);
            rgb_matrix_set_color(41, 0xD2, 0x69, 0xE1);
            rgb_matrix_set_color(63, 0xFF, 0x45, 0x00);

            //Volumen
            rgb_matrix_set_color(56, 0x8B, 0x00, 0x00);
            rgb_matrix_set_color(66, 0x8B, 0x00, 0x00);
            rgb_matrix_set_color(67, 0x8B, 0x00, 0x00);

            //Pagos
            rgb_matrix_set_color(22, 0x00, 0xFF, 0x00);
            break;

        default:
            rgb_matrix_set_color(63, 0x2C, 0x3E, 0x50);//FN
            rgb_matrix_set_color(50, 0x80, 0x80, 0x00);//N
            rgb_matrix_set_color(43, 0x00, 0xFF, 0x00);//PGUP
            rgb_matrix_set_color(2, 0x00, 0x00, 0x80);
            rgb_matrix_set_color(47, 0x80, 0x00, 0x00);//C
            rgb_matrix_set_color(48, 0x80, 0x00, 0x00);//V
            rgb_matrix_set_color(45, 0x00, 0x80, 0x00);//Z
            rgb_matrix_set_color(32, 0x80, 0x00, 0x80);//S
            rgb_matrix_set_color(18, 0x80, 0x80, 0x00);//E
            rgb_matrix_set_color(46, 0x00, 0x00, 0x80);//X
            rgb_matrix_set_color(12, 0xFF, 0x45, 0x00);//=
            rgb_matrix_set_color(40, 0x00, 0xFF, 0xFF);//;
            rgb_matrix_set_color(0, 0xEB, 0xF5, 0xFB);//ESC
            rgb_matrix_set_color(61, 0xEB, 0xF5, 0xFB);//SPC
            rgb_matrix_set_color(44, 0xFF, 0x45, 0x00);//LSHIFT
            rgb_matrix_set_color(31, 0x80, 0x00, 0x80);//A
            rgb_matrix_set_color(33, 0x80, 0x00, 0x80);//D
            rgb_matrix_set_color(17, 0x80, 0x00, 0x80);//W
            rgb_matrix_set_color(15, 0x00, 0xFF, 0xFF);//W


            break;
    }
    return true;
}


bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(30, 0xFF, 0xFF, 0xFF);
    }
    return true;
}

#endif
