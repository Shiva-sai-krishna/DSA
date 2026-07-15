# Commands to SetUp C++ VS and Git on Windows : 
# To Install Git on Windows ONLY
winget install --id Git.Git -e --source winget

# Setup Configurations
git --version
git config --global user.name "Shiva-sai-krishna"
git config --global user.email "shivakrishnaanand@gmail.com"


# GCC Compiler for C++ on Windows 
Go to [mysys2](https://www.msys2.org/) and run the installer
In the MSYS2 UCRT64 Terminal enter the command : pacman -Syu
Install the C++ Compiler : pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-gdb mingw-w64-ucrt-x86_64-make

# Environment Variables 
Go to the env variables by pressing env in the windows search
Click on Environment Variables in the Bottom Left 
Under User Variables Click on Path and Click on Edit 
Click New and paste the path : C:\msys64\ucrt64\bin
Click on OK on all three windows to save your changes

# VS Code 
Go to microsoft store and install VS Code 
Go to extensions and install C/C++ (Microsoft)

# GITHUB 
Login to Github 
Create a new Repo called DSA
Copy the URL of the Repo 
Go to Git hub branch icon in the left panel 
Clone your repository from github by entering the url
Go to the branch icon again and trust the authors to allow commits


# C++ 
Create a .cpp file and enter your code 
compile it using gcc : g++ test.cpp -o test 
and run it using : .\test.exe
Commit using the branch icon (this stages all the changes)










