/* ResidualVM - A 3D game interpreter
 *
 * ResidualVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the AUTHORS
 * file distributed with this source distribution.
 *
 * Additional copyright for this file:
 * Copyright (C) 1999-2000 Revolution Software Ltd.
 * This code is based on source code created by Revolution Software,
 * used with permission.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "p4_generic.h"

namespace ICB {

typedef struct {
	uint8 *pBacklog;
	uint8 *pPointer;
	char *pBuffer;
} _drvKeyStatus;

void WriteKey(char key); // Adds a keypress to the buffer

extern bool KeyWaiting();

extern int32 ReadKey(char *key);
extern void GetKeyStatus(_drvKeyStatus *s);
extern void Clear_key_buffer();

} // End of namespace ICB

#endif
