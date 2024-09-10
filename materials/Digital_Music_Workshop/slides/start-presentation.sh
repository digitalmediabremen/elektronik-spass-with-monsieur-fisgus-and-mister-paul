#! /bin/bash

BASEDIR=$(cd "$(dirname "$0")"; pwd)
PRESENTATION="$1"
CSS_FILE="$2"
PORT="$3"

echo "$1"
echo "$2"
echo "$BASEDIR"

cd "$BASEDIR"

PORT=$PORT marp --server --html --watch --theme $CSS_FILE $PRESENTATION & PROCESS_ID=$!
sleep 2.0
open http://localhost:$PORT/
read -r
kill $PROCESS_ID
