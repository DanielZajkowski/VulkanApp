#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>

#include "Utilities.h"

class VulkanRenderer
{
public:
	VulkanRenderer();
	~VulkanRenderer();

	int Init(GLFWwindow* newWindow);
	void Cleanup();

private:
	GLFWwindow* window;

	struct 
	{
		VkPhysicalDevice physicalDevice;
		VkDevice logicalDevice;
	} mainDevice;

	VkQueue graphicsQueue;

	// Vulkan Components
	VkInstance instance;

	// Vulkan Functions
	// - Create Functions
	void CreateInstance();
	void CreateLogicalDevice();

	// - Get Functions
	void GetPhysicalDevice();

	// - Support Functions
	// -- Checker Functions
	bool CheckInstanceExtensionSupport(std::vector<const char*>* checkExtensions);
	bool CheckDeviceSuitable(VkPhysicalDevice device);

	// -- Getter Functions
	QueueFamilyIndices GetQueueFamilies(VkPhysicalDevice device);
};

