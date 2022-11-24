echo ".bashrc"

id -u
id -g

export PS1="\u@\h:\w> "
export DISPLAY=:0

export VOL_ROOT=/mnt/host
cd $VOL_ROOT

# ... placez ici vos autres variables pratiques ...

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
qmake6 --version
echo "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"
echo ""

echo ".bashrc"

