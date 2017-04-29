#!/bin/bash

echo Running program with inputs word.txt \(hahaa\) suffix\(\) hahaa
java -classpath src runner word.txt suffix\(\) haa
echo ##########################
echo Now Running program with inputs word.txt longestSubstring\(\) haha
java -classpath src runner word.txt longestSubstring\(\) haha
echo ##########################
echo Now Running program with inputs word.txt longestRepeat\(\) hehaa
java -classpath src runner word.txt longestRepeat\(\) hehaa
echo ##########################
echo Now changing word to banana and showing result
java -classpath src runner banana.txt show\(\)
