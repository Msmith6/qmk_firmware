/*
Copyright 2020 MisonoWorks

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// matrix
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

// pins
#define MATRIX_ROW_PINS { D0, D1, D2, D3 }
#define MATRIX_COL_PINS { F0, F1, F4, F5, F6, F7, B0, B1, B2, B3, D4, D6}

// diode mode
#define DIODE_DIRECTION COL2ROW

// debouncing, NKRO, mouse keys speed 
#define FORCE_NKRO
#define MK_3_SPEED
#define TERMINAL_HELP

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGB_DI_PIN B6
#ifdef RGB_DI_PIN
#define RGBLED_NUM 3
#endif

