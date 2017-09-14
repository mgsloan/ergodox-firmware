/* ----------------------------------------------------------------------------
 * ergoDOX layout : QWERTY (modified from the Kinesis layout)
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
 *               2013 Michael Sloan <mgsloan@gmail.com>
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */


#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../../../lib/key-functions/private.h"
#include "../../../main.h"
#include "../matrix.h"
#include "../layout.h"

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // layout: layer 0: default
// unused
0,
// left hand
    _grave,         _1,         _2,      _3,      _4,    _5,   _6,
      _tab,         _Q,         _W,      _E,      _R,    _T,    1,
      _esc,         _A,         _S,      _D,      _F,    _G,
        _4,         _Z,         _X,      _C,      _V,    _B,    1,
    _ctrlL, _semicolon,     _comma,   _dash, _period,
                                                  _altL,  _ctrlL,
                                              0,      0,   _guiL,
                                             _bs, _shiftL, _ctrlL,
// right hand
   _grave, _7,      _8,      _9,      _0,      _dash,     _equal,
       _9, _Y,      _U,      _I,      _O,         _P,         _0,
           _H,      _J,      _K,      _L, _semicolon,     _quote,
_bracketL, _N,      _M,  _comma, _period,     _slash,  _bracketR,
               _arrowL, _arrowD, _arrowU,    _arrowR, _backslash,
  _altR,   _guiR,
 _ctrlR,       0,      0,
 _enter, _shiftR, _space ),


	KB_MATRIX_LAYER(  // layout: layer 1: function and symbol keys
// unused
0,
// left hand
  0,        _F1,        _F2,       _F3,       _F4,       _F5, _F11,
  0,  _bracketL,  _bracketR, _bracketL, _bracketR,         0,    1,
  0, _semicolon,     _slash,     _dash,     _0_kp,_semicolon,
  0,      _6_kp,      _7_kp,     _8_kp,     _9_kp,    _equal,    2,
  0,          0,          0,         0,         0,
                                                             0,  0,
                                                         0,  0,  0,
                                                         0,  0,  0,
// right hand
_F12,       _F6,    _F7,       _F8,       _F9,         _F10,   _power,
   0,         0,  _dash,    _comma,   _period,_currencyUnit, _volumeU,
     _backslash,  _1_kp,        _9,        _0,       _equal, _volumeD,
   2,        _8,  _2_kp,     _3_kp,     _4_kp,        _5_kp,    _mute,
                      0,         0,         0,            0,        0,
  0,  0,
  0,  0,  0,
  0,  0,  0 ),


	KB_MATRIX_LAYER(  // layout: layer 2: keyboard functions
// unused
0,
// left hand
  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,
		          0,  0,
		      0,  0,  0,
		      0,  0,  0,
// right hand
      0,  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,
	  0,  0,  0,  0,  0,  0,
      0,  0,  0,  0,  0,  0,  0,
	      0,  0,  0,  0,  0,
  0,  0,
  0,  0,  0,
  0,  0,  0 ),


	KB_MATRIX_LAYER(  // layout: layer 3: numpad
// unused
0,
// left hand
0,       0, 0, 0, 0, 0, 0,
0,       0, 0, 0, 0, 0, 0,
0,       0, 0, 0, 0, 0,
0,       0, 0, 0, 0, 0, 0,
0, _insert, 0, 0, 0,
                     0, 0,
                  0, 0, 0,
                  0, 0, 0,
// right hand
3, 0,     3, _equal_kp, _div_kp,   _mul_kp, 0,
0, 0, _7_kp,     _8_kp,   _9_kp,   _sub_kp, 0,
   0, _4_kp,     _5_kp,   _6_kp,   _add_kp, 0,
0, 0, _1_kp,     _2_kp,   _3_kp, _enter_kp, 0,
          0,         0, _period, _enter_kp, 0,
0, 0,
0, 0,     0,
0, 0, _0_kp ),

};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// aliases

// basic
#define  kprrel  &kbfun_press_release
#define  ktog    &kbfun_toggle
#define  ktrans  &kbfun_transparent
// --- layer push/pop functions
#define  lpush1   &kbfun_layer_push_1
#define  lpush2   &kbfun_layer_push_2
#define  lpush3   &kbfun_layer_push_3
#define  lpush4   &kbfun_layer_push_4
#define  lpush5   &kbfun_layer_push_5
#define  lpush6   &kbfun_layer_push_6
#define  lpush7   &kbfun_layer_push_7
#define  lpush8   &kbfun_layer_push_8
#define  lpush9   &kbfun_layer_push_9
#define  lpush10  &kbfun_layer_push_10
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  lpop3    &kbfun_layer_pop_3
#define  lpop4    &kbfun_layer_pop_4
#define  lpop5    &kbfun_layer_pop_5
#define  lpop6    &kbfun_layer_pop_6
#define  lpop7    &kbfun_layer_pop_7
#define  lpop8    &kbfun_layer_pop_8
#define  lpop9    &kbfun_layer_pop_9
#define  lpop10   &kbfun_layer_pop_10
// ---

// device
#define  dbtldr  &kbfun_jump_to_bootloader

// special
#define  sshprre  &kbfun_shift_press_release
#define  s2kcap   &kbfun_2_keys_capslock_press_release
#define  slpunum  &kbfun_layer_push_numpad
#define  slponum  &kbfun_layer_pop_numpad

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// Custom code added by mgsloan

//TODO: currently using shift+0 and shift+9 for (), but this means that they
// don't do anything special for shift.

// convenience macros
#define  LAYER         main_arg_layer
#define  LAYER_OFFSET  main_arg_layer_offset
#define  ROW           main_arg_row
#define  COL           main_arg_col
#define  IS_PRESSED    main_arg_is_pressed
#define  WAS_PRESSED   main_arg_was_pressed

#define release(key) _kbfun_press_release(false, key)
#define press(key)   _kbfun_press_release(true, key)
#define pressed(key) _kbfun_is_pressed(key)
#define send()       usb_keyboard_send()

// Backspace is backspace, unless left shift is held, in which case it's delete.

/*
bool delete_held = false;
bool backspace_held = false;
bool lshift_held = false;
bool lshift_key_held = false;
bool backspace_key_held = false;

void send_delete_messages(bool delete_was_held, bool backspace_was_held, bool lshift_was_held) {
  delete_held = lshift_key_held && backspace_key_held;
  backspace_held = !lshift_key_held && backspace_key_held;
  lshift_held = lshift_key_held && !backspace_key_held;
  // if (delete_held)    { _kb_led_1_on(); } else { _kb_led_1_off(); }
  // if (backspace_held) { _kb_led_2_on(); } else { _kb_led_2_off(); }
  // if (lshift_held)    { _kb_led_3_on(); } else { _kb_led_3_off(); }
  if (delete_was_held && !delete_held) release(KEY_DeleteForward);
  if (!delete_was_held && delete_held) press(KEY_DeleteForward);
  if (backspace_was_held && !backspace_held) release(KEY_DeleteBackspace);
  if (!backspace_was_held && backspace_held) press(KEY_DeleteBackspace);
  if (lshift_was_held && !lshift_held) release(KEY_LeftShift);
  if (!lshift_was_held && lshift_held) press(KEY_LeftShift);
  send();
}

void kbfun_lshift(void) {
  bool delete_was_held = delete_held;
  bool backspace_was_held = backspace_held;
  bool lshift_was_held = lshift_held;
  lshift_key_held = IS_PRESSED;
  send_delete_messages(delete_was_held, backspace_was_held, lshift_was_held);
}

void kbfun_shift_delete(void) {
  bool delete_was_held = delete_held;
  bool backspace_was_held = backspace_held;
  bool lshift_was_held = lshift_held;
  backspace_key_held = IS_PRESSED;
  send_delete_messages(delete_was_held, backspace_was_held, lshift_was_held);
}

#define  bs_del &kbfun_shift_delete
#define  lshift &kbfun_lshift
*/

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // press: layer 0: default
// unused
NULL,
// left hand
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, lpush1,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
sshprre, kprrel, kprrel, kprrel, kprrel, kprrel, lpush1,
 kprrel,sshprre,sshprre, kprrel,sshprre,
                                                 kprrel, kprrel,
                                           NULL,   NULL, kprrel,
                                         kprrel, kprrel, kprrel,
// right hand
         kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        sshprre, kprrel, kprrel, kprrel, kprrel, kprrel,sshprre,
                 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
         kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                         kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel,
 kprrel,   NULL,   NULL,
 kprrel, kprrel, kprrel ),


	KB_MATRIX_LAYER(  // press: layer 1: function and symbol keys
// unused
NULL,
// left hand
   NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 dbtldr,sshprre,sshprre, kprrel, kprrel,   NULL,  lpop1,
 ktrans, kprrel, kprrel, kprrel, kprrel,sshprre,
 ktrans, kprrel, kprrel, kprrel, kprrel,sshprre, lpush2,
 ktrans, ktrans, ktrans, ktrans, ktrans,
                                                 ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
// right hand
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        ktrans,   NULL, kprrel,sshprre,sshprre, kprrel, kprrel,
                kprrel, kprrel,sshprre,sshprre,sshprre, kprrel,
        lpush2,sshprre, kprrel, kprrel, kprrel, kprrel, kprrel,
                        ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans,
 ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans ),


	KB_MATRIX_LAYER(  // press: layer 2: keyboard functions
// unused
NULL,
// left hand
 dbtldr,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,
                                                   NULL,   NULL,
                                           NULL,   NULL,   NULL,
                                           NULL,   NULL,   NULL,
// right hand
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
                  NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
                          NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,
   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL ),


	KB_MATRIX_LAYER(  // press: layer 3: numpad
// unused
NULL,
// left hand
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, kprrel, ktrans, ktrans, ktrans,
                                                 ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
// right hand
       slponum, ktrans,slponum, kprrel, kprrel, kprrel, ktrans,
        ktrans, ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
                ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
        ktrans, ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
                        ktrans, ktrans, kprrel, kprrel, ktrans,
 ktrans, ktrans,
 ktrans, ktrans, ktrans,
 ktrans, ktrans, kprrel ),

};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // release: layer 0: default
// unused
NULL,
// left hand
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
 kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
sshprre, kprrel, kprrel, kprrel, kprrel, kprrel,  lpop1,
 kprrel,sshprre,sshprre, kprrel,sshprre,
                                                 kprrel, kprrel,
                                           NULL,   NULL, kprrel,
                                         kprrel, kprrel, kprrel,
// right hand
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
       sshprre, kprrel, kprrel, kprrel, kprrel, kprrel,sshprre,
                kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
                        kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel, kprrel,
 kprrel,   NULL,   NULL,
 kprrel, kprrel, kprrel ),

	KB_MATRIX_LAYER(  // release: layer 1: function and symbol keys
// unused
NULL,
// left hand
   NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 ktrans,sshprre,sshprre, kprrel, kprrel,   NULL,   NULL,
 ktrans, kprrel, kprrel, kprrel, kprrel,sshprre,
 ktrans, kprrel, kprrel, kprrel, kprrel,sshprre,  lpop2,
 ktrans, ktrans, ktrans, ktrans, ktrans,
                                                 ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
// right hand
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
        ktrans,   NULL, kprrel,sshprre,sshprre, kprrel, kprrel,
                kprrel, kprrel,sshprre,sshprre,sshprre, kprrel,
         lpop2,sshprre, kprrel, kprrel, kprrel, kprrel, kprrel,
                        ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans,
 ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans ),


	KB_MATRIX_LAYER(  // release: layer 2: keyboard functions
// unused
NULL,
// left hand
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,
                                                   NULL,   NULL,
                                           NULL,   NULL,   NULL,
                                           NULL,   NULL,   NULL,
// right hand
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
                  NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
                          NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,
   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL ),


	KB_MATRIX_LAYER(  // release: layer 3: numpad
// unused
NULL,
// left hand
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, ktrans, ktrans, ktrans, ktrans, ktrans, ktrans,
 ktrans, kprrel, ktrans, ktrans, ktrans,
                                                 ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
                                         ktrans, ktrans, ktrans,
// right hand
          NULL, ktrans,   NULL, kprrel, kprrel, kprrel, ktrans,
        ktrans, ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
                ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
        ktrans, ktrans, kprrel, kprrel, kprrel, kprrel, ktrans,
                        ktrans, ktrans, kprrel, kprrel, ktrans,
 ktrans, ktrans,
 ktrans, ktrans, ktrans,
 ktrans, ktrans, kprrel ),


	KB_MATRIX_LAYER(  // release: layer 3: nothing (just making sure unused
			  // functions don't get compiled out)
// unused
NULL,
// other
 kprrel, lpush8,  lpop8,   NULL,   NULL,   NULL,   NULL,   NULL,
   ktog, lpush9,  lpop9,   NULL,   NULL,   NULL,   NULL,   NULL,
 ktrans,lpush10, lpop10,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush1,  lpop1,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush2,  lpop2, dbtldr,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush3,  lpop3,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush4,  lpop4, s2kcap,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush5,  lpop5,slpunum,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush6,  lpop6,slponum,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush7,  lpop7,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL )

};
