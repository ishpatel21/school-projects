#include "GameWindow.h"
#include "OGLShader.h"

#include <GL\glew.h>

GameWindow *GameWindow::self;

GameWindow::GameWindow(Shader* shader, wstring title, int width, int height):
	Win32OGLWindow(title, width, height)
{
	this->shader = shader;
	this->WndProcedure = GameWindow::WndProc;
	this->self = this;
}

GameWindow::~GameWindow()
{
}

void GameWindow::runOneFrame()
{
	update();
	render();
}

void GameWindow::update()
{
}

bool GameWindow::create()
{
	if (!Win32OGLWindow::create()) return false;
	if(!this->shader->create()) return false;
	return true;
}

void GameWindow::render()
{
	glViewport(0, 0, this->width, this->height);

	glClearColor(
		this->background.red,
		this->background.green,
		this->background.blue,
		this->background.alpha
	);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	this->shader->renderObjects();

	SwapBuffers(this->deviceContext);
}

LRESULT CALLBACK GameWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return Win32OGLWindow::WndProc(hWnd, message, wParam, lParam);
}
