//
// Created by Phillip Schuster on 31.01.16.
//

#ifndef TEENSYCMAKE_VIRTUALKEYBOARDSCENECONTROLLER_H
#define TEENSYCMAKE_VIRTUALKEYBOARDSCENECONTROLLER_H


#include "SceneController.h"
#include "BitmapButton.h"
#include "LabelView.h"
#include "LabelButton.h"

class VirtualKeyboardSceneController: public SceneController, ButtonDelegate
{
public:
    VirtualKeyboardSceneController();
    virtual ~VirtualKeyboardSceneController();

    String getName();

private:
    virtual void buttonPressed(void *button);

public:
    virtual uint16_t getBackgroundColor() override;
};

#endif //TEENSYCMAKE_VIRTUALKEYBOARDSCENECONTROLLER_H
