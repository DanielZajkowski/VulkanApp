#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <vector>
#include <set>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <array>

#include "VulkanValidation.h"
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

	// Vulkan Components
	// - Main
	VkInstance instance;
	VkDebugUtilsMessengerEXT debugMessenger;
	struct 
	{
		VkPhysicalDevice physicalDevice;
		VkDevice logicalDevice;
	} mainDevice;
	VkQueue graphicsQueue;
	VkQueue presentationQueue;
	VkSurfaceKHR surface;
	VkSwapchainKHR swapchain;

	std::vector<SwapchainImage> swapchainImages;
	std::vector<VkFramebuffer> swapchainFramebuffers;
	std::vector<VkCommandBuffer> commandBuffers;

	// - Pipeline
	VkPipeline graphicsPipeline;
	VkPipelineLayout pipelineLayout;
	VkRenderPass renderPass;

	// - Pool
	VkCommandPool graphicsCommandPool;

	// - Utility
	VkFormat swapchainImageFormat;
	VkExtent2D swapchainExtent;

	// Vulkan Functions
	// - Create Functions
	void CreateInstance();
	void CreateDebugMessenger();
	void CreateLogicalDevice();
	void CreateSurface();
	void CreateSwapchain();
	void CreateRenderPass();
	void CreateGraphicsPipeline();
	void CreateFramebuffers();
	void CreateCommandPool();
	void CreateCommandBuffers();

	// - Record Functions
	void RecordCommands();

	// - Debug Functions
	VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);
	void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);

	// - Get Functions
	void GetPhysicalDevice();
	std::vector<const char*> GetRequiredExtensions();

	// - Support Functions
	// -- Checker Functions
	bool CheckInstanceExtensionSupport(std::vector<const char*>* checkExtensions);
	bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
	bool CheckDeviceSuitable(VkPhysicalDevice device);
	bool CheckValidationLayerSupport();

	// -- Getter Functions
	QueueFamilyIndices GetQueueFamilies(VkPhysicalDevice device);
	SwapchainDetails GetSwapchainDetails(VkPhysicalDevice device);

	// -- Choose Functions
	VkSurfaceFormatKHR ChooseBestSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& formats);
	VkPresentModeKHR ChooseBestPresentationMode(const std::vector<VkPresentModeKHR> presentationModes);
	VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& surfaceCapabilities);

	// -- Create Functions
	VkImageView CreateImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags);
	VkShaderModule CreateShaderModule(const std::vector<char>& code);
};

