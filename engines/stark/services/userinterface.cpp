/* ResidualVM - A 3D game interpreter
 *
 * ResidualVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the AUTHORS
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

#include "common/system.h"
#include "common/events.h"

#include "engines/stark/services/userinterface.h"

#include "engines/stark/gfx/driver.h"

#include "engines/stark/services/services.h"
#include "engines/stark/services/staticprovider.h"
#include "engines/stark/services/gameinterface.h"

#include "engines/stark/ui/actionmenu.h"
#include "engines/stark/ui/dialogpanel.h"
#include "engines/stark/ui/fmvplayer.h"
#include "engines/stark/ui/gamewindow.h"
#include "engines/stark/ui/inventorywindow.h"
#include "engines/stark/ui/topmenu.h"

namespace Stark {

UserInterface::UserInterface(Gfx::Driver *gfx, Cursor *cursor) :
	_gfx(gfx),
	_cursor(cursor),
	_topMenu(nullptr),
	_dialogPanel(nullptr),
	_inventoryWindow(nullptr),
	_exitGame(false),
	_fmvPlayer(nullptr),
	_actionMenu(nullptr),
	_gameWindow(nullptr),
	_interactive(true),
	_currentScreen(kScreenGame)
	{
}

UserInterface::~UserInterface() {
	delete _gameWindow;
	delete _actionMenu;
	delete _topMenu;
	delete _dialogPanel;
	delete _inventoryWindow;
	delete _fmvPlayer;
}

void UserInterface::init() {
	// Game screen windows
	_topMenu = new TopMenu(_gfx, _cursor);
	_dialogPanel = new DialogPanel(_gfx, _cursor);
	_actionMenu = new ActionMenu(_gfx, _cursor);
	_inventoryWindow = new InventoryWindow(_gfx, _cursor, _actionMenu);
	_actionMenu->setInventory(_inventoryWindow);
	_gameWindow = new GameWindow(_gfx, _cursor, _actionMenu, _inventoryWindow);

	_gameScreenWindows.push_back(_actionMenu);
	_gameScreenWindows.push_back(_inventoryWindow);
	_gameScreenWindows.push_back(_gameWindow);
	_gameScreenWindows.push_back(_topMenu);
	_gameScreenWindows.push_back(_dialogPanel);

	// FMV Screen window
	_fmvPlayer = new FMVPlayer(_gfx, _cursor);
}

void UserInterface::update() {
	StarkStaticProvider->onGameLoop();

	// Check for UI mouse overs
	switch (_currentScreen) {
		case kScreenGame:
			for (uint i = 0; i < _gameScreenWindows.size(); i++) {
				if (_gameScreenWindows[i]->isVisible() && _gameScreenWindows[i]->isMouseInside()) {
					_gameScreenWindows[i]->handleMouseMove();
					return;
				}
			}
	        break;
		default: // Nothing goes here
			break;
	}
}

void UserInterface::handleClick() {
	switch (_currentScreen) {
		case kScreenGame:
			for (uint i = 0; i < _gameScreenWindows.size(); i++) {
				if (_gameScreenWindows[i]->isMouseInside()) {
					_gameScreenWindows[i]->handleClick();
					return;
				}
			}
	        break;
		default: // Nothing goes here
			break;
	}
}

void UserInterface::handleRightClick() {
	switch (_currentScreen) {
		case kScreenGame:
			for (uint i = 0; i < _gameScreenWindows.size(); i++) {
				if (_gameScreenWindows[i]->isMouseInside()) {
					_gameScreenWindows[i]->handleRightClick();
					return;
				}
			}
			break;
		default: // Nothing goes here
			break;
	}
}

void UserInterface::handleDoubleClick() {
	switch (_currentScreen) {
		case kScreenGame:
			for (uint i = 0; i < _gameScreenWindows.size(); i++) {
				if (_gameScreenWindows[i]->isMouseInside()) {
					_gameScreenWindows[i]->handleDoubleClick();
					return;
				}
			}
	        break;
		default: // Nothing goes here
			break;
	}
}

void UserInterface::notifyShouldOpenInventory() {
	// Make the inventory update its contents.
	_inventoryWindow->open();
}

int16 UserInterface::getSelectedInventoryItem() const {
	if (_inventoryWindow) {
		return _inventoryWindow->getSelectedInventoryItem();
	} else {
		return -1;
	}
}

void UserInterface::selectInventoryItem(int16 itemIndex) {
	_inventoryWindow->setSelectedInventoryItem(itemIndex);
}

void UserInterface::requestFMVPlayback(const Common::String &name) {
	// TODO: Save the current screen so that it can be restored when the playback ends
	changeScreen(kScreenFMV);

	_fmvPlayer->play(name);
}

void UserInterface::onFMVStopped() {
	// TODO: Restore the previous screen
	changeScreen(kScreenGame);
}

void UserInterface::changeScreen(Screen screen) {
	_currentScreen = screen;
}

bool UserInterface::isInGameScreen() const {
	return _currentScreen == kScreenGame;
}

void UserInterface::skipFMV() {
	if (_currentScreen == kScreenFMV) {
		_fmvPlayer->stop();
	}
}

void UserInterface::render() {
	switch (_currentScreen) {
		case kScreenGame:
			for (int i = _gameScreenWindows.size() - 1; i >= 0; i--) {
				_gameScreenWindows[i]->render();
			}
			break;
		case kScreenFMV:
			_fmvPlayer->render();
			break;
		default: // Nothing goes here
			break;
	}
}

bool UserInterface::isInteractive() const {
	return _interactive;
}

void UserInterface::setInteractive(bool interactive) {
	_interactive = interactive;
}

} // End of namespace Stark

