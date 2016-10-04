@echo off
set rc=1
set arduino_runtime=!arduino_path!\hardware\cores\arduino
set path=%path%;!arduino_path!\hardware\tools\avr\bin
set path=!arduino_path!;!arduino_path!\tools\avr\bin;!path!
set rc=0