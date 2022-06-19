# SDL2_Boilerplate with state-machine system
### by [Mattéo Leclercq](https://github.com/MatteoL-W/)

![alt text](demo.png)

This boilerplate contains SDL2, SDL2_image, SDL2_TTF, SDL2_Mixer, GLM

## Installation
### Linux
- Install CMAKE
- Install lib ```sudo apt install git build-essential pkg-config cmake cmake-data libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev```
- Install the repository as a template and install **the submodule** : ```git submodule update --init --recursive```
- At the repo root, execute ```cmake --build "build"```
- You can execute the window in ```./bin/```

### Windows
- Install CMAKE
- Install a G++ compiler (this setup is made for MinGW)
- If you're not on MinGW, install SDL2 on your compiler
- Use the repository as a template
- At the repo root, execute ```cmake --build build```
- You can execute the window in ```./bin/```

For Windows, if you have the following build error: ```cannot find -SDL2_mixer``` in example, I advise you to move the content of the following library into your libraries MINGW folder. In my case, I needed to add ``` Thomas_Was_Alone\lib\SDL2_mixer-2.0.4\x86_64-w64-mingw32\lib ``` content into ```C:\MinGW\lib```. Same for the ```bin/``` folder. I don't know how to fix this one, sorry.

The CMake should be working with **MinGW builder** and **Linux** !

# Don't forget to remove this and write your own README.md 😄
