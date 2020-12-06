#include "Peak.h"


class ExampleLayer : public Peak::Layer
{
public:
	ExampleLayer() :Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f)
	{
		left = -1.6f;
		right = 1.6f;
		bottom = -0.9f;
		top = 0.9f;

		m_VertexArray.reset(Peak::VertexArray::Create());

		float vertices[3 * 7] = {
		   -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			0.0f,  0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f
		};

		std::shared_ptr<Peak::VertexBuffer> m_VertexBuffer;
		m_VertexBuffer.reset(Peak::VertexBuffer::Create(vertices, sizeof(vertices)));

		Peak::BufferLayout layout = {
				{ Peak::ShaderDataType::Float3, "a_Position"},
				{ Peak::ShaderDataType::Float4, "a_Color"}
		};

		m_VertexBuffer->SetLayout(layout);

		m_VertexArray->AddVertexBuffer(m_VertexBuffer);


		unsigned int indices[3] = { 0, 1, 2 };

		std::shared_ptr< Peak::IndexBuffer> m_IndexBuffer;
		m_IndexBuffer.reset(Peak::IndexBuffer::Create(indices, 3));


		m_VertexArray->SetIndexBuffer(m_IndexBuffer);


		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location=0) in vec3 a_Position;
			layout(location=1) in vec4 a_Color;
				
			uniform mat4 u_ViewProjection;

			out vec4 v_Color;
			void main()
			{
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position,1.0);
			}

		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location=0) out vec4 color;
			
			in vec4 v_Color;
			void main()
			{
				color = v_Color;
			}

		)";

		m_Shader.reset(new  Peak::Shader(vertexSrc, fragmentSrc));




		m_SquareVertexArray.reset(Peak::VertexArray::Create());


		float verticessq[3 * 4] = {
		   -0.75f, -0.75f, 0.0f,
			0.75f, -0.75f, 0.0f,
			0.75f,  0.75f, 0.0f,
		   -0.75f,  0.75f, 0.0f
		};



		std::shared_ptr< Peak::VertexBuffer> sqVB;
		sqVB.reset(Peak::VertexBuffer::Create(verticessq, sizeof(verticessq)));

		sqVB->SetLayout({
		{ Peak::ShaderDataType::Float3, "a_Position"}
			});

		m_SquareVertexArray->AddVertexBuffer(sqVB);

		unsigned int indices2[6] = { 0, 1, 2, 2, 3, 0 };

		std::shared_ptr< Peak::IndexBuffer> sqIB;
		sqIB.reset(Peak::IndexBuffer::Create(indices2, 6));
		m_SquareVertexArray->SetIndexBuffer(sqIB);



		std::string vertexSrc2 = R"(
			#version 330 core
			
			layout(location=0) in vec3 a_Position;
			
			uniform mat4 u_ViewProjection;
	
			out vec3 v_Position;
			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position,1.0);
			}

		)";

		std::string fragmentSrc2 = R"(
			#version 330 core
			
			layout(location=0) out vec4 color;
			
			in vec3 v_Position;
			void main()
			{
				color = vec4(0.2 , 0.3, 0.8, 1.0);
			}

		)";

		m_Shader2.reset(new Peak::Shader(vertexSrc2, fragmentSrc2));
	}

	void OnEvent(SDL_Event& event) override
	{
		RegisterEvent(event);
	}


	void OnUpdate(Peak::Timestep timestep) override
	{	

		if (isMousePressed(SDL_BUTTON_LEFT))
		{

		}
		else if (isEventType(SDL_MOUSEWHEEL)) {
			if (MouseWheelVertical > 0)
			{
				left -= 0.01f;
				right += 0.01f;
				bottom -= 0.01f;
				top += 0.01f;
				m_Camera.SetView(left, right, bottom, top);
			}
			else if (MouseWheelVertical < 0)
			{
				left += 0.01f;
				right -= 0.01f;
				bottom += 0.01f;
				top -= 0.01f;	
				m_Camera.SetView(left, right, bottom, top);
			}
		}
		else
		{
	
			if (isKeyPressed(KEY(W)))
			{
				position = m_Camera.GetPosition();
				position.y -= 1.0f * timestep;
			}
			else if (isKeyPressed(KEY(S)))
			{
				position = m_Camera.GetPosition();
				position.y += 1.0f * timestep;
			}
			if (isKeyPressed(KEY(A)))
			{
				position = m_Camera.GetPosition();
				position.x += 1.0f * timestep;
			}
			else if (isKeyPressed(KEY(D)))
			{
				position = m_Camera.GetPosition();
				position.x -= 1.0f* timestep;
			}
		}

		
		m_Camera.SetPosition(position);

		Peak::Renderer::SetClearColor(0.1f, 0.1f, 0.1f, 1);
		Peak::Renderer::Clear();

		Peak::Renderer::BeginScene(m_Camera);

		Peak::Renderer::Submit(m_Shader2, m_SquareVertexArray);

		Peak::Renderer::Submit(m_Shader, m_VertexArray);

		Peak::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Engine Data");
		ImGui::Text("Version 1.0v");
		ImGui::End();
	}
private:
	std::shared_ptr<Peak::Shader> m_Shader;
	std::shared_ptr<Peak::VertexArray> m_VertexArray;

	std::shared_ptr<Peak::Shader> m_Shader2;
	std::shared_ptr<Peak::VertexArray> m_SquareVertexArray;
	Peak::OrthographicCamera m_Camera;
	glm::vec3 position = {0.0f, 0.0f, 0.0f};
	float left = 0;
	float right = 0;
	float bottom = 0;
	float top = 0;
};

class Sandbox : public Peak::Application
{
public:
	Sandbox() : Application("Peak Engine", 1280,720)
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{
	
	}
};

Peak::Application* Peak::CreateApplication()
{
	return new Sandbox();
}