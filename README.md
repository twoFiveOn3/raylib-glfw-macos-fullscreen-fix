# raylib-glfw-macos-fullscreen-fix
simple c++ function to retrieve device dimensions on mac computers

I was making a 3D game for a school project and ran into an issue with the raylib library(using openGL and GLFW) where proper fullscreen resolution could not be set with my Mac computer.  In windowed form, everything works perfectly, however when using ToggleFullscreen() on a Mac, the picture will cover the whole screen, but will be off center.  I couldn't find much about it online so as a quick fix I wrote a function which uses a bash script to retrieve the screen resolution.  Once these values are retrieved the screen resolution can be set manually and FullScreen can be toggled without it being off center
