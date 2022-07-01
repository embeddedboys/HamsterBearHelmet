# HamsterBearHelmet
HamsterBearHelmet is a desktop application for hamsterbear which based on LVGL
It designed to run on target system, also makeing a way to run on host system.

# Project structre
```shell
input   --- the input methods
lvgl    --- the LVGL offical git repo
native  --- files used to run on native system
port    --- files used to port to target system
ui      --- files about lvgl app
```

# How it works?

* Run on a target system

the display implenments by fbdev, and input implenments by joystick and button etc

* Run on native system

the display implenments by SDL2, and input so on

# How to build?
To build for target system, look this
```shell
mkdir build && cd build
cmake ..
make -j12
```
and the target executable file `demo` on current dir

TODO: To build for host system, look this
```shell
```
