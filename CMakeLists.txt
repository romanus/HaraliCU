cmake_minimum_required (VERSION 3.8 FATAL_ERROR)
project (HaralickCU CXX CUDA)

set(OpenCV_STATIC ON)
find_package(OpenCV REQUIRED PATHS "${CMAKE_SOURCE_DIR}/3rd_party/opencv" NO_DEFAULT_PATH)
if(OpenCV_FOUND)
    message(STATUS "OPENCV FOUND")
endif()

add_executable (GPUDemo
    GPU/src/getopt.cpp
    GPU/src/AggregatedGrayPair.cu
    GPU/src/Direction.cu
    GPU/src/Features.cu
    GPU/src/GrayPair.cu
    GPU/src/ImageLoader.cpp
    GPU/src/WindowFeatureComputer.cu
    GPU/src/ImageFeatureComputer.cu
    GPU/src/Utils.cpp
    GPU/src/CudaFunctions.cu
    GPU/src/FeatureComputer.cu
    GPU/src/ProgramArguments.cpp
    GPU/src/GLCM.cu
    GPU/src/Image.cu
    GPU/src/ImageData.cu
    GPU/src/Window.cu
    GPU/src/WorkArea.cu
    GPU/src/main.cpp
)

target_include_directories (GPUDemo PUBLIC GPU/src)

set_target_properties(GPUDemo PROPERTIES CXX_STANDARD 17)
set(CMAKE_CONFIGURATION_TYPES "Release;" CACHE STRING "" FORCE)

set(CMAKE_CUDA_FLAGS "-Xptxas -O3 -use_fast_math -arch=compute_75 -code=compute_75")
set_target_properties(GPUDemo PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
set_property(TARGET GPUDemo PROPERTY BUILD_RPATH ${CMAKE_CUDA_IMPLICIT_LINK_DIRECTORIES})

target_link_libraries (GPUDemo
    PRIVATE
    ${OpenCV_LIBS}
    cudadevrt)