/* ScummVM - Graphic Adventure Engine
*
* ScummVM is the legal property of its developers, whose names
* are too numerous to list here. Please refer to the COPYRIGHT
* file distributed with this source distribution.
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

// This file was generated by larryScale_generator.js.
// Do not edit directly! Instead, edit the generator script and run it.

inline void scalePixelTo2x2(
	const MarginedBitmap<Color> &src,
	const MarginedBitmap<bool> &linePixels,
	int x, int y,
	// Out parameters
	Color &topLeft, Color &topRight, Color &bottomLeft, Color &bottomRight
) {
	const Color pixel = src.get(x, y);
	const EqualityMatrix matrix = getEqualityMatrix(src.getPointerTo(x, y), src.getStride());

	// Note: There is a case label for every possible value, so we don't need a default label, but one is added to avoid any compiler warnings.
	switch (matrix) {
	default: case 0x00 /*⠀⠂⠀*/:	case 0x07 /*⠃⠃⠀*/:	case 0x17 /*⠃⠃⠂*/:	case 0x1c /*⠀⠃⠃*/:	case 0x1d /*⠂⠃⠃*/:	case 0x1e /*⠁⠃⠃*/:	case 0x1f /*⠃⠃⠃*/:	case 0x27 /*⠃⠃⠄*/:
	case 0x2f /*⠃⠃⠅*/:	case 0x37 /*⠃⠃⠆*/:	case 0x3c /*⠀⠃⠇*/:	case 0x3d /*⠂⠃⠇*/:	case 0x3e /*⠁⠃⠇*/:	case 0x3f /*⠃⠃⠇*/:	case 0x47 /*⠃⠇⠀*/:	case 0x4f /*⠃⠇⠁*/:
	case 0x50 /*⠀⠆⠂*/:	case 0x51 /*⠂⠆⠂*/:	case 0x52 /*⠁⠆⠂*/:	case 0x54 /*⠀⠇⠂*/:	case 0x55 /*⠂⠇⠂*/:	case 0x57 /*⠃⠇⠂*/:	case 0x5c /*⠀⠇⠃*/:	case 0x5d /*⠂⠇⠃*/:
	case 0x5e /*⠁⠇⠃*/:	case 0x5f /*⠃⠇⠃*/:	case 0x67 /*⠃⠇⠄*/:	case 0x6f /*⠃⠇⠅*/:	case 0x70 /*⠀⠆⠆*/:	case 0x71 /*⠂⠆⠆*/:	case 0x72 /*⠁⠆⠆*/:	case 0x73 /*⠃⠆⠆*/:
	case 0x74 /*⠀⠇⠆*/:	case 0x75 /*⠂⠇⠆*/:	case 0x76 /*⠁⠇⠆*/:	case 0x77 /*⠃⠇⠆*/:	case 0x78 /*⠀⠆⠇*/:	case 0x79 /*⠂⠆⠇*/:	case 0x7a /*⠁⠆⠇*/:	case 0x7b /*⠃⠆⠇*/:
	case 0x7c /*⠀⠇⠇*/:	case 0x7d /*⠂⠇⠇*/:	case 0x7e /*⠁⠇⠇*/:	case 0x7f /*⠃⠇⠇*/:	case 0x97 /*⠇⠃⠂*/:	case 0x9c /*⠄⠃⠃*/:	case 0x9d /*⠆⠃⠃*/:	case 0x9e /*⠅⠃⠃*/:
	case 0x9f /*⠇⠃⠃*/:	case 0xa7 /*⠇⠃⠄*/:	case 0xaa /*⠅⠂⠅*/:	case 0xaf /*⠇⠃⠅*/:	case 0xb7 /*⠇⠃⠆*/:	case 0xbc /*⠄⠃⠇*/:	case 0xbd /*⠆⠃⠇*/:	case 0xbe /*⠅⠃⠇*/:
	case 0xbf /*⠇⠃⠇*/:	case 0xc1 /*⠆⠆⠀*/:	case 0xc5 /*⠆⠇⠀*/:	case 0xc7 /*⠇⠇⠀*/:	case 0xc9 /*⠆⠆⠁*/:	case 0xcb /*⠇⠆⠁*/:	case 0xcd /*⠆⠇⠁*/:	case 0xcf /*⠇⠇⠁*/:
	case 0xd1 /*⠆⠆⠂*/:	case 0xd3 /*⠇⠆⠂*/:	case 0xd5 /*⠆⠇⠂*/:	case 0xd7 /*⠇⠇⠂*/:	case 0xd9 /*⠆⠆⠃*/:	case 0xdb /*⠇⠆⠃*/:	case 0xdc /*⠄⠇⠃*/:	case 0xdd /*⠆⠇⠃*/:
	case 0xde /*⠅⠇⠃*/:	case 0xdf /*⠇⠇⠃*/:	case 0xe5 /*⠆⠇⠄*/:	case 0xe7 /*⠇⠇⠄*/:	case 0xe9 /*⠆⠆⠅*/:	case 0xeb /*⠇⠆⠅*/:	case 0xed /*⠆⠇⠅*/:	case 0xef /*⠇⠇⠅*/:
	case 0xf0 /*⠄⠆⠆*/:	case 0xf1 /*⠆⠆⠆*/:	case 0xf2 /*⠅⠆⠆*/:	case 0xf3 /*⠇⠆⠆*/:	case 0xf4 /*⠄⠇⠆*/:	case 0xf5 /*⠆⠇⠆*/:	case 0xf6 /*⠅⠇⠆*/:	case 0xf7 /*⠇⠇⠆*/:
	case 0xf8 /*⠄⠆⠇*/:	case 0xf9 /*⠆⠆⠇*/:	case 0xfa /*⠅⠆⠇*/:	case 0xfb /*⠇⠆⠇*/:	case 0xfc /*⠄⠇⠇*/:	case 0xfd /*⠆⠇⠇*/:	case 0xfe /*⠅⠇⠇*/:	case 0xff /*⠇⠇⠇*/:
		topLeft = topRight = bottomLeft = bottomRight = pixel;
		break;
	case 0x11 /*⠂⠂⠂*/:	case 0x15 /*⠂⠃⠂*/:
		topLeft = topRight = pixel;
		bottomLeft = bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		break;
	case 0x29 /*⠂⠂⠅*/:
		topLeft = topRight = bottomRight = pixel;
		bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		break;
	case 0x44 /*⠀⠇⠀*/:	case 0x45 /*⠂⠇⠀*/:
		topLeft = bottomLeft = pixel;
		topRight = bottomRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		break;
	case 0x49 /*⠂⠆⠁*/:	case 0x4a /*⠁⠆⠁*/:
		topLeft = topRight = bottomLeft = pixel;
		bottomRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		break;
	case 0x92 /*⠅⠂⠂*/:	case 0x94 /*⠄⠃⠂*/:
		topLeft = topRight = bottomLeft = pixel;
		bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		break;
	case 0xa4 /*⠄⠃⠄*/:
		topLeft = bottomLeft = bottomRight = pixel;
		topRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		break;
	case 0x53 /*⠃⠆⠂*/:	case 0x56 /*⠁⠇⠂*/:	case 0x59 /*⠂⠆⠃*/:	case 0x5a /*⠁⠆⠃*/:	case 0x5b /*⠃⠆⠃*/:	case 0xd2 /*⠅⠆⠂*/:	case 0xd4 /*⠄⠇⠂*/:	case 0xd6 /*⠅⠇⠂*/:
	case 0xda /*⠅⠆⠃*/:
		if (linePixels.get(x, y)) {
			topLeft = topRight = bottomLeft = bottomRight = pixel;
		} else {
			topLeft = topRight = bottomLeft = bottomRight = pixel;
		}
		break;
	case 0x2a /*⠁⠂⠅*/:
		topLeft = topRight = bottomRight = pixel;
		bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		break;
	case 0x8a /*⠅⠂⠁*/:	case 0x8f /*⠇⠃⠁*/:
		topLeft = topRight = bottomLeft = pixel;
		bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		break;
	case 0xa2 /*⠅⠂⠄*/:	case 0xe3 /*⠇⠆⠄*/:
		topLeft = bottomLeft = bottomRight = pixel;
		topRight = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		break;
	case 0xa8 /*⠄⠂⠅*/:
		topLeft = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		topRight = bottomLeft = bottomRight = pixel;
		break;
	case 0x25 /*⠂⠃⠄*/:
		topLeft = bottomRight = pixel;
		topRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		break;
	case 0x13 /*⠃⠂⠂*/:	case 0x19 /*⠂⠂⠃*/:	case 0x1b /*⠃⠂⠃*/:	case 0x31 /*⠂⠂⠆*/:	case 0x33 /*⠃⠂⠆*/:	case 0x35 /*⠂⠃⠆*/:	case 0x39 /*⠂⠂⠇*/:	case 0x3b /*⠃⠂⠇*/:
	case 0x91 /*⠆⠂⠂*/:	case 0x93 /*⠇⠂⠂*/:	case 0x95 /*⠆⠃⠂*/:	case 0x99 /*⠆⠂⠃*/:	case 0x9b /*⠇⠂⠃*/:	case 0xb1 /*⠆⠂⠆*/:	case 0xb3 /*⠇⠂⠆*/:	case 0xb5 /*⠆⠃⠆*/:
	case 0xb9 /*⠆⠂⠇*/:	case 0xbb /*⠇⠂⠇*/:
		if (linePixels.get(x, y)) {
			topLeft = topRight = pixel;
			bottomLeft = bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		} else {
			topLeft = topRight = bottomLeft = bottomRight = pixel;
		}
		break;
	case 0x2b /*⠃⠂⠅*/:	case 0xa9 /*⠆⠂⠅*/:	case 0xab /*⠇⠂⠅*/:
		if (linePixels.get(x, y)) {
			topLeft = topRight = bottomRight = pixel;
			bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		} else {
			topLeft = topRight = bottomLeft = bottomRight = pixel;
		}
		break;
	case 0x46 /*⠁⠇⠀*/:	case 0x4c /*⠀⠇⠁*/:	case 0x4d /*⠂⠇⠁*/:	case 0x4e /*⠁⠇⠁*/:	case 0x64 /*⠀⠇⠄*/:	case 0x65 /*⠂⠇⠄*/:	case 0x66 /*⠁⠇⠄*/:	case 0x6c /*⠀⠇⠅*/:
	case 0x6d /*⠂⠇⠅*/:	case 0x6e /*⠁⠇⠅*/:	case 0xc4 /*⠄⠇⠀*/:	case 0xc6 /*⠅⠇⠀*/:	case 0xcc /*⠄⠇⠁*/:	case 0xce /*⠅⠇⠁*/:	case 0xe4 /*⠄⠇⠄*/:	case 0xe6 /*⠅⠇⠄*/:
	case 0xec /*⠄⠇⠅*/:	case 0xee /*⠅⠇⠅*/:
		if (linePixels.get(x, y)) {
			topLeft = bottomLeft = pixel;
			topRight = bottomRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		} else {
			topLeft = topRight = bottomLeft = bottomRight = pixel;
		}
		break;
	case 0x4b /*⠃⠆⠁*/:	case 0x69 /*⠂⠆⠅*/:	case 0x6a /*⠁⠆⠅*/:	case 0x6b /*⠃⠆⠅*/:	case 0xca /*⠅⠆⠁*/:	case 0xea /*⠅⠆⠅*/:
		if (linePixels.get(x, y)) {
			topLeft = topRight = bottomLeft = pixel;
			bottomRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		} else {
			topLeft = topRight = bottomLeft = bottomRight = pixel;
		}
		break;
	case 0x96 /*⠅⠃⠂*/:	case 0x9a /*⠅⠂⠃*/:	case 0xb2 /*⠅⠂⠆*/:	case 0xb4 /*⠄⠃⠆*/:	case 0xb6 /*⠅⠃⠆*/:	case 0xba /*⠅⠂⠇*/:
		if (linePixels.get(x, y)) {
			topLeft = topRight = bottomLeft = pixel;
			bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		} else {
			topLeft = topRight = bottomLeft = bottomRight = pixel;
		}
		break;
	case 0xa6 /*⠅⠃⠄*/:	case 0xac /*⠄⠃⠅*/:	case 0xae /*⠅⠃⠅*/:
		if (linePixels.get(x, y)) {
			topLeft = bottomLeft = bottomRight = pixel;
			topRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		} else {
			topLeft = topRight = bottomLeft = bottomRight = pixel;
		}
		break;
	case 0x01 /*⠂⠂⠀*/:	case 0x09 /*⠂⠂⠁*/:	case 0x0f /*⠃⠃⠁*/:
		topLeft = topRight = pixel;
		bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		break;
	case 0x04 /*⠀⠃⠀*/:	case 0x84 /*⠄⠃⠀*/:	case 0x87 /*⠇⠃⠀*/:
		topLeft = bottomLeft = pixel;
		topRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		break;
	case 0x10 /*⠀⠂⠂*/:	case 0x12 /*⠁⠂⠂*/:	case 0x14 /*⠀⠃⠂*/:
		topLeft = topRight = pixel;
		bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		break;
	case 0x21 /*⠂⠂⠄*/:	case 0xe1 /*⠆⠆⠄*/:
		topLeft = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : pixel;
		topRight = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		bottomLeft = bottomRight = pixel;
		break;
	case 0x24 /*⠀⠃⠄*/:
		topLeft = !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		topRight = bottomRight = pixel;
		bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		break;
	case 0x40 /*⠀⠆⠀*/:	case 0x41 /*⠂⠆⠀*/:	case 0x42 /*⠁⠆⠀*/:	case 0xc3 /*⠇⠆⠀*/:
		topLeft = bottomLeft = pixel;
		topRight = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		bottomRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		break;
	case 0x48 /*⠀⠆⠁*/:
		topLeft = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		topRight = bottomRight = pixel;
		bottomLeft = !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		break;
	case 0x90 /*⠄⠂⠂*/:
		topLeft = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		topRight = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : pixel;
		bottomLeft = bottomRight = pixel;
		break;
	case 0xd8 /*⠄⠆⠃*/:
		if (linePixels.get(x, y)) {
			topLeft = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
			topRight = bottomLeft = bottomRight = pixel;
		} else {
			topLeft = topRight = bottomLeft = bottomRight = pixel;
		}
		break;
	case 0x02 /*⠁⠂⠀*/:	case 0x20 /*⠀⠂⠄*/:	case 0x22 /*⠁⠂⠄*/:
		topLeft = bottomRight = pixel;
		topRight = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		break;
	case 0x08 /*⠀⠂⠁*/:	case 0x80 /*⠄⠂⠀*/:	case 0x88 /*⠄⠂⠁*/:
		topLeft = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		topRight = bottomLeft = pixel;
		bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		break;
	case 0x0a /*⠁⠂⠁*/:
		topLeft = topRight = pixel;
		bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		break;
	case 0x28 /*⠀⠂⠅*/:
		topLeft = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		topRight = bottomRight = pixel;
		bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		break;
	case 0x82 /*⠅⠂⠀*/:
		topLeft = bottomLeft = pixel;
		topRight = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		break;
	case 0xa0 /*⠄⠂⠄*/:
		topLeft = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		topRight = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		bottomLeft = bottomRight = pixel;
		break;
	case 0x2d /*⠂⠃⠅*/:	case 0xa5 /*⠆⠃⠄*/:	case 0xad /*⠆⠃⠅*/:
		if (linePixels.get(x, y)) {
			topLeft = bottomRight = pixel;
			topRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
			bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		} else {
			topLeft = topRight = bottomLeft = bottomRight = pixel;
		}
		break;
	case 0x05 /*⠂⠃⠀*/:
		topLeft = pixel;
		topRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		break;
	case 0x06 /*⠁⠃⠀*/:
		if (linePixels.get(x, y)) {
			topLeft = bottomLeft = pixel;
			topRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
			bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		} else {
			topLeft = topRight = bottomLeft = bottomRight = pixel;
		}
		break;
	case 0x18 /*⠀⠂⠃*/:	case 0x1a /*⠁⠂⠃*/:	case 0x30 /*⠀⠂⠆*/:	case 0x32 /*⠁⠂⠆*/:	case 0x36 /*⠁⠃⠆*/:	case 0x38 /*⠀⠂⠇*/:	case 0x3a /*⠁⠂⠇*/:
		if (linePixels.get(x, y)) {
			topLeft = topRight = pixel;
			bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
			bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		} else {
			topLeft = topRight = bottomLeft = bottomRight = pixel;
		}
		break;
	case 0x26 /*⠁⠃⠄*/:	case 0x2c /*⠀⠃⠅*/:	case 0x2e /*⠁⠃⠅*/:
		if (linePixels.get(x, y)) {
			topLeft = bottomRight = pixel;
			topRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
			bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		} else {
			topLeft = topRight = bottomLeft = bottomRight = pixel;
		}
		break;
	case 0x68 /*⠀⠆⠅*/:	case 0xc8 /*⠄⠆⠁*/:	case 0xe8 /*⠄⠆⠅*/:
		if (linePixels.get(x, y)) {
			topLeft = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
			topRight = bottomLeft = pixel;
			bottomRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		} else {
			topLeft = topRight = bottomLeft = bottomRight = pixel;
		}
		break;
	case 0x98 /*⠄⠂⠃*/:	case 0xb0 /*⠄⠂⠆*/:	case 0xb8 /*⠄⠂⠇*/:
		if (linePixels.get(x, y)) {
			topLeft = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
			topRight = bottomLeft = pixel;
			bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		} else {
			topLeft = topRight = bottomLeft = bottomRight = pixel;
		}
		break;
	case 0xc0 /*⠄⠆⠀*/:
		if (linePixels.get(x, y)) {
			topLeft = bottomLeft = pixel;
			topRight = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
			bottomRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		} else {
			topLeft = topRight = bottomLeft = bottomRight = pixel;
		}
		break;
	case 0x16 /*⠁⠃⠂*/:	case 0x34 /*⠀⠃⠆*/:
		if (linePixels.get(x, y)) {
			topLeft = !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
			topRight = pixel;
			bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
			bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		} else {
			topLeft = topRight = bottomLeft = bottomRight = pixel;
		}
		break;
	case 0x58 /*⠀⠆⠃*/:	case 0xd0 /*⠄⠆⠂*/:
		if (linePixels.get(x, y)) {
			topLeft = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
			topRight = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : pixel;
			bottomLeft = !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
			bottomRight = pixel;
		} else {
			topLeft = topRight = bottomLeft = bottomRight = pixel;
		}
		break;
	case 0x03 /*⠃⠂⠀*/:
		if (linePixels.get(x, y)) {
			topLeft = topRight = pixel;
			bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
			bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		} else {
			topLeft = bottomLeft = bottomRight = pixel;
			topRight = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		}
		break;
	case 0x0b /*⠃⠂⠁*/:	case 0x81 /*⠆⠂⠀*/:	case 0x83 /*⠇⠂⠀*/:	case 0x89 /*⠆⠂⠁*/:	case 0x8b /*⠇⠂⠁*/:
		if (linePixels.get(x, y)) {
			topLeft = topRight = pixel;
			bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
			bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		} else {
			topLeft = topRight = bottomLeft = pixel;
			bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		}
		break;
	case 0x0c /*⠀⠃⠁*/:	case 0x0e /*⠁⠃⠁*/:	case 0x86 /*⠅⠃⠀*/:	case 0x8c /*⠄⠃⠁*/:	case 0x8e /*⠅⠃⠁*/:
		if (linePixels.get(x, y)) {
			topLeft = bottomLeft = pixel;
			topRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
			bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		} else {
			topLeft = topRight = bottomLeft = pixel;
			bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		}
		break;
	case 0x23 /*⠃⠂⠄*/:	case 0xa1 /*⠆⠂⠄*/:	case 0xa3 /*⠇⠂⠄*/:
		if (linePixels.get(x, y)) {
			topLeft = bottomRight = pixel;
			topRight = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
			bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		} else {
			topLeft = bottomLeft = bottomRight = pixel;
			topRight = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		}
		break;
	case 0x60 /*⠀⠆⠄*/:	case 0x62 /*⠁⠆⠄*/:	case 0x63 /*⠃⠆⠄*/:	case 0xc2 /*⠅⠆⠀*/:	case 0xe0 /*⠄⠆⠄*/:	case 0xe2 /*⠅⠆⠄*/:
		if (linePixels.get(x, y)) {
			topLeft = bottomLeft = pixel;
			topRight = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
			bottomRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		} else {
			topLeft = bottomLeft = bottomRight = pixel;
			topRight = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		}
		break;
	case 0x0d /*⠂⠃⠁*/:	case 0x85 /*⠆⠃⠀*/:	case 0x8d /*⠆⠃⠁*/:
		if (linePixels.get(x, y)) {
			topLeft = pixel;
			topRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
			bottomLeft = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
			bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		} else {
			topLeft = topRight = bottomLeft = pixel;
			bottomRight = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		}
		break;
	case 0x43 /*⠃⠆⠀*/:	case 0x61 /*⠂⠆⠄*/:
		if (linePixels.get(x, y)) {
			topLeft = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : pixel;
			topRight = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
			bottomLeft = pixel;
			bottomRight = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		} else {
			topLeft = bottomLeft = bottomRight = pixel;
			topRight = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		}
		break;
	}
}

inline void scalePixelTo2x1(
	const MarginedBitmap<Color> &src,
	const MarginedBitmap<bool> &linePixels,
	int x, int y,
	// Out parameters
	Color &left, Color &right
) {
	const Color pixel = src.get(x, y);
	const EqualityMatrix matrix = getEqualityMatrix(src.getPointerTo(x, y), src.getStride());

	// Note: There is a case label for every possible value, so we don't need a default label, but one is added to avoid any compiler warnings.
	switch (matrix) {
	default: case 0x00 /*⠀⠂⠀*/:	case 0x01 /*⠂⠂⠀*/:	case 0x02 /*⠁⠂⠀*/:	case 0x07 /*⠃⠃⠀*/:	case 0x08 /*⠀⠂⠁*/:	case 0x09 /*⠂⠂⠁*/:	case 0x0a /*⠁⠂⠁*/:	case 0x0f /*⠃⠃⠁*/:
	case 0x10 /*⠀⠂⠂*/:	case 0x11 /*⠂⠂⠂*/:	case 0x12 /*⠁⠂⠂*/:	case 0x14 /*⠀⠃⠂*/:	case 0x15 /*⠂⠃⠂*/:	case 0x17 /*⠃⠃⠂*/:	case 0x1c /*⠀⠃⠃*/:	case 0x1d /*⠂⠃⠃*/:
	case 0x1e /*⠁⠃⠃*/:	case 0x1f /*⠃⠃⠃*/:	case 0x20 /*⠀⠂⠄*/:	case 0x21 /*⠂⠂⠄*/:	case 0x22 /*⠁⠂⠄*/:	case 0x25 /*⠂⠃⠄*/:	case 0x27 /*⠃⠃⠄*/:	case 0x29 /*⠂⠂⠅*/:
	case 0x2a /*⠁⠂⠅*/:	case 0x2f /*⠃⠃⠅*/:	case 0x37 /*⠃⠃⠆*/:	case 0x3c /*⠀⠃⠇*/:	case 0x3d /*⠂⠃⠇*/:	case 0x3e /*⠁⠃⠇*/:	case 0x3f /*⠃⠃⠇*/:	case 0x47 /*⠃⠇⠀*/:
	case 0x49 /*⠂⠆⠁*/:	case 0x4a /*⠁⠆⠁*/:	case 0x4f /*⠃⠇⠁*/:	case 0x50 /*⠀⠆⠂*/:	case 0x51 /*⠂⠆⠂*/:	case 0x52 /*⠁⠆⠂*/:	case 0x54 /*⠀⠇⠂*/:	case 0x55 /*⠂⠇⠂*/:
	case 0x57 /*⠃⠇⠂*/:	case 0x5c /*⠀⠇⠃*/:	case 0x5d /*⠂⠇⠃*/:	case 0x5e /*⠁⠇⠃*/:	case 0x5f /*⠃⠇⠃*/:	case 0x67 /*⠃⠇⠄*/:	case 0x6f /*⠃⠇⠅*/:	case 0x70 /*⠀⠆⠆*/:
	case 0x71 /*⠂⠆⠆*/:	case 0x72 /*⠁⠆⠆*/:	case 0x73 /*⠃⠆⠆*/:	case 0x74 /*⠀⠇⠆*/:	case 0x75 /*⠂⠇⠆*/:	case 0x76 /*⠁⠇⠆*/:	case 0x77 /*⠃⠇⠆*/:	case 0x78 /*⠀⠆⠇*/:
	case 0x79 /*⠂⠆⠇*/:	case 0x7a /*⠁⠆⠇*/:	case 0x7b /*⠃⠆⠇*/:	case 0x7c /*⠀⠇⠇*/:	case 0x7d /*⠂⠇⠇*/:	case 0x7e /*⠁⠇⠇*/:	case 0x7f /*⠃⠇⠇*/:	case 0x80 /*⠄⠂⠀*/:
	case 0x88 /*⠄⠂⠁*/:	case 0x8a /*⠅⠂⠁*/:	case 0x8f /*⠇⠃⠁*/:	case 0x90 /*⠄⠂⠂*/:	case 0x92 /*⠅⠂⠂*/:	case 0x94 /*⠄⠃⠂*/:	case 0x97 /*⠇⠃⠂*/:	case 0x9c /*⠄⠃⠃*/:
	case 0x9d /*⠆⠃⠃*/:	case 0x9e /*⠅⠃⠃*/:	case 0x9f /*⠇⠃⠃*/:	case 0xa0 /*⠄⠂⠄*/:	case 0xa2 /*⠅⠂⠄*/:	case 0xa4 /*⠄⠃⠄*/:	case 0xa7 /*⠇⠃⠄*/:	case 0xa8 /*⠄⠂⠅*/:
	case 0xaa /*⠅⠂⠅*/:	case 0xaf /*⠇⠃⠅*/:	case 0xb7 /*⠇⠃⠆*/:	case 0xbc /*⠄⠃⠇*/:	case 0xbd /*⠆⠃⠇*/:	case 0xbe /*⠅⠃⠇*/:	case 0xbf /*⠇⠃⠇*/:	case 0xc1 /*⠆⠆⠀*/:
	case 0xc5 /*⠆⠇⠀*/:	case 0xc7 /*⠇⠇⠀*/:	case 0xc9 /*⠆⠆⠁*/:	case 0xcb /*⠇⠆⠁*/:	case 0xcd /*⠆⠇⠁*/:	case 0xcf /*⠇⠇⠁*/:	case 0xd1 /*⠆⠆⠂*/:	case 0xd3 /*⠇⠆⠂*/:
	case 0xd5 /*⠆⠇⠂*/:	case 0xd7 /*⠇⠇⠂*/:	case 0xd9 /*⠆⠆⠃*/:	case 0xdb /*⠇⠆⠃*/:	case 0xdc /*⠄⠇⠃*/:	case 0xdd /*⠆⠇⠃*/:	case 0xde /*⠅⠇⠃*/:	case 0xdf /*⠇⠇⠃*/:
	case 0xe1 /*⠆⠆⠄*/:	case 0xe3 /*⠇⠆⠄*/:	case 0xe5 /*⠆⠇⠄*/:	case 0xe7 /*⠇⠇⠄*/:	case 0xe9 /*⠆⠆⠅*/:	case 0xeb /*⠇⠆⠅*/:	case 0xed /*⠆⠇⠅*/:	case 0xef /*⠇⠇⠅*/:
	case 0xf0 /*⠄⠆⠆*/:	case 0xf1 /*⠆⠆⠆*/:	case 0xf2 /*⠅⠆⠆*/:	case 0xf3 /*⠇⠆⠆*/:	case 0xf4 /*⠄⠇⠆*/:	case 0xf5 /*⠆⠇⠆*/:	case 0xf6 /*⠅⠇⠆*/:	case 0xf7 /*⠇⠇⠆*/:
	case 0xf8 /*⠄⠆⠇*/:	case 0xf9 /*⠆⠆⠇*/:	case 0xfa /*⠅⠆⠇*/:	case 0xfb /*⠇⠆⠇*/:	case 0xfc /*⠄⠇⠇*/:	case 0xfd /*⠆⠇⠇*/:	case 0xfe /*⠅⠇⠇*/:	case 0xff /*⠇⠇⠇*/:
		left = right = pixel;
		break;
	case 0x44 /*⠀⠇⠀*/:	case 0x45 /*⠂⠇⠀*/:
		left = pixel;
		right = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		break;
	case 0x03 /*⠃⠂⠀*/:	case 0x0b /*⠃⠂⠁*/:	case 0x13 /*⠃⠂⠂*/:	case 0x18 /*⠀⠂⠃*/:	case 0x19 /*⠂⠂⠃*/:	case 0x1a /*⠁⠂⠃*/:	case 0x1b /*⠃⠂⠃*/:	case 0x23 /*⠃⠂⠄*/:
	case 0x26 /*⠁⠃⠄*/:	case 0x2b /*⠃⠂⠅*/:	case 0x2c /*⠀⠃⠅*/:	case 0x2d /*⠂⠃⠅*/:	case 0x2e /*⠁⠃⠅*/:	case 0x30 /*⠀⠂⠆*/:	case 0x31 /*⠂⠂⠆*/:	case 0x32 /*⠁⠂⠆*/:
	case 0x33 /*⠃⠂⠆*/:	case 0x35 /*⠂⠃⠆*/:	case 0x36 /*⠁⠃⠆*/:	case 0x38 /*⠀⠂⠇*/:	case 0x39 /*⠂⠂⠇*/:	case 0x3a /*⠁⠂⠇*/:	case 0x3b /*⠃⠂⠇*/:	case 0x4b /*⠃⠆⠁*/:
	case 0x53 /*⠃⠆⠂*/:	case 0x56 /*⠁⠇⠂*/:	case 0x59 /*⠂⠆⠃*/:	case 0x5a /*⠁⠆⠃*/:	case 0x5b /*⠃⠆⠃*/:	case 0x68 /*⠀⠆⠅*/:	case 0x69 /*⠂⠆⠅*/:	case 0x6a /*⠁⠆⠅*/:
	case 0x6b /*⠃⠆⠅*/:	case 0x81 /*⠆⠂⠀*/:	case 0x83 /*⠇⠂⠀*/:	case 0x89 /*⠆⠂⠁*/:	case 0x8b /*⠇⠂⠁*/:	case 0x91 /*⠆⠂⠂*/:	case 0x93 /*⠇⠂⠂*/:	case 0x95 /*⠆⠃⠂*/:
	case 0x96 /*⠅⠃⠂*/:	case 0x98 /*⠄⠂⠃*/:	case 0x99 /*⠆⠂⠃*/:	case 0x9a /*⠅⠂⠃*/:	case 0x9b /*⠇⠂⠃*/:	case 0xa1 /*⠆⠂⠄*/:	case 0xa3 /*⠇⠂⠄*/:	case 0xa5 /*⠆⠃⠄*/:
	case 0xa6 /*⠅⠃⠄*/:	case 0xa9 /*⠆⠂⠅*/:	case 0xab /*⠇⠂⠅*/:	case 0xac /*⠄⠃⠅*/:	case 0xad /*⠆⠃⠅*/:	case 0xae /*⠅⠃⠅*/:	case 0xb0 /*⠄⠂⠆*/:	case 0xb1 /*⠆⠂⠆*/:
	case 0xb2 /*⠅⠂⠆*/:	case 0xb3 /*⠇⠂⠆*/:	case 0xb4 /*⠄⠃⠆*/:	case 0xb5 /*⠆⠃⠆*/:	case 0xb6 /*⠅⠃⠆*/:	case 0xb8 /*⠄⠂⠇*/:	case 0xb9 /*⠆⠂⠇*/:	case 0xba /*⠅⠂⠇*/:
	case 0xbb /*⠇⠂⠇*/:	case 0xc8 /*⠄⠆⠁*/:	case 0xca /*⠅⠆⠁*/:	case 0xd2 /*⠅⠆⠂*/:	case 0xd4 /*⠄⠇⠂*/:	case 0xd6 /*⠅⠇⠂*/:	case 0xd8 /*⠄⠆⠃*/:	case 0xda /*⠅⠆⠃*/:
	case 0xe8 /*⠄⠆⠅*/:	case 0xea /*⠅⠆⠅*/:
		if (linePixels.get(x, y)) {
			left = right = pixel;
		} else {
			left = right = pixel;
		}
		break;
	case 0x04 /*⠀⠃⠀*/:	case 0x05 /*⠂⠃⠀*/:	case 0x84 /*⠄⠃⠀*/:	case 0x87 /*⠇⠃⠀*/:
		left = pixel;
		right = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		break;
	case 0x24 /*⠀⠃⠄*/:
		left = !linePixels.get(x - 1, y) ? src.get(x - 1, y) : !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		right = pixel;
		break;
	case 0x40 /*⠀⠆⠀*/:	case 0x41 /*⠂⠆⠀*/:	case 0x42 /*⠁⠆⠀*/:	case 0xc3 /*⠇⠆⠀*/:
		left = pixel;
		right = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		break;
	case 0x48 /*⠀⠆⠁*/:
		left = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		right = pixel;
		break;
	case 0x46 /*⠁⠇⠀*/:	case 0x4c /*⠀⠇⠁*/:	case 0x4d /*⠂⠇⠁*/:	case 0x4e /*⠁⠇⠁*/:	case 0x64 /*⠀⠇⠄*/:	case 0x65 /*⠂⠇⠄*/:	case 0x66 /*⠁⠇⠄*/:	case 0x6c /*⠀⠇⠅*/:
	case 0x6d /*⠂⠇⠅*/:	case 0x6e /*⠁⠇⠅*/:	case 0xc4 /*⠄⠇⠀*/:	case 0xc6 /*⠅⠇⠀*/:	case 0xcc /*⠄⠇⠁*/:	case 0xce /*⠅⠇⠁*/:	case 0xe4 /*⠄⠇⠄*/:	case 0xe6 /*⠅⠇⠄*/:
	case 0xec /*⠄⠇⠅*/:	case 0xee /*⠅⠇⠅*/:
		if (linePixels.get(x, y)) {
			left = pixel;
			right = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		} else {
			left = right = pixel;
		}
		break;
	case 0x28 /*⠀⠂⠅*/:
		left = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		right = pixel;
		break;
	case 0x82 /*⠅⠂⠀*/:
		left = pixel;
		right = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		break;
	case 0x06 /*⠁⠃⠀*/:	case 0x0c /*⠀⠃⠁*/:	case 0x0d /*⠂⠃⠁*/:	case 0x0e /*⠁⠃⠁*/:	case 0x85 /*⠆⠃⠀*/:	case 0x86 /*⠅⠃⠀*/:	case 0x8c /*⠄⠃⠁*/:	case 0x8d /*⠆⠃⠁*/:
	case 0x8e /*⠅⠃⠁*/:
		if (linePixels.get(x, y)) {
			left = pixel;
			right = !linePixels.get(x + 1, y) ? src.get(x + 1, y) : !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		} else {
			left = right = pixel;
		}
		break;
	case 0x16 /*⠁⠃⠂*/:	case 0x34 /*⠀⠃⠆*/:
		if (linePixels.get(x, y)) {
			left = !linePixels.get(x - 1, y) ? src.get(x - 1, y) : !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
			right = pixel;
		} else {
			left = right = pixel;
		}
		break;
	case 0x43 /*⠃⠆⠀*/:	case 0x60 /*⠀⠆⠄*/:	case 0x61 /*⠂⠆⠄*/:	case 0x62 /*⠁⠆⠄*/:	case 0x63 /*⠃⠆⠄*/:	case 0xc0 /*⠄⠆⠀*/:	case 0xc2 /*⠅⠆⠀*/:	case 0xe0 /*⠄⠆⠄*/:
	case 0xe2 /*⠅⠆⠄*/:
		if (linePixels.get(x, y)) {
			left = pixel;
			right = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		} else {
			left = right = pixel;
		}
		break;
	case 0x58 /*⠀⠆⠃*/:	case 0xd0 /*⠄⠆⠂*/:
		if (linePixels.get(x, y)) {
			left = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
			right = pixel;
		} else {
			left = right = pixel;
		}
		break;
	}
}

inline void scalePixelTo1x2(
	const MarginedBitmap<Color> &src,
	const MarginedBitmap<bool> &linePixels,
	int x, int y,
	// Out parameters
	Color &top, Color &bottom
) {
	const Color pixel = src.get(x, y);
	const EqualityMatrix matrix = getEqualityMatrix(src.getPointerTo(x, y), src.getStride());

	// Note: There is a case label for every possible value, so we don't need a default label, but one is added to avoid any compiler warnings.
	switch (matrix) {
	default: case 0x00 /*⠀⠂⠀*/:	case 0x02 /*⠁⠂⠀*/:	case 0x04 /*⠀⠃⠀*/:	case 0x07 /*⠃⠃⠀*/:	case 0x08 /*⠀⠂⠁*/:	case 0x17 /*⠃⠃⠂*/:	case 0x1c /*⠀⠃⠃*/:	case 0x1d /*⠂⠃⠃*/:
	case 0x1e /*⠁⠃⠃*/:	case 0x1f /*⠃⠃⠃*/:	case 0x20 /*⠀⠂⠄*/:	case 0x22 /*⠁⠂⠄*/:	case 0x24 /*⠀⠃⠄*/:	case 0x25 /*⠂⠃⠄*/:	case 0x27 /*⠃⠃⠄*/:	case 0x28 /*⠀⠂⠅*/:
	case 0x29 /*⠂⠂⠅*/:	case 0x2a /*⠁⠂⠅*/:	case 0x2f /*⠃⠃⠅*/:	case 0x37 /*⠃⠃⠆*/:	case 0x3c /*⠀⠃⠇*/:	case 0x3d /*⠂⠃⠇*/:	case 0x3e /*⠁⠃⠇*/:	case 0x3f /*⠃⠃⠇*/:
	case 0x40 /*⠀⠆⠀*/:	case 0x41 /*⠂⠆⠀*/:	case 0x42 /*⠁⠆⠀*/:	case 0x44 /*⠀⠇⠀*/:	case 0x45 /*⠂⠇⠀*/:	case 0x47 /*⠃⠇⠀*/:	case 0x48 /*⠀⠆⠁*/:	case 0x49 /*⠂⠆⠁*/:
	case 0x4a /*⠁⠆⠁*/:	case 0x4f /*⠃⠇⠁*/:	case 0x50 /*⠀⠆⠂*/:	case 0x51 /*⠂⠆⠂*/:	case 0x52 /*⠁⠆⠂*/:	case 0x54 /*⠀⠇⠂*/:	case 0x55 /*⠂⠇⠂*/:	case 0x57 /*⠃⠇⠂*/:
	case 0x5c /*⠀⠇⠃*/:	case 0x5d /*⠂⠇⠃*/:	case 0x5e /*⠁⠇⠃*/:	case 0x5f /*⠃⠇⠃*/:	case 0x67 /*⠃⠇⠄*/:	case 0x6f /*⠃⠇⠅*/:	case 0x70 /*⠀⠆⠆*/:	case 0x71 /*⠂⠆⠆*/:
	case 0x72 /*⠁⠆⠆*/:	case 0x73 /*⠃⠆⠆*/:	case 0x74 /*⠀⠇⠆*/:	case 0x75 /*⠂⠇⠆*/:	case 0x76 /*⠁⠇⠆*/:	case 0x77 /*⠃⠇⠆*/:	case 0x78 /*⠀⠆⠇*/:	case 0x79 /*⠂⠆⠇*/:
	case 0x7a /*⠁⠆⠇*/:	case 0x7b /*⠃⠆⠇*/:	case 0x7c /*⠀⠇⠇*/:	case 0x7d /*⠂⠇⠇*/:	case 0x7e /*⠁⠇⠇*/:	case 0x7f /*⠃⠇⠇*/:	case 0x80 /*⠄⠂⠀*/:	case 0x82 /*⠅⠂⠀*/:
	case 0x84 /*⠄⠃⠀*/:	case 0x87 /*⠇⠃⠀*/:	case 0x88 /*⠄⠂⠁*/:	case 0x8a /*⠅⠂⠁*/:	case 0x8f /*⠇⠃⠁*/:	case 0x92 /*⠅⠂⠂*/:	case 0x94 /*⠄⠃⠂*/:	case 0x97 /*⠇⠃⠂*/:
	case 0x9c /*⠄⠃⠃*/:	case 0x9d /*⠆⠃⠃*/:	case 0x9e /*⠅⠃⠃*/:	case 0x9f /*⠇⠃⠃*/:	case 0xa2 /*⠅⠂⠄*/:	case 0xa4 /*⠄⠃⠄*/:	case 0xa7 /*⠇⠃⠄*/:	case 0xa8 /*⠄⠂⠅*/:
	case 0xaa /*⠅⠂⠅*/:	case 0xaf /*⠇⠃⠅*/:	case 0xb7 /*⠇⠃⠆*/:	case 0xbc /*⠄⠃⠇*/:	case 0xbd /*⠆⠃⠇*/:	case 0xbe /*⠅⠃⠇*/:	case 0xbf /*⠇⠃⠇*/:	case 0xc1 /*⠆⠆⠀*/:
	case 0xc3 /*⠇⠆⠀*/:	case 0xc5 /*⠆⠇⠀*/:	case 0xc7 /*⠇⠇⠀*/:	case 0xc9 /*⠆⠆⠁*/:	case 0xcb /*⠇⠆⠁*/:	case 0xcd /*⠆⠇⠁*/:	case 0xcf /*⠇⠇⠁*/:	case 0xd1 /*⠆⠆⠂*/:
	case 0xd3 /*⠇⠆⠂*/:	case 0xd5 /*⠆⠇⠂*/:	case 0xd7 /*⠇⠇⠂*/:	case 0xd9 /*⠆⠆⠃*/:	case 0xdb /*⠇⠆⠃*/:	case 0xdc /*⠄⠇⠃*/:	case 0xdd /*⠆⠇⠃*/:	case 0xde /*⠅⠇⠃*/:
	case 0xdf /*⠇⠇⠃*/:	case 0xe3 /*⠇⠆⠄*/:	case 0xe5 /*⠆⠇⠄*/:	case 0xe7 /*⠇⠇⠄*/:	case 0xe9 /*⠆⠆⠅*/:	case 0xeb /*⠇⠆⠅*/:	case 0xed /*⠆⠇⠅*/:	case 0xef /*⠇⠇⠅*/:
	case 0xf0 /*⠄⠆⠆*/:	case 0xf1 /*⠆⠆⠆*/:	case 0xf2 /*⠅⠆⠆*/:	case 0xf3 /*⠇⠆⠆*/:	case 0xf4 /*⠄⠇⠆*/:	case 0xf5 /*⠆⠇⠆*/:	case 0xf6 /*⠅⠇⠆*/:	case 0xf7 /*⠇⠇⠆*/:
	case 0xf8 /*⠄⠆⠇*/:	case 0xf9 /*⠆⠆⠇*/:	case 0xfa /*⠅⠆⠇*/:	case 0xfb /*⠇⠆⠇*/:	case 0xfc /*⠄⠇⠇*/:	case 0xfd /*⠆⠇⠇*/:	case 0xfe /*⠅⠇⠇*/:	case 0xff /*⠇⠇⠇*/:
		top = bottom = pixel;
		break;
	case 0x11 /*⠂⠂⠂*/:	case 0x15 /*⠂⠃⠂*/:
		top = pixel;
		bottom = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		break;
	case 0x06 /*⠁⠃⠀*/:	case 0x0c /*⠀⠃⠁*/:	case 0x0e /*⠁⠃⠁*/:	case 0x23 /*⠃⠂⠄*/:	case 0x26 /*⠁⠃⠄*/:	case 0x2b /*⠃⠂⠅*/:	case 0x2c /*⠀⠃⠅*/:	case 0x2d /*⠂⠃⠅*/:
	case 0x2e /*⠁⠃⠅*/:	case 0x46 /*⠁⠇⠀*/:	case 0x4b /*⠃⠆⠁*/:	case 0x4c /*⠀⠇⠁*/:	case 0x4d /*⠂⠇⠁*/:	case 0x4e /*⠁⠇⠁*/:	case 0x53 /*⠃⠆⠂*/:	case 0x56 /*⠁⠇⠂*/:
	case 0x59 /*⠂⠆⠃*/:	case 0x5a /*⠁⠆⠃*/:	case 0x5b /*⠃⠆⠃*/:	case 0x60 /*⠀⠆⠄*/:	case 0x62 /*⠁⠆⠄*/:	case 0x63 /*⠃⠆⠄*/:	case 0x64 /*⠀⠇⠄*/:	case 0x65 /*⠂⠇⠄*/:
	case 0x66 /*⠁⠇⠄*/:	case 0x68 /*⠀⠆⠅*/:	case 0x69 /*⠂⠆⠅*/:	case 0x6a /*⠁⠆⠅*/:	case 0x6b /*⠃⠆⠅*/:	case 0x6c /*⠀⠇⠅*/:	case 0x6d /*⠂⠇⠅*/:	case 0x6e /*⠁⠇⠅*/:
	case 0x86 /*⠅⠃⠀*/:	case 0x8c /*⠄⠃⠁*/:	case 0x8e /*⠅⠃⠁*/:	case 0x96 /*⠅⠃⠂*/:	case 0x98 /*⠄⠂⠃*/:	case 0x9a /*⠅⠂⠃*/:	case 0xa1 /*⠆⠂⠄*/:	case 0xa3 /*⠇⠂⠄*/:
	case 0xa5 /*⠆⠃⠄*/:	case 0xa6 /*⠅⠃⠄*/:	case 0xa9 /*⠆⠂⠅*/:	case 0xab /*⠇⠂⠅*/:	case 0xac /*⠄⠃⠅*/:	case 0xad /*⠆⠃⠅*/:	case 0xae /*⠅⠃⠅*/:	case 0xb0 /*⠄⠂⠆*/:
	case 0xb2 /*⠅⠂⠆*/:	case 0xb4 /*⠄⠃⠆*/:	case 0xb6 /*⠅⠃⠆*/:	case 0xb8 /*⠄⠂⠇*/:	case 0xba /*⠅⠂⠇*/:	case 0xc0 /*⠄⠆⠀*/:	case 0xc2 /*⠅⠆⠀*/:	case 0xc4 /*⠄⠇⠀*/:
	case 0xc6 /*⠅⠇⠀*/:	case 0xc8 /*⠄⠆⠁*/:	case 0xca /*⠅⠆⠁*/:	case 0xcc /*⠄⠇⠁*/:	case 0xce /*⠅⠇⠁*/:	case 0xd2 /*⠅⠆⠂*/:	case 0xd4 /*⠄⠇⠂*/:	case 0xd6 /*⠅⠇⠂*/:
	case 0xd8 /*⠄⠆⠃*/:	case 0xda /*⠅⠆⠃*/:	case 0xe0 /*⠄⠆⠄*/:	case 0xe2 /*⠅⠆⠄*/:	case 0xe4 /*⠄⠇⠄*/:	case 0xe6 /*⠅⠇⠄*/:	case 0xe8 /*⠄⠆⠅*/:	case 0xea /*⠅⠆⠅*/:
	case 0xec /*⠄⠇⠅*/:	case 0xee /*⠅⠇⠅*/:
		if (linePixels.get(x, y)) {
			top = bottom = pixel;
		} else {
			top = bottom = pixel;
		}
		break;
	case 0x01 /*⠂⠂⠀*/:	case 0x05 /*⠂⠃⠀*/:	case 0x09 /*⠂⠂⠁*/:	case 0x0f /*⠃⠃⠁*/:
		top = pixel;
		bottom = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		break;
	case 0x10 /*⠀⠂⠂*/:	case 0x12 /*⠁⠂⠂*/:	case 0x14 /*⠀⠃⠂*/:
		top = pixel;
		bottom = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		break;
	case 0x21 /*⠂⠂⠄*/:	case 0xe1 /*⠆⠆⠄*/:
		top = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		bottom = pixel;
		break;
	case 0x90 /*⠄⠂⠂*/:
		top = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		bottom = pixel;
		break;
	case 0x13 /*⠃⠂⠂*/:	case 0x19 /*⠂⠂⠃*/:	case 0x1b /*⠃⠂⠃*/:	case 0x31 /*⠂⠂⠆*/:	case 0x33 /*⠃⠂⠆*/:	case 0x35 /*⠂⠃⠆*/:	case 0x39 /*⠂⠂⠇*/:	case 0x3b /*⠃⠂⠇*/:
	case 0x91 /*⠆⠂⠂*/:	case 0x93 /*⠇⠂⠂*/:	case 0x95 /*⠆⠃⠂*/:	case 0x99 /*⠆⠂⠃*/:	case 0x9b /*⠇⠂⠃*/:	case 0xb1 /*⠆⠂⠆*/:	case 0xb3 /*⠇⠂⠆*/:	case 0xb5 /*⠆⠃⠆*/:
	case 0xb9 /*⠆⠂⠇*/:	case 0xbb /*⠇⠂⠇*/:
		if (linePixels.get(x, y)) {
			top = pixel;
			bottom = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : pixel;
		} else {
			top = bottom = pixel;
		}
		break;
	case 0x0a /*⠁⠂⠁*/:
		top = pixel;
		bottom = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		break;
	case 0xa0 /*⠄⠂⠄*/:
		top = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		bottom = pixel;
		break;
	case 0x03 /*⠃⠂⠀*/:	case 0x0b /*⠃⠂⠁*/:	case 0x0d /*⠂⠃⠁*/:	case 0x81 /*⠆⠂⠀*/:	case 0x83 /*⠇⠂⠀*/:	case 0x85 /*⠆⠃⠀*/:	case 0x89 /*⠆⠂⠁*/:	case 0x8b /*⠇⠂⠁*/:
	case 0x8d /*⠆⠃⠁*/:
		if (linePixels.get(x, y)) {
			top = pixel;
			bottom = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
		} else {
			top = bottom = pixel;
		}
		break;
	case 0x16 /*⠁⠃⠂*/:	case 0x18 /*⠀⠂⠃*/:	case 0x1a /*⠁⠂⠃*/:	case 0x30 /*⠀⠂⠆*/:	case 0x32 /*⠁⠂⠆*/:	case 0x34 /*⠀⠃⠆*/:	case 0x36 /*⠁⠃⠆*/:	case 0x38 /*⠀⠂⠇*/:
	case 0x3a /*⠁⠂⠇*/:
		if (linePixels.get(x, y)) {
			top = pixel;
			bottom = !linePixels.get(x, y + 1) ? src.get(x, y + 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
		} else {
			top = bottom = pixel;
		}
		break;
	case 0x43 /*⠃⠆⠀*/:	case 0x61 /*⠂⠆⠄*/:
		if (linePixels.get(x, y)) {
			top = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x + 1, y) ? src.get(x + 1, y) : pixel;
			bottom = pixel;
		} else {
			top = bottom = pixel;
		}
		break;
	case 0x58 /*⠀⠆⠃*/:	case 0xd0 /*⠄⠆⠂*/:
		if (linePixels.get(x, y)) {
			top = !linePixels.get(x, y - 1) ? src.get(x, y - 1) : !linePixels.get(x - 1, y) ? src.get(x - 1, y) : pixel;
			bottom = pixel;
		} else {
			top = bottom = pixel;
		}
		break;
	}
}
