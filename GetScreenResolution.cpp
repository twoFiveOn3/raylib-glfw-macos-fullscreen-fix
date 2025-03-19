// I was making a 3D game for a school project and ran into an issue with the raylib library(using openGL and GLFW) where proper fullscreen resolution could not be set with my Mac computer.
// In windowed form, everything works perfectly, however when using ToggleFullscreen() on a Mac, the picture will cover the whole screen, but will be off center.  
// I couldn't find much about it online so as a quick fix I wrote a function which uses a bash script to retrieve the screen resolution.  Once these values are retrieved,
// the InitWindow() heigh and width can be set manually, and ToggleFullScreen() show a centered picture.
//
// The caveat is that using these values directly as your window width/height locks you into the resolution of your screen, ie not good for 8 bit style games.  However, my guess is that
// you can scale the retrieved values, preserving the aspect ratio and therefore still getting a centered picture

// Library used was RayLib by raysan5 (https://github.com/raysan5/raylib).  Absolutely love it and would recommend to anyone


std::pair<int, int> GetScreenResolution() {
    int width;
    int height;
    std::string junk;
    char buffer[256];
    std::string trimmedInput;
    char cmd[] = "system_profiler SPDisplaysDataType | grep Resolution";  //bash-zsh shell command
    FILE* pipe = popen(cmd, "r");

    if (!pipe) {
        TraceLog(LOG_WARNING, "Unable to find display resolution, may result in unexpected behavior");
        return std::pair{1920, 1080};
    }
    while (fgets(buffer, sizeof(buffer), pipe)) {
        trimmedInput += buffer;
    }
    pclose(pipe);
    trimmedInput.erase(0, trimmedInput.find_first_not_of(" \t"));
    std::size_t pos = trimmedInput.find("Resolution:");
    if (pos != std::string::npos) {
        trimmedInput = trimmedInput.substr(pos + 11); // Move past "Resolution: "
    }
    std::stringstream ss(trimmedInput);
    char x; // For the 'x' separator
    ss >> width >> x >> height;

    return {width, height};
}
