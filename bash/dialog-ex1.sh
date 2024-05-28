#!/bin/bash

# ----------------------------------------------------
# pcp.sh: A shell script to copy files from /etc, and
#         displays a progress bar while copying files.  
# ----------------------------------------------------

# Create an array of all files in /etc directory
DIRS=(/etc/*)

# Destination directory
DEST="/tmp/test.$$"

# Create ${DEST} if does not exits
[ ! -d ${DEST} ] && mkdir -p ${DEST}

# -------------------
# Show a progress bar
# -------------------

# Redirect dialog commands input using substitution
dialog --title "Copy file" --gauge "Copying file ..." 10 75 < <(
   # Get total number of files in array
   n=${#DIRS[*]}; 

   # set counter - it will increase every-time a file is copied to ${DEST}
   i=0

   # ------------------
   # Start the for loop 
   # ------------------

   # read each file from ${DIRS} array 
   # using ${FILE} as current filename 
   for FILE in "${DIRS[@]}"
   do
      # calculate progress
      PCT=$(( 100*(++i)/n ))

      # update dialog box
      # both 'XXX' are specific delimiters for dialog gauge prompt changing message
cat <<EOF
XXX
Copying file "${FILE}" (${i} of ${n}) ...
Please wait, this may take a long time
XXX
${PCT}
EOF
  # copy file ${FILE} to ${DEST} 
   /bin/cp "${FILE}" "${DEST}" &>/dev/null
   done
)

# just delete ${DEST} directory
/bin/rm -rf "${DEST}"