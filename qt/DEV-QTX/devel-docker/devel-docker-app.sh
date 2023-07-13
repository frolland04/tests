#!/bin/bash

echo "**** BIENVENUE! ****"


echo "On est dans le conteneur Docker de développement Qt :"
echo "exécution de $0"
echo "-----------------------------------------------------"
echo ""

# Dossier de départ
cd /mnt

# Pour debug sans histoire
PTRACE=/proc/sys/kernel/yama/ptrace_scope
if [ -f "$PTRACE" ]; then
    echo 0 > $PTRACE
fi

# ... placez ici vos autres variables et commandes pratiques (SU) ...

# Shell interactif
DEVEL_USER="devel"
if id $DEVEL_USER >/dev/null 2>&1 ; then
    echo $DEVEL_USER
    su -P -c bash $DEVEL_USER
else
    echo "..."
    bash
fi

echo "**** A BIENTOT. ****"

# ... placez ici vos autres variables et commandes pratiques (SU) ...

