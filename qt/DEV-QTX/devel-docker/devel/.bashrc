echo ".bashrc"

id -u
id -g

export PS1="\u@\h:\w> "
export DISPLAY=:0
export PATH=~/.local/bin:$PATH
export VOL_ROOT=/mnt/host
cd $VOL_ROOT

# ... placez ici vos autres variables pratiques ...
export PATH=/opt/Qt:/opt/Qt/Tools/CMake/bin:/opt/Qt/Tools/QtCreator/bin:/opt/Qt/6.4.2/gcc_64/bin:$PATH

if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
    # ^^^ ... où la dedans ...
fi

echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"
alias ll='ls -al'
alias
echo ""
env | grep -E "^HOME=|^PWD=|^PATH=|^HOSTNAME=|^DISPLAY=|^LD_LIBRARY_PATH=|^VOL_"
echo ""
/opt/Qt/5.15.2/gcc_64/bin/qmake --version
/opt/Qt/6.4.2/gcc_64/bin/qmake6 --version
cmake --version | grep version
conan --version
echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
echo ""

echo ".bashrc"

