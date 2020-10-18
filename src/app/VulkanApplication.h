//
// Created by Almásy Gergő on 10/18/2020.
//

#ifndef VULKANTUTORIAL2_VULKANAPPLICATION_H
#define VULKANTUTORIAL2_VULKANAPPLICATION_H

#define GLFW_INCLUDE_VULKAN

#include <GLFW/glfw3.h>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <map>
#include <optional>
#include <set>

const uint32_t WIDTH = 1920;
const uint32_t HEIGHT = 800;

const std::vector<const char *> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

class VulkanApplication {
public:
    void run();

private:
    GLFWwindow *window;
    VkInstance instance;
    VkSurfaceKHR surface;
    VkPhysicalDevice physicalDevice;
    VkDevice device;
    VkQueue graphicsQueue;

    VkQueue presentQueue;

    void initWindow();

    void createSurface();

    void initVulkan();

    void mainLoop();

    void cleanup();

    void createInstance();

    bool checkValidationLayerSupport();

    void pickPhysicalDevice();

    bool isDeviceSuitable(VkPhysicalDevice device);

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

    void createLogicalDevice();

};


#endif //VULKANTUTORIAL2_VULKANAPPLICATION_H
