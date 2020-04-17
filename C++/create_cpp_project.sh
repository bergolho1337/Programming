# ============================================================================
# Author: Lucas Berg
# Script to create a simple C++ program template
# ============================================================================
#!/bin/bash

write_cpp_program_template () {
cat << EOF >> "$1/main.cpp"
int main (int argc, char *argv[])
{
	// Put your code here
	return 0;
}
EOF
}

write_cmakelists () {
cat << EOF >> "$1/CMakeLists.txt"
cmake_minimum_required(VERSION 2.8)

PROJECT(main)

SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY "\${CMAKE_CURRENT_SOURCE_DIR}/bin" )

ADD_EXECUTABLE(main MACOSX_BUNDLE main.cpp)

TARGET_LINK_LIBRARIES(main m)
EOF
}

write_recompile_script () {
cat << EOF >> "$1/recompile_project.sh"
BUILD_DIR="build"
BUILD_TYPE="Release"

if [[ ! -d "\$BUILD_DIR" ]]; then
  echo "Directory \"\$BUILD_DIR\" does not exist. Creating."
  mkdir "\$BUILD_DIR"
fi

cd "\${BUILD_DIR}"; cmake -DCMAKE_BUILD_TYPE="\${BUILD_TYPE}" ..; make
EOF

chmod +x "$1/recompile_project.sh"
}

write_clean_script () {
cat << EOF >> "$1/clean_project.sh"
#!/bin/bash
rm -r build/*
rm -r bin/*
EOF

chmod +x "$1/clean_project.sh"
}


create_directory () {
	# If the folder does not exist we will create
	if [ ! -d $1 ]; then
		echo "[!] Creating folder '$1' !"
		mkdir $1
	fi
}

# MAIN PROGRAM
if [ "$#" -ne 1 ]; then
	echo "--------------------------------------------------------------"
	echo "Usage:> ./create_cpp_project.sh <project_folder>"
	echo "--------------------------------------------------------------"
	echo "Example: ./create_cpp_project.sh Main"
	echo "         ./create_cpp_project.sh HelloWorld"
	echo "--------------------------------------------------------------"
	exit 1
fi

create_directory $1
write_cpp_program_template $1
write_cmakelists $1
write_recompile_script $1
write_clean_script $1
