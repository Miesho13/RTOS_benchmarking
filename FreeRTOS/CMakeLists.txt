cmake_minimum_required(VERSION 3.22)


project(stm32_f411xe_min_require C ASM) 

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)


set(PROCESSOR_FLAGS "-mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${PROCESSOR_FLAGS} -Wall -Wextra -g -O0")

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32F411VET6.ld)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -specs=nosys.specs -T${LINKER_SCRIPT}")
    

file(GLOB_RECURSE SOURCES "src/*.c"
                          "src/*.s"
                          "src/cmsis/*.c"
                          "src/drivers/*.c"
                          "src/system/*.c"
                          "src/FreeRTOS/org/Source/*.c"
                          "src/FreeRTOS/org/Source/portable/GCC/ARM_CM4F/*.c"
                          "src/FreeRTOS/org/Source/portable/MemMang/heap_4.c")
include_directories(src)
include_directories(src/FreeRTOS/org/Source/include)
include_directories(src/FreeRTOS/org/Source/GCC/ARM_CM4F)

add_executable(${PROJECT_NAME}.elf ${SOURCES})

# generate .bin and .hex files 
add_custom_command(
    TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
    COMMAND ${CMAKE_OBJCOPY} -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
    COMMENT "Generating .bin and .hex files")
