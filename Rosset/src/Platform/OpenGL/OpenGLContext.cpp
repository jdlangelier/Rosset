#include "Rosset/Config/RsConfig.h"

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "Platform/OpenGL/OpenGLContext.h"

namespace Rosset {

    Rosset::OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
        : m_WindowHandle(windowHandle)
    {
        RS_ENGINE_ASSERT(m_WindowHandle, "Window handle is NULL!");
    }

    void Rosset::OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        int nRes = gladLoadGL(glfwGetProcAddress);
        RS_ENGINE_ASSERT(nRes, "Could not initialize glad!");
    }

    void Rosset::OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }
}
