#include <imgui.h>

class App{
    public:
    App(ImGuiIO& in_io);
    ~App();
    void run_app();

    // Our state
    public:
        bool show_demo_window = true;
        bool show_another_window = false;
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    private:
        ImGuiIO& io;
};