The main branch was originally built using a custom MakeFile that probably only works on my local machine. Please clone the cmake branch for better compatibility.

# Forest Fire Model Visualization
A visualization of the [self-organized criticality forest fire model](https://en.wikipedia.org/wiki/Forest-fire_model) using SFML graphics in C++

Loud audio warning. I'm still working on better sounds in LMMS to replace the current sounds being used.

Before building, Linux users may need to install a few things according to [SFML's website](https://www.sfml-dev.org/tutorials/3.0/getting-started/cmake/#requirements)

Build the program by running:

cmake -B build

cmake --build build

You will find the executable file in the subfolder "build/bin/"

After you should get something like this (unless I changed the default number of units or colors later):
 
![ffm2](https://github.com/user-attachments/assets/511695b5-9957-4631-8775-87909edce27b)
