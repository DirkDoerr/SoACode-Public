#include "stdafx.h"
#include "App.h"

#include <Vorb/ui/InputDispatcher.h>
#include <Vorb/ui/ScreenList.h>
#include <Vorb/graphics/SpriteBatch.h>

#include "DevScreen.h"
#include "GameManager.h"
#include "GameplayScreen.h"
#include "InitScreen.h"
#include "LoadScreen.h"
#include "MainMenuScreen.h"
#include "MeshManager.h"
#include "Options.h"
#include "GameplayScreen.h"
#include "SpaceSystem.h"
#include "TestBlockViewScreen.h"
#include "TestConsoleScreen.h"
#include "TestDeferredScreen.h"
#include "TestGasGiantScreen.h"
#include "TestMappingScreen.h"
#include "TestStarScreen.h"

void App::addScreens() {
    scrInit = new InitScreen(this);
    scrLoad = new LoadScreen(this);
    scrMainMenu = new MainMenuScreen(this, scrLoad);
    scrGamePlay = new GameplayScreen(this, scrMainMenu);

    m_screenList.addScreen(scrInit);
    m_screenList.addScreen(scrLoad);
    m_screenList.addScreen(scrMainMenu);
    m_screenList.addScreen(scrGamePlay);

    // Add development screen
    scrDev = new DevScreen;
    scrDev->addScreen(VKEY_RETURN, scrInit, "Seed of Andromeda");
    m_screenList.addScreen(scrDev);

    // Add test screens
    scrTests.push_back(new TestConsoleScreen);
    m_screenList.addScreen(scrTests.back());
    scrDev->addScreen(VKEY_C, scrTests.back(), "TestConsoleScreen");
    scrTests.push_back(new TestMappingScreen);
    m_screenList.addScreen(scrTests.back());
    scrDev->addScreen(VKEY_M, scrTests.back(), "TestMappingScreen");
    scrTests.push_back(new TestDeferredScreen);
    m_screenList.addScreen(scrTests.back());
    scrDev->addScreen(VKEY_D, scrTests.back(), "TestDeferredScreen");
    scrTests.push_back(new TestBlockView);
    m_screenList.addScreen(scrTests.back());
    scrDev->addScreen(VKEY_B, scrTests.back(), "TestBlockView");
    scrTests.push_back(new TestGasGiantScreen);
    m_screenList.addScreen(scrTests.back());
    scrDev->addScreen(VKEY_G, scrTests.back(), "TestGasGiantScreen");
    scrTests.push_back(new TestStarScreen(this));
    m_screenList.addScreen(scrTests.back());
    scrDev->addScreen(VKEY_S, scrTests.back(), "TestStarScreen");

    // Uncomment to start from dev screen for testing other screens
#define START_AT_DEV_SCREEN
#ifdef START_AT_DEV_SCREEN
    m_screenList.setScreen(scrDev->getIndex());
#else
    m_screenList.setScreen(scrInit->getIndex());
#endif
}

void App::onInit() {
    
    // Load the game options
    loadOptions("Data/Options.yml");

    vg::SamplerState::initPredefined();
}

void App::onExit() {
    // Delete cache if it exists

    vg::SpriteBatch::disposeProgram();
}

App::~App() {

    delete scrInit;
    delete scrLoad;
    delete scrMainMenu;
    delete scrGamePlay;
    delete scrDev;
}