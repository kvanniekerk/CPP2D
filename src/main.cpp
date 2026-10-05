#include <iostream>
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>


int main()
{

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 450, "window name");


#pragma region imgui
	rlImGuiSetup(true);


	ImGuiIO& io = ImGui::GetIO();
	//.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
	//.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.FontGlobalScale = 2; // Scale the font size for easier reading

#pragma endregion


	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

#pragma region imgui
		// Docking ImGui window to the main viewport
		rlImGuiBegin();

		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		ImGui::PopStyleColor(2);
#pragma endregion

		DrawRectangle(50, 50, 100, 100, { 255, 0, 0, 127 });
		DrawRectangle(75, 75, 100, 100, { 0, 255, 0, 127 });

		DrawText("Hello, World!", 190, 200, 20, RED);

		// Create a simple ImGui window
#pragma region imgui windows
		ImGui::Begin("first window");

		ImGui::Text("Hello, World!");
		ImGui::Button("Click me!");

		if (ImGui::Button("button")) // Text after ## is not displayed, but is used to uniquely identify the button
		{
			std::cout << "First button!\n";
		}
		ImGui::SameLine();

		ImGui::PushID(2);
		if (ImGui::Button("button##2"))
		{
			std::cout << "Second button!\n";
		}
		ImGui::PopID();
		ImGui::SameLine();

		if (ImGui::Button("button##3"))
		{
			std::cout << "Third button!\n";
		}
		//ImGui::ShowDemoWindow();

		ImGui::End();

		ImGui::Begin("Second Window");

		ImGui::Text("second window");
		ImGui::Separator();
		ImGui::NewLine();
		static float a = 0;
		ImGui::SliderFloat("slider", &a, 0, 1);
		if (ImGui::Button("button")) // Widgets on different windows can have the same name
		{
			std::cout << "Window 2!\n";
		}

		ImGui::End();
#pragma endregion


#pragma region imgui
		rlImGuiEnd();
#pragma endregion

		EndDrawing();
	}
#pragma region imgui
	rlImGuiShutdown();
#pragma endregion

	CloseWindow();

	return 0;
}