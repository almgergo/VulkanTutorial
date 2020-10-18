cmake_minimum_required(VERSION 3.17)
project(VulkanTutorial2)

set(CMAKE_CXX_STANDARD 17)


add_executable(VulkanTutorial2 src/main.cpp)
target_sources(VulkanTutorial2 PRIVATE src/app/VulkanApplication.cpp)

include_directories(C:\\Software\\glfw-3.3.2.bin.WIN64\\include)
include_directories(C:\\Software\\glm-0.9.9.8)
include_directories(C:\\VulkanSDK\\1.2.154.1\\Include)

find_library(GLFW_LIBRARIES NAMES glfw3.lib PATHS C:\\Software\\glfw-3.3.2.bin.WIN64\\lib-vc2019)
if (NOT GLFW_LIBRARIES) 
    message(FATAL_ERROR "Could not find glfw library!")
endif ()

target_link_libraries(VulkanTutorial2 ${GLFW_LIBRARIES})

find_library(VulkanLibrary NAMES vulkan-1.lib PATHS c:\\VulkanSDK\\1.2.154.1\\Lib)
if (NOT VulkanLibrary)
    message(FATAL_ERROR "Could not find Vulkan library!")
endif ()

target_link_libraries(VulkanTutorial2 ${VulkanLibrary})
