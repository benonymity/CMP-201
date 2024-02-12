# Only run this at the start of each class!
now="$(date +'%m-%d-%y')"
mkdir $now
cp templates/hello.cpp $now/$now.cpp
cp templates/notes.md $now/