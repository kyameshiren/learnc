#!/bin/bash

FILES=("$HOME/.bashrc" "$HOME/.tmux.conf" "$HOME/.vimrc")

BACKUP_DIR="$HOME/bak"
if [ ! -d "$BACKUP_DIR" ]; then
	mkdir -p "$BACKUP_DIR"
fi


for FILE in "${FILES[@]}"; do
	BASE="$(basename "$FILE")"
	NEW="./$BASE"

	if [ -f "$FILE" ]; then
		
		BACKUP="$FILE.bak"
		
		if [ -f "$BACKUP" ]; then
			TIMESTAMP=$(date +"%Y%m%d%H")
			BACKUP="$FILE.bak.$TIMESTAMP"
		fi

		BACKUP_PATH="$BACKUP_DIR"/"$(basename "$BACKUP")"
		mv "$FILE" "$BACKUP_PATH"
		
		echo "Backup created for $FILE at: $BACKUP_PATH"
	else
		echo "File $FILE not found!"
	fi
	
	if [ -f "$NEW" ]; then
		cp "$NEW" "$FILE"
		echo "New file $NEW added to $HOME"
	fi


done
