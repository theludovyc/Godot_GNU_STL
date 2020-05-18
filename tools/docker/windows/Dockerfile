FROM godot/build_base:latest

RUN apt-get update && apt-get install -y mingw-w64 
RUN update-alternatives --set x86_64-w64-mingw32-g++ /usr/bin/x86_64-w64-mingw32-g++-posix &&\
update-alternatives --set x86_64-w64-mingw32-gcc /usr/bin/x86_64-w64-mingw32-gcc-posix

COPY ./windows.cmake /windows.cmake

CMD cmake -Bbuild/windows -DCMAKE_BUILD_TYPE=${build} -DCMAKE_TOOLCHAIN_FILE=/windows.cmake -H. && cmake --build build/windows -- -j`nproc`