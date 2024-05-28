#!/bin/bash

array=(
    'sda' 
    'super cool' 
    'sdb' 
    'less cool'
    'sdc'
    'there is another ?'
)

function dialog_menu()
{

    arr["$1"]="$(dialog --clear \
            --backtitle "$2" \
            --title "$3" \
            --menu "$4" 10 60 3 \
            "${!5}" --output-fd 1)"

}

dialog_menu disk_selection "Menu" "Menu Test" "This is a test for Menu entry" array[@]
echo ${arr["disk_selection"]}