/**
 * \file
 * \brief Header file which defines output audio related variables and functions
 *
 * Copyright (C) 2015 PSP2SDK Project
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _PSP2_SCREENSHOT_H_
#define _PSP2_SCREENSHOT_H_

#include <psp2/types.h>

enum ScreenshotErrorCodes {
	SCE_SCREENSHOT_ERROR_INVALID_ARGUMENT	= 0x80102f01,
	SCE_SCREENSHOT_ERROR_NO_MEMORY	= 0x80102f02,
	SCE_SCREENSHOT_ERROR_FILE_NOT_FOUND	= 0x80102f03,
	SCE_SCREENSHOT_ERROR_NOT_SUPPORTED_FORMAT	= 0x80102f04,
	SCE_SCREENSHOT_ERROR_MEDIA_FULL	= 0x80102f05,
	SCE_SCREENSHOT_ERROR_INTERNAL	= 0x80102f06
};

enum ScreenshotMaxLen {
	//! Max size of path strings (includes device name and NULL terminator)
	SCE_SCREENSHOT_MAX_FS_PATH	= 1024,

	//! Max length of photo title
	SCE_SCREENSHOT_MAX_PHOTO_TITLE_LEN	= 64,

	 //! Max size of photo title (includes NULL terminater)
	SCE_SCREENSHOT_MAX_PHOTO_TITLE_SIZE	= (SCE_SCREENSHOT_MAX_PHOTO_TITLE_LEN * 4),


	//! Max length of game title
	SCE_SCREENSHOT_MAX_GAME_TITLE_LEN	= 64,

	//! Max size of game title (includes NUL terminator)
	SCE_SCREENSHOT_MAX_GAME_TITLE_SIZE	= (SCE_SCREENSHOT_MAX_GAME_TITLE_LEN * 4),

	//! Max length of comment (description)
	SCE_SCREENSHOT_MAX_GAME_COMMENT_LEN	= 128,

	//! Max size of comment (description) (includes NUL terminator)
	SCE_SCREENSHOT_MAX_GAME_COMMENT_SIZE	= (SCE_SCREENSHOT_MAX_GAME_COMMENT_LEN * 4)
};

typedef struct ScreenshotParam {
	const SceWChar32 *photoTitle; //!< Photo title
	const SceWChar32 *gameTitle;  //!< Game title
	const SceWChar32 *gameComment;  //!< Game description
	void *reserved; //!< Reserved range (Must be NULL)
};

//! Set screenshot params
int sceScreenshotSetParam(const ScreenshotParam *param);

//! Set overlay image
int sceScreenshotOverlayImage(const char *filepath, int offsetX, int offsetY);

//! Disable screenshot
int sceScreenshotDisable(void);

//! Enable screnshot
int sceScreenshotEnable(void);

#endif
