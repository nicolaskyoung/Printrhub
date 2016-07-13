//
// Created by Phillip Schuster on 09.07.16.
//

#ifndef ESP8266_ARM_SWD_COMMSTACK_H
#define ESP8266_ARM_SWD_COMMSTACK_H

#include "Arduino.h"

//Maximum is 255 as currentTaskIndex is a byte
#define COMM_STACK_MAX_TASKS 10

enum CommType : uint8_t {
    Request = 0,
    Response = 1
};

enum TaskID : uint8_t {
    Unknown = 0,
    GetIndexFile = 1,
    GetProjectWithID = 2,
    PrintProjectWithID = 3,
    GetTimeAndDate = 4,
    GetProjectItemWithID = 5,
    GetJobWithID = 6,
    FileOpenForWrite = 7,
    FileSendData = 8,
    FileClose = 9,
    Error = 10,
};

struct CommHeader {
public:
    uint8_t numberOfTasks;
    TaskID tasks[COMM_STACK_MAX_TASKS];
    uint8_t currentTaskIndex;
    CommType commType;
    uint32_t contentLength;

public:
    CommHeader() {
        this->numberOfTasks = 0;
        this->currentTaskIndex = 0;
        this->commType = Request;
        this->contentLength = 0;
    }

    CommHeader(TaskID task, uint32_t contentLength) {
        this->tasks[0] = task;
        this->numberOfTasks = 1;
        this->currentTaskIndex = 0;
        this->commType = Request;
        this->contentLength = contentLength;
    }

    CommHeader(TaskID* tasks, uint8_t numberOfTasks, uint32_t contentLength) {
        memcpy(&this->tasks,tasks,sizeof(uint8_t)*numberOfTasks);
        this->numberOfTasks = numberOfTasks;
        this->currentTaskIndex = 0;
        this->commType = Request;
        this->contentLength = contentLength;
    }

    TaskID getCurrentTask()
    {
        if (currentTaskIndex >= COMM_STACK_MAX_TASKS) return Unknown;
        if (currentTaskIndex >= numberOfTasks) return Unknown;
        return tasks[currentTaskIndex];
    }

    bool isFinished()
    {
        return (currentTaskIndex >= numberOfTasks);
    }
};

class CommStackDelegate
{
public:
    virtual bool runTask(CommHeader& header, Stream* stream) = 0;
    virtual bool canRunTask(CommHeader& header) { return true; }
};

class CommStack
{
/*#pragma mark Task Definitions
public:
    static const uint8_t GetIndexFile = 0;
    static const uint8_t GetProjectWithID = 1;
    static const uint8_t PrintProjectWithID = 2;
    static const uint8_t GetTimeAndDate = 3;
*/
#pragma mark Constructor
public:
    CommStack(Stream* port, CommStackDelegate* delegate);
    ~CommStack();

public:
    void process();
    bool requestTask(TaskID task);
    bool requestTasks(TaskID* tasks);
    Stream* getPort() const { return _port; };

private:
    bool readHeader(CommHeader* commHeader);
    bool prepareResponse(CommHeader* commHeader);
    bool writeHeader(CommHeader* commHeader);

#pragma mark Member Variables
private:
    Stream* _port;
    CommStackDelegate* _delegate;
};

#endif //ESP8266_ARM_SWD_COMMSTACK_H
