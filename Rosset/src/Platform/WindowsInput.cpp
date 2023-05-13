#include "Rosset/Config/RsConfig.h"

#include "Platform/WindowsInput.h"

#include "Rosset/Application/Application.h"

#include <GLFW/glfw3.h>

namespace Rosset {
    Input* Input::s_Instance = new WindowsInput();

    bool WindowsInput::IsKeyPressedImpl(int keyCode)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keyCode);

        return (state == GLFW_PRESS || state == GLFW_REPEAT);
    }

    bool WindowsInput::IsMouseButtonPressedImpl(int button)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, button);

        return (state == GLFW_PRESS);
    }

    std::pair<float, float> WindowsInput::GetMousePosition()
    {
        double xPos = 0;
        double yPos = 0;
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());

        glfwGetCursorPos(window, &xPos, &yPos);

        return { static_cast<float>(xPos), static_cast<float>(yPos) };
    }

    float WindowsInput::GetMouseXImpl()
    {
        auto [xPos, yPos] = GetMousePosition();
        return xPos;
    }

    float WindowsInput::GetMouseYImpl()
    {
        auto [xPos, yPos] = GetMousePosition();
        return yPos;
    }
}
