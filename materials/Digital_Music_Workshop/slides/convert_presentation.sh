#! /bin/bash

BASEDIR=$(cd "$(dirname "$0")"; pwd)
PRESENTATION="$1"
CSS_FILE="$2"

echo "$1"
echo "$2"
echo "$BASEDIR"

cd "$BASEDIR"

marp --pdf --html --theme $CSS_FILE --output "$PRESENTATION.pdf" --allow-local-files $PRESENTATION
marp --html --theme $CSS_FILE $PRESENTATION
