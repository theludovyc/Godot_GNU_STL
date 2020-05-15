FROM godot/build_base:latest

RUN apt-get update && apt-get install -y libx11-dev libxcursor-dev libxinerama-dev libglu-dev libasound2-dev libpulse-dev libudev-dev libxi-dev libxrandr-dev

CMD cmake -Bbuild/linux -DCMAKE_BUILD_TYPE=${build} -H. && cmake --build build/linux -- -j`nproc`