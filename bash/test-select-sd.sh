#!/usr/bin/env bash

set -au -o pipefail

SD_ITEMS=$(lsblk --noheadings --ascii --paths --pairs --output NAME,TYPE,LABEL,SIZE,MOUNTPOINT --include '8,65,66' | grep -E 'TYPE="part"|TYPE="loop"')

echo "->${SD_ITEMS}<-"

if [ "${SD_ITEMS}" == "" ] ; then
    dialog --clear \
            --backtitle "xxxx" \
            --title "Error" \
            --msgbox "\n\nThere is no attached storage device !\nAborting." 15 60
    exit
fi

IFS=$'\n' read -d '' -r -a MENU_SD_ITEMS < <(printf '%s\n' "${SD_ITEMS}" | cut -d ' ' -f '1,3-')

echo "->${MENU_SD_ITEMS}<-"

SELECTED_SD=$(dialog --backtitle "xxxx" \
                     --no-items \
                     --title "Please select zzzz" \
                     --menu "\n\nbla bla" 90 90 25 "${MENU_SD_ITEMS[@]}" \
                     --output-fd 1)
echo "->${SELECTED_SD}<-"

set ${SELECTED_SD}
for f in "$@"; do
    IFS='=' read -r key val <<< "$f"
    test -n "$val" && printf -v "$key" "$val"
done

echo "Result : ->${NAME}<- ->${MOUNTPOINT}<-"
if [ "${MOUNTPOINT}" == '""' ] ; then
    MOUNTPOINT=/mnt
    echo "Mounting ${NAME} into ${MOUNTPOINT}"
    echo "..."
    echo "Unmounting ${NAME}"
fi