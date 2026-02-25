The main branch was originally built using a custom MakeFile that probably only works on my local machine. Please clone the cmake branch for better compatibility.

# Forest Fire Model Visualization
A visualization of the [self-organized criticality forest fire model](https://en.wikipedia.org/wiki/Forest-fire_model) using SFML graphics in C++

Before building, Linux users may need to install a few things according to [SFML's website](https://www.sfml-dev.org/tutorials/3.0/getting-started/cmake/#requirements)

Build the program by running:

cmake -B build

cmake --build build

After you should get something like this (unless I changed the default number of units or colors later):
 
![ffm2](https://github.com/user-attachments/assets/511695b5-9957-4631-8775-87909edce27b)
