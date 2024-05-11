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

        RS_ENGINE_INFO("OpenGL Renderer:");
        RS_ENGINE_INFO("  Vendor:   {0}", (const char*)glGetString(GL_VENDOR));
        RS_ENGINE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
        RS_ENGINE_INFO("  Version:  {0}", (const char*)glGetString(GL_VERSION));
    }

    void Rosset::OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }
}
