call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"

pushd lib\aff3ct
mkdir build
cd build
cmake .. -G "Visual Studio 15 2017" -A x64 -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="-funroll-loops -march=native -fvisibility=hidden -fvisibility-inlines-hidden -faligned-new" -DAFF3CT_COMPILE_EXE="OFF" -DAFF3CT_COMPILE_STATIC_LIB="ON" -DAFF3CT_COMPILE_SHARED_LIB="ON" -DCMAKE_CXX_FLAGS="-D_CRT_SECURE_NO_DEPRECATE /EHsc /MP4 /bigobj"
devenv /build Debug aff3ct.sln

cd ..\doc
mkdir build
cd source
"C:\Program Files\doxygen\bin\doxygen.exe" Doxyfile
popd

mkdir cmake
mkdir cmake\Modules
copy lib\aff3ct\build\lib\cmake\aff3ct-3.0.2\* cmake\Modules

mkdir build
cd build
python ..\configure.py --verbose
cmake .. -G "Visual Studio 15 2017" -A x64 -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="-funroll-loops -march=native -fvisibility=hidden -fvisibility-inlines-hidden -faligned-new" -DCMAKE_CXX_FLAGS="-D_CRT_SECURE_NO_DEPRECATE /EHsc /MP4 /bigobj"
devenv /build Debug py_aff3ct_test.sln