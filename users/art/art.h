#pragma once
#include QMK_KEYBOARD_H
#include "art_user_config.c"

#define CTL_ALT(kc) (CTL_ALT_START + ((kc) & 0xff))

extern bool is_win;
#define BLINKING_INTERVAL 25
#define TYPING_INTERVAL 20
#define LONG_TYPING_INTERVAL 50

enum layer_names {
#if SPLIT75_PUBLIC_USE == 1 && defined(KEYBOARD_wheatfield_split75)
  BASE,
  QWERTY,
#else
  QWERTY,
  BASE,
#endif
  
  WORKMAN,
#if defined(KEYBOARD_wheatfield_split75)
  CONFIG,
  LAYOUT_CHG,
  QWERTY_MOD,
#elif defined(KEYBOARD_ergodone)
  FKEYS,
  CTRL_NAV,
  SHIFT_NAV,
#endif

  MEDIA,
  COMBOS,
  //STRINGS,
  NAV,
  NUMPAD,
  GIT,
  GIT_C,
  GIT_R,
  GIT_S
};

enum custom_keycodes_art {
  CTRL_CTV = SAFE_RANGE,
  CTRL_LCTV,
  CTRL_CAV,
  BEAT_BROWSER,
  NEUTRAL_COPY,
  SARCASM,
  LMB_SPAM,

  TOG_OS,
  CTR_ALT,
  CTR_ALT_SHIFT,
  OS_CTRL,
  OS_WIN,

  TILD_BLOCK,
  ALL_BEST,
  BRACES,
  DASHES,
  PARENTHS,
  SM_READPNT,
  STARS,
  QUOTES,
  QUOTES_RU,

  ADMINS,
  PRESCRIPTION,
  FOURS,
  
  G_ADD,
  G_BRCH,
  G_C,
  G_CHEC,	
  G_CHER,
  G_COMM,
  G_DEV,
  G_DIFF,
  G_FTCH,
  G_LOG,
  G_MERG,
  G_PULL,
  G_PUSH,
  G_R,
  G_RBASE,
  G_RVERT,
  G_RST,
  G_S,
  G_STAT,
  G_STSH,
  G_SHOW,

  CTL_ALT_START,
  CTL_ALT_END = CTL_ALT_START + 0xff,

  NEW_SAFE_RANGE  //for keymap specific codes
};
