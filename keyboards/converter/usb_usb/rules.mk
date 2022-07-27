# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
# https://docs.qmk.fm/#/squeezing_avr
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes        # Mouse keys
EXTRAKEY_ENABLE = yes       	# Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
USB_HID_ENABLE = yes
CUSTOM_MATRIX = yes
KEY_OVERRIDE_ENABLE = yes	# https://docs.qmk.fm/#/feature_key_overrides for shift
LTO_ENABLE = yes
#EXTRAFLAGS+= -mrelax
#EXTRAFLAGS+= -mcall-prologues

TAP_DANCE_ENABLE = no
# AUTO_SHIFT_ENABLE = yes

GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no
#SPACE_CADET_ENABLE = no

UNICODE_ENABLE   = no
SWAP_HANDS_ENABLE= no

SRC += custom_matrix.cpp

DEFAULT_FOLDER = converter/usb_usb/hasu

LAYOUTS = fullsize_ansi fullsize_iso
