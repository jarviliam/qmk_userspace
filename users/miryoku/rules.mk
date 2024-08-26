# Copyright 2019 Manna Harbour
# https://github.com/manna-harbour/miryoku

MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
TAP_DANCE_ENABLE = yes
CAPS_WORD_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
ACHORDION_ENABLE ?= yes

INTROSPECTION_KEYMAP_C = manna-harbour_miryoku.c # keymaps

ifeq ($(strip $(ACHORDION_ENABLE)), yes)
	OPT_DEFS += -DACHORDION_ENABLE
	SRC += features/achordion.c
endif

include $(USER_PATH)/custom_rules.mk

include $(USER_PATH)/post_rules.mk
