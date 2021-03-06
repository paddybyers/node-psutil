#ifndef WORKER_H_
#define WORKER_H_

#include <v8.h>

using namespace v8;
using namespace node;

class Worker {
  public:
    Worker() {}
    virtual ~Worker() {}

    // libuv's request struct.
    uv_work_t request;
    // Callback
    v8::Persistent<Function> callback;
    // Was there an error
    bool error;
    // The error message
    char *error_message;

    // Virtual execute function
    void virtual execute();
    // Map to output object
    Handle<Value> virtual map();
};

#endif  // WORKER_H_
