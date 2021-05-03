#include <inttypes.h>
#include <iostream>
// #include <string>
// #include <limits.h>
int main()
{
    // typedef enum SEGMENT_RENDER_NAMES : uint8_t
    // {
    //     PROCESS_INITIALIZE,
    //     PROCESS_GOOD_STATE,
    //     OPERATION_DONE,
    //     RUNTIME_ERROR,
    //     RUNTIME_SUCCESS,
    //     CORE_1,
    //     CORE_2,
    //     GP_READING,
    //     GP_WRITING,
    //     NEGOTIATE_AUTH,
    //     NEGOTIATE_UNAUTH,
    //     MODULE_CONNECT,
    //     MODULE_PAIRED,
    //     RESERVED
    // };

    // constexpr uint8_t MAX_ALLOWABLE_RENDERS = 13;

    // struct __SEGMENT_RENDERS
    // {
    //     SEGMENT_RENDER_NAMES segIdentifier;
    //     uint8_t BIN_SEGMENTS[8 - 1];

    //     // Constructor __SEGMENT_RENDERS.
    //     __SEGMENT_RENDERS(SEGMENT_RENDER_NAMES id, uint8_t *) : segIdentifier(id) // Auto-Assign.
    //     {
    //         for (unsigned start = 0; start < RESERVED; start++)
    //         {
    //             std::cout << static_cast<SEGMENT_RENDER_NAMES>(start) << std::endl;
    //         }

    //         BIN_SEGMENTS = (uint8_t *)ctx;

    //     }

    // } _SEGMENT_RENDERS [MAX_ALLOWABLE_RENDERS] = {
    //     {PROCESS_INITIALIZE, {1, 0, 0, 0, 0, 0, 0}},
    //     {PROCESS_GOOD_STATE, {1, 1, 1, 1, 1, 0, 1}},
    //     {OPERATION_DONE, {1, 0, 1, 1, 1, 1, 0}},
    //     {RUNTIME_ERROR, {1, 1, 1, 1, 0, 0, 1}},
    //     {RUNTIME_SUCCESS, {1, 1, 0, 1, 1, 0, 1}},
    //     {CORE_1, {0, 0, 0, 0, 1, 1, 0}},
    //     {CORE_2, {1, 0, 1, 1, 0, 1, 1}},
    //     {GP_READING, {1, 0, 1, 0, 0, 0, 0}},
    //     {GP_WRITING, {0, 1, 1, 0, 1, 1, 0}},
    //     {NEGOTIATE_AUTH, {1, 1, 1, 0, 1, 1, 1}},
    //     {NEGOTIATE_UNAUTH, {0, 1, 1, 1, 1, 1, 0}},
    //     {MODULE_CONNECT, {0, 1, 1, 1, 0, 0, 1}},
    //     {MODULE_PAIRED, {1, 1, 1, 0, 0, 1, 1}}};
    uint8_t sample_test = 0x67;
    unsigned main_value = static_cast<unsigned>(sample_test);

    std::cout << "Before Test | " << main_value << std::endl;

    for (unsigned test = 0; test < CHAR_BIT; test++)
    {
        std::cout << "Iter #" << test << " | Value is " << (sample_test & 0x01 ? 1 : 0) << std::endl;
        sample_test = sample_test >> 1;
    }

    std::cout << "After Test | " << main_value << std::endl;

    int i = 10;
    void *v = static_cast<void *>(&i);
    std::cout << i << std::endl;
    int *ip = static_cast<int *>(v);

    std::cout << v << " | " << *ip << std::endl;
    // std::cout << sizeof(SEGMENT_RENDER_NAMES) << sizeof(std::string) << std::endl;
    // std::cout << sizeof(SEGMENT_RENDER_NAMES) / sizeof(std::string);

    // for (unsigned start = 0; start < RESERVED; start++)
    // {
    //     std::cout << static_cast<SEGMENT_RENDER_NAMES>(start) << std::endl;
    // }
    return 0;
}