# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Commit Guidelines

When generating commits, do not mention Claude or any AI assistance. Use standard, descriptive commit messages that focus on the changes made.

## Keyboard: KPrepublic BM68HSRGB Rev2 - Imperial Keymap

### Build Commands

Build the Imperial keymap:
```bash
qmk compile -kb kprepublic/bm68hsrgb/rev2 -km imperial
```

Flash the Imperial keymap:
```bash
qmk flash -kb kprepublic/bm68hsrgb/rev2 -km imperial
```

Alternative make commands:
```bash
make kprepublic/bm68hsrgb/rev2:imperial
make kprepublic/bm68hsrgb/rev2:imperial:flash
```

### Keyboard Architecture

**Hardware Specifications:**
- 65% ANSI layout (68 keys)
- Hotswap switches with per-switch RGB (IS31FL3741 driver)
- Underglow RGB strip (6 LEDs, WS2812 on pin E2)
- ATmega32u4 microcontroller
- USB VID: 0x4B50, PID: 0x1131

**Imperial Keymap Structure:**
- Layer 0 (_BASE): Standard QWERTY layout with arrow keys
- Layer 1 (_FUNCTIONS): Function layer with F-keys, RGB controls, and media keys
- Layers 2-3: Empty placeholder layers for future expansion

### RGB Matrix Implementation

The Imperial keymap implements sophisticated RGB matrix control:

**Custom RGB Functions:**
- `RGB_MATRIX_CUSTOM_Functions` mode for special layer lighting
- Custom keycodes for granular RGB control:
  - `RMT`: RGB Matrix Toggle
  - `RMS`: RGB Matrix Step (cycle modes)
  - `RMIH/RMDH`: RGB Matrix Increase/Decrease Hue
  - `RMIS/RMDS`: RGB Matrix Increase/Decrease Saturation
  - `RMIV/RMDV`: RGB Matrix Increase/Decrease Value (brightness)
- Layer-based RGB mode switching with automatic restoration

**RGB Matrix Features:**
- Max brightness: 180 (per-switch), 150 (underglow)
- Sleep mode enabled for power management
- 40+ animation effects including reactive typing effects
- Custom layer state RGB switching in `layer_state_set_user()`

### Key Custom Code Patterns

**Layer Detection and RGB Control:**
```c
uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);
    switch (layer) {
        case _FUNCTIONS:
            setGameRGB(5);  // Custom RGB for function layer
            break;
        default:
            // Restore previous RGB mode
            if(rgbStatus == true) {
                rgb_matrix_mode_noeeprom(rgbmode);
            }
            break;
    }
    return state;
}
```

**RGB Mode Preservation:**
```c
void matrix_scan_user(void) {
    if(rgb_matrix_config.mode != RGB_MATRIX_CUSTOM_Functions){
        rgbmode = rgb_matrix_config.mode;
    }
}
```

### Special Features

**Function Layer (Layer 1) Access:**
- Hold `MO(1)` key (between Alt and Ctrl on right side)
- Provides access to F1-F12, RGB controls, volume controls, and QK_BOOT

**RGB Control:**
- Standard RGB controls: `RGB_TOG`, `RGB_MOD`, `RGB_HUI`, etc.
- Custom RGB controls: `RMT`, `RMS`, `RMIH`, `RMDH`, etc.
- Layer-specific RGB lighting modes

### Bootloader Mode

Enter bootloader mode by:
- Shorting two-pad footprint left of spacebar while plugged in
- Holding Esc while connecting USB cable
- Using QK_BOOT key (F1 position on function layer)

### File Locations

- Main keymap: `keyboards/kprepublic/bm68hsrgb/rev2/keymaps/imperial/keymap.c`
- Keyboard config: `keyboards/kprepublic/bm68hsrgb/rev2/keyboard.json`
- Hardware config: `keyboards/kprepublic/bm68hsrgb/rev2/config.h`

### Development Notes

- The keymap includes debugging elements (e.g., `Prueba` keycode)
- RGB matrix driver uses IS31FL3741 with specific I2C addressing
- Custom RGB functions are designed for gaming/productivity scenarios
- Layer switching preserves RGB state for seamless user experience
