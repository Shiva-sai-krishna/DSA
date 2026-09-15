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


# Commands for Set up for Github on Linux : 
# Star by installing GIT and Configuring it with your creds :

sudo apt update
sudo apt upgrade
sudo apt install git

git config --global user.name "Shiva-sai-krishna"
git config --global user.email "shivakrishnaanand@gmail.com"


# Create the Key, Then press enter and display the key 

ssh-keygen -t ed25519 -C "shivakrishnaanand@gmail.com"
<ENTER>
cat ~/.ssh/id_ed25519.pub


# copy and paste the entire line (along with the mail id) in the Profile → Settings → SSH and GPG keys → New SSH key and give it a name like ubuntu

# Login using the terminal SSH 
ssh -T git@github.com


# download the official deb file from the vs code page : https://code.visualstudio.com/download?utm_source=chatgpt.com

sudo apt install ./<the file name here >.deb

# create a new folder locally in home where you want to store the copy of repo
git clone git@github.com:Shiva-sai-krishna/DSA.git
code .










