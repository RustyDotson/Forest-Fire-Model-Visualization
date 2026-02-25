The main branch is currently being built using a custom MakeFile that works on my local machine. Please clone the cmake branch for better compatibility.

# Forest Fire Model Visualization
A visualization of the [self-organized criticality forest fire model](https://en.wikipedia.org/wiki/Forest-fire_model) using SFML graphics in C++

The project was originally built using MacOS without using cmake, instead through making a custom MakeFile. Getting the main branch to work currenly on Windows or Linux will be annoying. AI is good for learning but often walks you through really bad ways of doing things :/. You can see how the cmake files were made by reading [this page](https://www.sfml-dev.org/tutorials/3.0/getting-started/cmake/#requirements) on SFML's website. Linux users may need to install a few extra things according to the page.

building the program by running:

cmake -B build
cmake --build build

should get you something like this (unless I changed the default number of units or colors later):
 
![ffm2](https://github.com/user-attachments/assets/511695b5-9957-4631-8775-87909edce27b)
