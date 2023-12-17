
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "lily58.h"

#define L_BASE 0
#define L_SYMB (1 << 1)
#define L_MISC (1 << 2)
#define L_MEDIA (1 << 3)
#define L_MEDIA_TRI (L_MEDIA | L_MISC | L_SYMB)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    break;
  case L_MISC:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Miscellanous");
    break;
  case L_SYMB:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Symbols");
    break;
  case L_MEDIA:
  case L_MEDIA_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Media");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}
