#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glutilD.lib")

#include "GameEngine.h"
#include "WindowsConsoleLogger.h"
#include "GameWindow.h"
#include "OGLVertexShader.h"
#include "OGLFragmentShader.h"
#include "OGLShaderProgram.h"
#include "OGLShaderManager.h"
#include "TextFileReader.h"
#include "OGLGraphicsSystem.h"
#include "CoreSystem.h"
#include "GameWorld.h"
#include "GameObjectManager.h"
#include "OGLSphericalCamera.h"
#include "OGLViewingFrustum.h"
#include "StockObjectLoader.h"
#include "PCInputSystem.h"
#include "WindowsTimer.h"
#include "OGLFirstPersonCamera.h"
#include "TheGame.h"
#include "TextureManager.h"
#include "GameAssetLoader.h"
#include "FirstPersonPlayer.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	GraphicsSystem* graphicsSystem = new OGLGraphicsSystem(
		new OGLShaderManager(),
		new GameWorld(
			new GameObjectManager(),
			new OGLFirstPersonCamera()),
		new OGLViewingFrustum(),
		new TextureManager());

	GameEngine gameEngine(
		new WindowsConsoleLogger(), 
		new FirstPersonPlayer("The Player"),
		new TheGame(),
		new GameAssetLoader(),
		new CoreSystem(
			new TextFileReader()), 
		graphicsSystem,
		new GameWindow(
			L"Find all Treasure!", 
			1000, 
			800),
		new PCInputSystem(),
		new WindowsTimer()
	);
	gameEngine.loadShaders("ShaderAssets.data");
	gameEngine.initializeWindowAndGraphics("ShaderAssets.data");
	gameEngine.setupGame("GameAssets.data");
	gameEngine.run();

	return 0;
}
