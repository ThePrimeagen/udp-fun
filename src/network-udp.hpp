#include <uv.h>
#include <iostream>
#include <chrono>
#include <thread>

namespace foo {

struct Work {
    uv_work_t my_work;
};

void WorkAsync(uv_work_t* work) {
    std::cout << "WorkAsync#sleep" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "WorkAsync#sleep#complete" << std::endl;
}

void WorkAsyncComplete(uv_work_t *req, int status) {
    std::cout << "WorkAsyncComplete" << std::endl;
}

class UdpStuff {
   public:
    UdpStuff() {
        loop = std::make_unique<uv_loop_t>();
        data = (int*)malloc(sizeof(int) * 4);
        data[0] = 69;
        data[1] = 420;
        data[2] = 1337;

        work = std::make_unique<Work>();
        work->my_work.data = data;

        uv_loop_init(loop.get());
        uv_queue_work(loop.get(), &work->my_work, foo::WorkAsync, foo::WorkAsyncComplete);
    }

    ~UdpStuff() {
        // free(data);
    }

   private:
    std::unique_ptr<uv_loop_t> loop;
    std::unique_ptr<Work> work;
    int* data;
};

}


