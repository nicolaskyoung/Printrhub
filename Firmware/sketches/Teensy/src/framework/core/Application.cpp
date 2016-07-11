/*
 * Little Helper -- your best friend in your lab
 * http://www.appfruits.com/littlehelper
 *
 * This software is part of the firmware running Little Helper. You may use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies of the Software
 * but you must include this copyright notice and this permission in all copies or
 * substantial portions of the Software.
 *
 * Appfruits invests time and resources to make this open source. Please support us
 * and the open-source hardware initiative.
 *
 * Copyright 2014-2015 Phillip Schuster (@appfruits)
 * http://www.appfruits.com
 *
 * MIT-License
 */

#include "Application.h"
#include "SceneController.h"
#include "../animation/Animator.h"

ApplicationClass Application;

ApplicationClass::ApplicationClass()
{
	_firstSceneLoop = true;
	_touched = false;
	_nextScene = NULL;
	_currentScene = NULL;
	_lastTime = 0;
	_deltaTime = 0;
	_esp = new CommStack(&Serial3,this);
}

ApplicationClass::~ApplicationClass()
{

}


void ApplicationClass::handleTouches()
{
	//If we don't have a screen controller we don't have to handle touches
	if (_currentScene == NULL) return;

	//Get current scene controller
	SceneController* sceneController = _currentScene;

	//Touches infinite state machine
	if (Touch.touched())
	{
		//Get touch point and transform due to screen rotation
		TS_Point point = Touch.getPoint();
		swap(point.x,point.y);
		point.y = 240-point.y;

		if (_touched)
		{
			if (point.x != _lastTouchPoint.x || point.y != _lastTouchPoint.y)
			{
				//LOG("Touch Moved");
				//Move event
				sceneController->handleTouchMoved(point,_lastTouchPoint);
			}
		}
		else
		{
			//LOG("Touch down");
			//Touch down event
			sceneController->handleTouchDown(point);
			_touched = true;
		}

		_lastTouchPoint = point;
	}
	else
	{
		if (_touched)
		{
			//LOG("Touch up");
			//Touch up event
			sceneController->handleTouchUp(_lastTouchPoint);
		}

		_touched = false;
	}
}

void ApplicationClass::loop()
{
	//Run Animations
	Animator.update();

	//Clear the display
	//Display.clear();

	if (_nextScene != NULL)
	{
		//Shut down display to hide the build process of the layout (which is step by step and looks flashy)
		Display.fadeOut();

		//Clear the display
		Display.clear();

		if (_currentScene != NULL)
		{
			delete _currentScene;
		}

		_currentScene = _nextScene;
		_nextScene = NULL;
		_firstSceneLoop = true;
	}

	//Run current controller
	if (_currentScene != NULL)
	{
		//LOG("Run Controller");
		SceneController* sceneController = _currentScene;

		//Call onWillAppear event handler if this is the first time the loop function is called by the scene
		//The default implementation will clear the display!
		if (_firstSceneLoop)
		{
			LOG("First loop");
			Display.clear();

			//Prepare display for this scene (i.e. setting scroll position and scroll offsets, etc)
			sceneController->setupDisplay();

			LOG_VALUE("Appearing scene", sceneController->getName());
			sceneController->onWillAppear();
			LOG("Scene appeared");

/*			Display.fillRect(0,0,50,240,Application.getTheme()->getPrimaryColor());
			Display.setTextRotation(270);
			Display.setCursor(13,130);
			Display.setTextColor(ILI9341_WHITE);
			Display.setFont(PTSansNarrow_24);
			Display.print("PROJECTS");

			Display.setTextRotation(0);*/
		}

		//Touch handling
		handleTouches();

		//Calculate Delta Time
		unsigned long currentTime = millis();
		if (currentTime < _lastTime)
		{
			//millis overflowed, just set delta to 0
			_deltaTime = 0;
		}
		else
		{
			_deltaTime = (float)(currentTime - _lastTime)/1000.0f;
		}

		//Run the scenes loop function
		sceneController->loop();
		_lastTime = millis();

		//Relayout screen tiles
		Display.layoutIfNeeded();

		//Update display
		Display.dispatch();

		if (_firstSceneLoop)
		{
			//Set display brightness to full to show what's been built up since we shut down the display
			Display.fadeIn();

		}

		_firstSceneLoop = false;
	}

	//Delay for a few ms if no animation is running
	if (!Animator.hasActiveAnimations())
	{
		delay(16);
	}

}

void ApplicationClass::pushScene(SceneController *scene)
{
	LOG_VALUE("Pushing scene",scene->getName());

	_nextScene = scene;
}

ColorTheme* ApplicationClass::getTheme()
{
	return &_theme;
}


void ApplicationClass::sendScreenshot()
{

}


float ApplicationClass::getDeltaTime()
{
	return _deltaTime;
}


CommStack *ApplicationClass::getESPStack()
{
	return _esp;
}

bool ApplicationClass::runTask(CommHeader &header, Stream *stream)
{
	LOG_VALUE("Running Task with ID",header.getCurrentTask());
	LOG_VALUE("Comm-Type",header.commType);

	if (header.getCurrentTask() == GetTimeAndDate)
	{
		if (header.commType == Response)
		{
			LOG("Loading Date and Time from ESP");
			Display.setCursor(10,20);
			Display.println("Data available, reading...");

			String datetime = stream->readStringUntil('\n');
			LOG_VALUE("Received Datetime",datetime);

			Display.setCursor(10,30);
			Display.println("Received datetime from ESP");
			Display.println(datetime);
		}
	}
	return true;
}


